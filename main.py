import glob
import os
import functools
import multiprocessing as mp
import networkx as nx
from itertools import combinations
from tqdm import tqdm

from PlagiarismDB import PlagiarismDB, Submission

# PLATFORM = "Codeforces"
# LOGPATH = "test_log.txt"
# ARCHIVEPATH = "-1"

PLATFORM = "Codeforces"
LOGPATH = "log.txt"
ARCHIVEPATH = "602776"

# PLATFORM = "Yandex"
# LOGPATH = "log-911-1.xml"
# ARCHIVEPATH = "submits-911-1"

# PLATFORM = "Yandex"
# LOGPATH = "log-911-2.xml"
# ARCHIVEPATH = "submits-911-2"

GRAPHSDIR=ARCHIVEPATH + "_OK_JOERN/graphs"

SUBGRAPH_SIZE = 4
SEARCH = 'ABCDEFGHIJK'


def extend_subgraph(G, k, V_sub, V_ext, v, results, seen):
    if len(V_sub) == k:
        # results.append(V_sub.copy())
        sub_frozen = frozenset(V_sub)
        if sub_frozen not in seen:
            seen.add(sub_frozen)
            results.append(G.subgraph(V_sub))
        return
    while V_ext:
        w = V_ext.pop()
        new_sub = V_sub | {w}
        neighbors = set(G.predecessors(w)) | set(G.successors(w))
        neighbors_w = {u for u in neighbors if u not in V_sub and u > v}
        new_ext = V_ext | neighbors_w
        extend_subgraph(G, k, new_sub, new_ext, v, results, seen)


def prepare_nodes(graph):
    nodes_to_remove = []
    for node in graph.nodes():
        name = graph.nodes[node].get('NAME', None)
        if name is None:
            nodes_to_remove.append(node)
    graph.remove_nodes_from(nodes_to_remove)
    components_to_remove = []
    weak_components = tuple(nx.weakly_connected_components(graph))
    for component in weak_components:
        if len(component) < SUBGRAPH_SIZE:
            components_to_remove.extend(component)
    graph.remove_nodes_from(components_to_remove)


# @functools.lru_cache(maxsize=None)
def get_all_weakly_connected_subgraphs(G_path):
    G = nx.drawing.nx_agraph.read_dot(G_path)
    prepare_nodes(G)
    subgraphs = []
    seen = set()
    for v in G.nodes:
    # for v in tqdm(G.nodes(),
    #               desc=f"Getting subgraphs of {G_path}", position=pid % mp.cpu_count(), leave=False, ascii=True, colour='yellow'):
        neighbors = set(G.predecessors(v)) | set(G.successors(v))
        V_extension = {u for u in neighbors if u > v}
        extend_subgraph(G, SUBGRAPH_SIZE, {v}, V_extension, v, subgraphs, seen)
    return subgraphs


def plagiarism(G1_path, G1, G2):
    G1_nodes_iso = {node: False for node in G1.nodes()}
    G1_all_subgraphs = get_all_weakly_connected_subgraphs(G1_path)

    # pid = os.getpid()
    for subgraph in G1_all_subgraphs:
    # for subgraph in tqdm(G1_all_subgraphs,
    #                      desc=f"{pid}: {G1_path}", leave=False, position=os.getpid() % mp.cpu_count(), ascii=True):
        if all(G1_nodes_iso[node] for node in subgraph.nodes()):
            continue  # Пропускаем проверку изоморфизма
        is_isomorhic = nx.algorithms.isomorphism.DiGraphMatcher(
            G2, subgraph, node_match=lambda n1, n2: n1['NAME'] == n2['NAME']).subgraph_is_isomorphic()
        # iso = vf3py.has_subgraph(subgraph, G2, node_match=lambda n1, n2: n1['NAME'] == n2['NAME'], variant='P', num_threads=8)
        # iso = grandiso.find_motifs(subgraph, G2, is_node_attr_match=lambda p_id, t_id, p_g, t_g: (p_g.nodes[p_id].get('NAME') == t_g.nodes[t_id].get('NAME')))
        if is_isomorhic:
            for node in subgraph.nodes():
                G1_nodes_iso[node] = True
    return sum(G1_nodes_iso.values())/len(G1_nodes_iso)


def get_graph_code(db, submission: Submission, G_Path):
    cursor = db.conn.cursor()
    cursor.execute("""
            SELECT graph FROM submissions WHERE submission_id = ?
            """, (submission.id,))
    result = cursor.fetchone()
    if result is None or result[0] is None:
        with open(G_Path, 'r', encoding='utf-8') as f:
            code = f.read()
        cursor.execute("""
                    UPDATE submissions 
                    SET graph = ? 
                    WHERE submission_id = ?
                """, (code, submission.id))
        db.conn.commit()
        return code
    return result[0]


def process_combination(args):
    G1_sub, G2_sub, SUBGRAPH_SIZE, GRAPHSDIR = args
    db = PlagiarismDB('plagiarism.db')
    db.connect_db()

    try:
        G1_pattern = f"*{G1_sub.submission_code}*.dot"
        G2_pattern = f"*{G2_sub.submission_code}*.dot"
        
        G1_files = glob.glob(f"./{GRAPHSDIR}/{G1_pattern}")
        G2_files = glob.glob(f"./{GRAPHSDIR}/{G2_pattern}")
        
        if not G1_files:
            # print(f"Файл с кодом {G1_sub.submission_code} не найден")
            return None
        
        if not G2_files:
            # print(f"Файл с кодом {G2_sub.submission_code} не найден")
            return None
        
        # Берём первый найденный файл (если их несколько)
        G1_dotpath = G1_files[0]
        G2_dotpath = G2_files[0]
        
        get_graph_code(db, G1_sub, G1_dotpath)
        get_graph_code(db, G2_sub, G2_dotpath)
        
        G1 = nx.drawing.nx_agraph.read_dot(G1_dotpath)
        G2 = nx.drawing.nx_agraph.read_dot(G2_dotpath)

        prepare_nodes(G1)
        if G1.number_of_nodes() == 0:
            return (G1_sub, G2_sub, 0, 0, 0, G1_dotpath)
        prepare_nodes(G2)
        if G2.number_of_nodes() == 0:
            return (G1_sub, G2_sub, 0, 0, 0, G2_dotpath)

        res1 = plagiarism(G1_dotpath, G1, G2)
        res2 = plagiarism(G2_dotpath, G2, G1)

        db.save_result(G1_sub.id, G2_sub.id, SUBGRAPH_SIZE, res1)
        db.save_result(G2_sub.id, G1_sub.id, SUBGRAPH_SIZE, res2)

        mn = min(res1, res2)
        return (G1_sub, G2_sub, res1, res2, mn, None)

    finally:
        db.close_db()


if __name__ == '__main__':
    db = PlagiarismDB('plagiarism.db')
    if PLATFORM == "Yandex":
        contest_id = db.yandex_parse(LOGPATH, ARCHIVEPATH)
    if PLATFORM == "Codeforces":
        contest_id = db.codeforces_parse(LOGPATH, ARCHIVEPATH)
    problems = db.get_problems_by_contest(contest_id)

    results = []
    errors = set()

    for problem in problems:
        if problem.code not in SEARCH:
            continue
        submissions = [sub for sub in db.get_submissions_by_problem(problem.id) if sub.verdict == 'OK' and sub.language not in ('.txt', '.pas')]
        combinations_list = list(combinations(submissions, 2))
        for G1_sub, G2_sub in combinations_list.copy():
            if (G1_sub.team_code == G2_sub.team_code or
            not glob.glob(f"./{GRAPHSDIR}/*{G1_sub.submission_code}*.dot") or
            not glob.glob(f"./{GRAPHSDIR}/*{G2_sub.submission_code}*.dot")):
                combinations_list.remove((G1_sub, G2_sub))
        
        # print(combinations_list)
        args = [(G1_sub, G2_sub, SUBGRAPH_SIZE, GRAPHSDIR)
                for G1_sub, G2_sub in combinations_list]
        with mp.Pool(processes=mp.cpu_count()) as p:
            for result in tqdm(p.imap_unordered(process_combination, args),
                               total=len(args),
                               desc=f"{problem.code}",
                               position=0):
                # print(result[0], result[1], result[2], result[3], result[4])
                if result is not None:
                    if result[5]:  # error path
                        errors.add(result[5])
                    else:
                        results.append(result[:5])  # (G1_sub, G2_sub, res1, res2, mn)
        results.sort(key=lambda x: x[4], reverse=True)
        results.clear()
        errors.clear()
        # get_all_weakly_connected_subgraphs.cache_clear()
