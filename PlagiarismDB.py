from dataclasses import dataclass
import os
from sqlite3 import Error
from typing import List
import sqlite3
from typing import Optional



@dataclass
class Contest:
    id: int
    name: str
    contlen: int
    platform: str  # Codeforces или Yandex


@dataclass
class Problem:
    id: int
    code: str  # Буква задачи
    name: str


@dataclass
class Team:
    id: int
    code: int  # Локальный номер
    name: str


@dataclass
class Submission:
    id: int
    language: str
    team_code: int
    problem_code: str # Локальный номер
    submission_code: int # Локальный номер
    attempt: int
    time: int
    verdict: str
    code: str
    score: Optional[int] = None

    def __repr__(self):
        return (f"\nSubmission(filename={self.submission_code}{self.language}, id={self.id}|{self.submission_code}team={self.team_code},"
                f" problem='{self.problem_code}', attempt={self.attempt}, time={self.time}, verdict='{self.verdict}')")


class PlagiarismDB:
    def __init__(self, db_file="plagiarism.db"):
        self.db_file = db_file
        self.conn = None

        self.problems: List[Problem] = []
        self.teams: List[Team] = []
        self.submissions: List[Submission] = []

    def connect_db(self):
        try:
            self.conn = sqlite3.connect(self.db_file)
            return True
        except Error as e:
            print(f"Ошибка подключения: {e}")
            return False

    def close_db(self):
        if self.conn:
            self.conn.close()

    def create_tables(self):
        cursor = self.conn.cursor()
        try:
            sql_create_contests_table = """
            CREATE TABLE IF NOT EXISTS contests (
                contest_id integer PRIMARY KEY AUTOINCREMENT,
                contest_name varchar(255) UNIQUE,
                contlen integer,
                platform varchar(63)
            );
            """
            cursor.execute(sql_create_contests_table)
            self.conn.commit()
        except Error as e:
            print(f"Ошибка создания таблицы contests: {e}")
            exit(-255)

        try:
            sql_create_problems_table = """
            CREATE TABLE IF NOT EXISTS problems (
                problem_id integer PRIMARY KEY AUTOINCREMENT,
                contest_id integer REFERENCES contests(contest_id),
                problem_code varchar(3),
                problem_name varchar(127),
                UNIQUE(contest_id, problem_code)
            );
            """
            cursor.execute(sql_create_problems_table)
            self.conn.commit()
        except Error as e:
            print(f"Ошибка создания таблицы problems: {e}")
            exit(-255)

        try:
            sql_create_teams_table = """
            CREATE TABLE IF NOT EXISTS teams (
                team_id INTEGER PRIMARY KEY AUTOINCREMENT,
                contest_id INTEGER REFERENCES contests(contest_id),
                team_code INTEGER,
                team_name VARCHAR(127),
                UNIQUE(contest_id, team_code)
            );
            """
            cursor.execute(sql_create_teams_table)
            self.conn.commit()
        except Error as e:
            print(f"Ошибка создания таблицы teams: {e}")
            exit(-255)

        try:
            sql_create_submissions_table = """
            CREATE TABLE IF NOT EXISTS submissions (
                submission_id INTEGER PRIMARY KEY AUTOINCREMENT,
                language varchar(20),
                contest_id integer REFERENCES contests(contest_id),
                problem_id integer REFERENCES problems(problem_id),
                team_id integer REFERENCES teams(team_id),
                submission_code bigint,
                attempt integer,
                time integer,
                verdict varchar(3),
                score integer,
                code text,
                graph text,
                UNIQUE(contest_id, submission_code)
            );
            """
            cursor.execute(sql_create_submissions_table)
            self.conn.commit()
        except Error as e:
            print(f"Ошибка создания таблицы submissions: {e}")
            exit(-255)
        try:
            sql_create_results_table = """
            CREATE TABLE IF NOT EXISTS results (
                subgraphs_from INTEGER NOT NULL REFERENCES submissions(submission_id),
                isomorphism_to INTEGER NOT NULL REFERENCES submissions(submission_id),
                subgraph_size INTEGER NOT NULL,
                result REAL NOT NULL CHECK (result >= 0 AND result <= 1),
                UNIQUE(subgraphs_from, isomorphism_to, subgraph_size)
            );
            """
            cursor.execute(sql_create_results_table)
            self.conn.commit()
        except Error as e:
            print(f"Ошибка создания таблицы results: {e}")
            exit(-255)
        print("Таблицы созданы (если не существуют)")

    def save_contest(self, contest: Contest):
        try:
            cursor = self.conn.cursor()
            cursor.execute("""
                INSERT OR IGNORE INTO contests(contest_name, contlen, platform)
                VALUES (?, ?, ?) RETURNING contest_id 
            """, (contest.name, contest.contlen, contest.platform))
            result = cursor.fetchone()
            if result:
                contest_id = result[0]
            else:
                cursor.execute("""
                    SELECT contest_id FROM contests 
                    WHERE contest_name = ?
                """, (contest.name, ))
                contest_id = cursor.fetchone()[0]
            self.conn.commit()
            return contest_id
        except Error as e:
            print(f"Ошибка сохранения контеста: {e}")
            return None

    def save_problem(self, contest_id: int, problem: Problem):
        try:
            cursor = self.conn.cursor()
            cursor.execute("""
                INSERT OR IGNORE INTO problems (contest_id, problem_code, problem_name)
                VALUES (?, ?, ?) RETURNING problem_id
            """, (contest_id, problem.code, problem.name))
            result = cursor.fetchone()
            if result:
                problem_id = result[0]
            else:
                cursor.execute("""
                    SELECT problem_id FROM problems 
                    WHERE contest_id = ? AND problem_code = ?
                """, (contest_id, problem.code))
                problem_id = cursor.fetchone()[0]
            self.conn.commit()
            return problem_id
        except Error as e:
            print(f"Ошибка сохранения задачи {problem.code}: {e}")
            return None

    def save_team(self, contest_id: int, team: Team):
        try:
            cursor = self.conn.cursor()
            cursor.execute("""
                INSERT OR IGNORE INTO teams (contest_id, team_code, team_name)
                VALUES (?, ?, ?) RETURNING team_id
            """, (contest_id, team.code, team.name))
            result = cursor.fetchone()
            if result:
                team_id = result[0]
            else:
                cursor.execute("""
                    SELECT team_id FROM teams 
                    WHERE contest_id = ? AND team_code = ?
                """, (contest_id, team.code))
                team_id = cursor.fetchone()[0]
            self.conn.commit()
            return team_id
        except Error as e:
            print(f"Ошибка сохранения команды {team.code}: {e}")
            return None

    def save_submission(self, contest_id: int, problem_id: int, team_id: int, submission: Submission) -> None:
        try:
            cursor = self.conn.cursor()
            cursor.execute("""
                INSERT OR IGNORE INTO submissions (language, contest_id, problem_id, team_id, submission_code,
                           attempt, time, verdict, code, score)
                VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?) RETURNING submission_id
            """, (submission.language,
                  contest_id,
                  problem_id,
                  team_id,
                  submission.submission_code,
                  submission.attempt,
                  submission.time,
                  submission.verdict,
                  submission.code,
                  submission.score))
            result = cursor.fetchone()
            self.conn.commit()
            if result:
                submission_id = result[0]
            else:
                cursor.execute("""
                    SELECT submission_id FROM submissions 
                    WHERE contest_id = ? AND submission_code = ?
                """, (contest_id, submission.submission_code))
                submission_id = cursor.fetchone()[0]
            self.conn.commit()
            return submission_id
        except Error as e:
            print(f"Ошибка сохранения submission: {e}")

    def save_result(self, sub_from: int, iso_to: int, size: int, result: float) -> None:
        try:
            cursor = self.conn.cursor()
            cursor.execute("""
                INSERT OR REPLACE INTO results (subgraphs_from, isomorphism_to, subgraph_size, result)
                VALUES (?, ?, ?, ?)
            """, (sub_from, iso_to, size, result))
            self.conn.commit()
        except Error as e:
            print(f"Ошибка сохранения submission: {e}")

    def codeforces_parse(self, logfile, archive_path) -> Optional[int]:
        if not self.connect_db():
            return
        self.create_tables()
        files = sorted([f for f in os.listdir(archive_path) if os.path.isfile(os.path.join(archive_path, f))])
        idx = -1

        problem_db_ids = {}
        team_db_ids = {}

        with open(logfile, 'r', encoding='utf-8') as f:
            for line in f:
                line = line.strip()
                if not line:
                    continue

                parts = line.split(' ', 1)
                if len(parts) < 2:
                    continue

                cmd, data = parts

                if cmd == "@contest":
                    contest_name = data.strip('"')
                elif cmd == "@contlen":
                    contlen = int(data) * 60
                elif cmd == "@problems":
                    problems_count = int(data)
                elif cmd == "@teams":
                    teams_count = int(data)
                elif cmd == "@submissions":
                    submissions_count = int(data)

                    contest = Contest(
                        id=0,
                        name=contest_name,
                        contlen=contlen,
                        platform="Codeforces"
                    )
                    contest_id = self.save_contest(contest)
                    if contest_id:
                        contest.id = contest_id
                elif cmd == '@p':
                    p_data = data.split(',')
                    problem = Problem(
                        id=0,
                        code=p_data[0],
                        name=p_data[1],
                    )
                    problem_id = self.save_problem(contest_id, problem)
                    if problem_id:
                        problem_db_ids[problem.code] = problem_id
                        problem.id = problem_id
                    self.problems.append(problem)

                elif cmd == '@t':
                    t_data = data.split(',')
                    team = Team(
                        id=-1,
                        code=int(t_data[0]),
                        name=t_data[3],
                    )
                    team_id = self.save_team(contest_id, team)
                    if team_id:
                        team_db_ids[team.code] = team_id
                        team.id = team_id
                    self.teams.append(team)

                elif cmd == '@s':
                    idx += 1
                    filename, ext = os.path.splitext(files[idx])
                    if ext in ('.pypy3-64', '.py3', '.pypy3', '.pypy2'):
                        ext = '.py'
                    filepath = os.path.join(archive_path, files[idx])
                    with open(filepath, 'r', encoding='utf-8') as f:
                        code = f.read()

                    s_data = data.split(',')

                    team_code = int(s_data[0])
                    team_id = team_db_ids[team_code]

                    # Находим задачу по коду
                    problem_code = s_data[1]
                    problem_id = problem_db_ids[problem_code]

                    submission = Submission(
                        id=0,
                        language=ext,
                        team_code=team_code,
                        problem_code=problem_code,
                        submission_code=int(filename),
                        attempt=int(s_data[2]),
                        time=int(s_data[3]),
                        verdict=s_data[4],
                        code=code
                    )
                    submission_id = self.save_submission(contest_id, problem_id, team_id, submission)
                    if submission_id:
                        submission.id = submission_id
                    self.submissions.append(submission)
        print(f"Парсинг контеста Codeforces завершен.")
        return contest_id


    def yandex_parse(self, xml_file, archive_path) -> Optional[int]:
        import xml.etree.ElementTree as ET
        
        if not self.connect_db():
            return
        self.create_tables()
        
        # Парсим XML
        tree = ET.parse(xml_file)
        root = tree.getroot()
        
        # Получаем информацию о контесте
        settings = root.find('settings')
        contest_name = settings.find('contestName').text if settings.find('contestName') is not None else "Unknown Contest"
        
        # Длительность контеста в секундах
        duration_str = settings.find('duration').text if settings.find('duration') is not None else "0:00:00"
        duration_parts = duration_str.split(':')
        contlen = int(duration_parts[0]) * 3600 + int(duration_parts[1]) * 60 + int(duration_parts[2])
        
        # Сохраняем контест
        contest = Contest(
            id=0,
            name=contest_name,
            contlen=contlen,
            platform="Yandex"
        )
        contest_id = self.save_contest(contest)
        if contest_id:
            contest.id = contest_id
        else:
            print("Ошибка: не удалось сохранить контест")
            self.close_db()
            return
        
        # Парсим задачи
        problems_section = root.find('problems')
        problem_map = {}  # title -> (code, name)
        problem_id_map = {}  # title -> problem_id
        problem_code_map = {}  # title -> буква задачи (1->A, 2->B, ...)
        
        if problems_section is not None:
            for problem_elem in problems_section.findall('problem'):
                title = problem_elem.get('title')
                long_name = problem_elem.get('longName')
                if title:
                    problem_code = title
                    problem_code_map[title] = problem_code
                    problem = Problem(
                        id=0,
                        code=problem_code,
                        name=long_name if long_name else f"Задача {title}"
                    )
                    problem_id = self.save_problem(contest_id, problem)
                    if problem_id:
                        problem.id = problem_id
                        problem_id_map[title] = problem_id
                        problem_map[title] = problem
                    self.problems.append(problem)
        
        # Парсим пользователей (команды)
        users_section = root.find('users')
        team_map = {}  # user_id -> team
        team_id_map = {}  # user_id -> team_id в БД
        
        if users_section is not None:
            for user in users_section.findall('user'):
                user_id = user.get('id')
                login_name = user.get('loginName')
                displayed_name = user.get('displayedName')
                participation_type = user.get('participationType')
                
                # Пропускаем скрытых пользователей (жюри, мониторы и т.д.)
                if participation_type == "HIDDEN":
                    continue
                
                if user_id:
                    team_code = int(user_id) if user_id else 0
                    team = Team(
                        id=0,
                        code=team_code,
                        name=displayed_name if displayed_name else login_name
                    )
                    team_id = self.save_team(contest_id, team)
                    if team_id:
                        team.id = team_id
                        team_id_map[user_id] = team_id
                        team_map[user_id] = team
                    self.teams.append(team)
        
        # Сканируем archive_path для поиска файлов решений
        # Структура: archive_path/папка_участника/файл_решения
        # Формат файла: {problem_number}-{submission_id}-{language_id}-{verdict}
        # Сканируем archive_path для поиска файлов решений (рекурсивно)
        submission_files = {}  # submission_id -> (filepath, problem_number, language_id, verdict)

        if os.path.exists(archive_path):
            for participant_dir in os.listdir(archive_path):
                dir_path = os.path.join(archive_path, participant_dir)
                if not os.path.isdir(dir_path):
                    continue
                
                for filename in os.listdir(dir_path):
                    filepath = os.path.join(dir_path, filename)
                    if not os.path.isfile(filepath):
                        continue
                    
                    # Парсим имя файла: 1-149105975-No-compiler-WrongAnswer
                    parts = filename.split('-')
                    if len(parts) >= 4:
                        problem_number = parts[0]
                        submission_id = parts[1]
                        language_id = parts[2]
                        verdict = parts[3] if len(parts) > 3 else "Unknown"
                        
                        submission_files[submission_id] = {
                            'filepath': filepath,
                            'problem_number': problem_number,
                            'language_id': language_id,
                            'verdict': verdict,
                            'participant_dir': participant_dir
                        }
        
        # Парсим посылки
        events_section = root.find('events')
        submissions_count = 0
        
        if events_section is not None:
            for submit_elem in events_section.findall('submit'):
                submission_id = submit_elem.get('id')
                contest_time = int(submit_elem.get('contestTime', 0))
                problem_title = submit_elem.get('problemTitle')
                user_id = submit_elem.get('userId')
                language_id = submit_elem.get('languageId')
                verdict = submit_elem.get('verdict')
                score = submit_elem.get('score')
                
                # Пропускаем, если нет нужных данных
                if not submission_id or not problem_title or not user_id:
                    continue
                
                # Пропускаем скрытых пользователей
                if user_id not in team_id_map:
                    continue
                
                # Получаем ID задачи и команды
                problem_id = problem_id_map.get(problem_title)
                team_id = team_id_map.get(user_id)
                
                if not problem_id or not team_id:
                    continue
                
                # Получаем код задачи (букву)
                problem_code = problem_code_map.get(problem_title, problem_title)
                
                # Определяем язык
                lang = self._get_language_extension(language_id) if language_id else ".txt"
                
                # Пытаемся найти файл с кодом
                code = ""
                submission_info = submission_files.get(submission_id)
                if submission_info:
                    try:
                        with open(submission_info['filepath'], 'r', encoding='utf-8') as f:
                            code = f.read()
                    except Exception as e:
                        print(f"Ошибка чтения файла {submission_info['filepath']}: {e}")
                
                # Определяем попытку - считаем количество посылок по этой задаче от этого пользователя
                attempt = self._get_attempt_count(events_section, user_id, problem_title, submission_id)
                
                # Определяем финальный балл
                if score is not None:
                    try:
                        final_score = float(score)
                    except ValueError:
                        final_score = 0.0
                else:
                    final_score = 0.0
                
                # Создаём посылку
                submission = Submission(
                    id=0,
                    language=lang,
                    team_code=int(user_id),
                    problem_code=problem_code,
                    submission_code=int(submission_id),
                    attempt=attempt,
                    time=contest_time // 1000,
                    verdict=verdict if verdict else "Unknown",
                    code=code,
                    score=int(final_score) if final_score is not None else None
                )
                
                submission_db_id = self.save_submission(contest_id, problem_id, team_id, submission)
                if submission_db_id:
                    submission.id = submission_db_id
                self.submissions.append(submission)
                submissions_count += 1
        
        print(f"Парсинг Yandex завершен. Сохранено в БД: контест={contest.name}, задач={len(self.problems)}, команд={len(self.teams)}, посылок={submissions_count}")
        return contest_id

    def _get_attempt_count(self, events_section, user_id: str, problem_title: str, current_submission_id: str) -> int:
        """
        Подсчитывает номер попытки для данной посылки
        
        Args:
            events_section: секция events из XML
            user_id: ID пользователя
            problem_title: название задачи
            current_submission_id: ID текущей посылки
            
        Returns:
            номер попытки (начиная с 1)
        """
        attempt = 1
        for submit in events_section.findall('submit'):
            sub_id = submit.get('id')
            sub_user_id = submit.get('userId')
            sub_problem = submit.get('problemTitle')
            
            if (sub_user_id == user_id and 
                sub_problem == problem_title and 
                sub_id == current_submission_id):
                break
            
            if (sub_user_id == user_id and 
                sub_problem == problem_title):
                attempt += 1
        
        return attempt

    def _get_language_extension(self, language_id: str) -> str:
        """
        Определяет расширение файла по идентификатору языка
        
        Args:
            language_id: идентификатор языка из Яндекс.Контеста
            
        Returns:
            расширение файла (с точкой)
        """
        language_map = {
            'haskell': '.hs',
            'data-analysis-handbook': '.py',
            'dcc': '.pas',
            'fpc30': '.pas',
            'r_modules': '.r',
            'kotlin_2_1': '.kt',
            'golang-1_24': '.go',
            'dotnet8': '.cs',
            'pascal_abc': '.pas',
            'pypy3_7_1_0': '.py',
            'gcc14_cpp23': '.cpp',
            'python3_13': '.py',
            'jdk21': '.java',
            'rust154': '.rs',
            'scala_docker': '.scala',
            'No-compiler': '.txt',
        }
        return language_map.get(language_id, '.txt')

    def get_all_contests(self) -> List[Contest]:
        try:
            cursor = self.conn.cursor()
            cursor.execute("SELECT * FROM contests ORDER BY contest_id")

            contests = []
            for row in cursor.fetchall():
                contest = Contest(
                    id=row[0],
                    name=row[1],
                    contlen=row[2],
                    platform=row[3]
                )
                contests.append(contest)
            return contests
        except Error as e:
            print(f"Ошибка получения контестов: {e}")
            return []

    def get_problems_by_contest(self, contest_id: int) -> List[Problem]:
        try:
            cursor = self.conn.cursor()
            cursor.execute("""
                SELECT problem_id, problem_code, problem_name 
                FROM problems 
                WHERE contest_id = ?
            """, (contest_id,))

            problems = []
            for row in cursor.fetchall():
                problem = Problem(
                    id=row[0],
                    code=row[1],
                    name=row[2]
                )
                problems.append(problem)
            return problems
        except Error as e:
            print(f"Ошибка get_problems_by_contest: {contest_id}: {e}")
            return []


    def get_submissions_by_contest(self, contest_id: int) -> List[Submission]:
        try:
            cursor = self.conn.cursor()
            cursor.execute("""
                SELECT s.submission_id, s.language, t.team_code, p.problem_code, 
                    s.submission_code, s.attempt, s.time, s.verdict, s.code, s.score
                FROM submissions s
                JOIN teams t USING(team_id)
                JOIN problems p USING(problem_id)
                WHERE p.contest_id = ?
            """, (contest_id,))
            
            submissions = []
            for row in cursor.fetchall():
                submission = Submission(
                    id=row[0],
                    language=row[1],
                    team_code=row[2],
                    problem_code=row[3],
                    submission_code=row[4],
                    attempt=row[5],
                    time=row[6],
                    verdict=row[7],
                    code=row[8],
                    score=row[9]
                )
                submissions.append(submission)
            return submissions
        except Error as e:
            print(f"Ошибка get_submissions_by_contest: {contest_id}: {e}")
            return []


    def get_teams_by_contest(self, contest_id: int) -> List[Team]:
        try:
            cursor = self.conn.cursor()
            cursor.execute("""
                SELECT team_id, team_code, team_name 
                FROM teams 
                WHERE contest_id = ?
            """, (contest_id,))

            teams = []
            for row in cursor.fetchall():
                team = Team(
                    id=row[0],
                    code=row[1],
                    name=row[2]
                )
                teams.append(team)

            return teams
        except Exception as e:
            print(f"Ошибка получения команд контеста {contest_id}: {e}")
            return []


    def get_submissions_by_problem(self, problem_id: int) -> List[Submission]:
        try:
            cursor = self.conn.cursor()
            cursor.execute("""
                SELECT s.submission_id, s.language, s.team_id, p.problem_code, s.submission_code, s.attempt, s.time, s.verdict, s.score, s.code
                FROM submissions s
                JOIN problems p ON s.problem_id = p.problem_id
                WHERE s.problem_id = ?
            """, (problem_id,))

            submissions = []
            for row in cursor.fetchall():
                submission = Submission(
                    id=row[0],
                    language=row[1],
                    team_code=row[2],
                    problem_code=row[3],
                    submission_code=row[4],
                    attempt=row[5],
                    time=row[6],
                    verdict=row[7],
                    score=row[8],
                    code=row[9]
                )
                submissions.append(submission)
            return submissions
        except Error as e:
            print(f"Ошибка получения посылок задачи {problem_id}: {e}")
            return []
        

    def get_submissions_by_team(self, team_id: int) -> List[Submission]:
        try:
            cursor = self.conn.cursor()
            cursor.execute("""
                SELECT s.submission_id, s.language, t.team_code, p.problem_code, s.submission_code, s.attempt, s.time, s.verdict, s.score, s.code
                FROM submissions s
                JOIN teams t ON s.team_id = t.team_id
                JOIN problems p ON s.problem_id = p.problem_id
                WHERE s.team_id = ?
                ORDER BY time
            """, (team_id,))

            submissions = []
            for row in cursor.fetchall():
                submission = Submission(
                    id=row[0],
                    language=row[1],
                    team_code=row[2],
                    problem_code=row[3],
                    submission_code=row[4],
                    attempt=row[5],
                    time=row[6],
                    verdict=row[7],
                    score=row[8],
                    code=row[9]
                )
                submissions.append(submission)
            return submissions
        except Error as e:
            print(f"Ошибка получения посылок задачи {team_id}: {e}")
            return []

    def get_subgraph_sizes(self) -> List[int]:
        try:
            cursor = self.conn.cursor()
            cursor.execute("SELECT DISTINCT subgraph_size FROM results ORDER BY subgraph_size")

            return [row[0] for row in cursor.fetchall()]
        except Error as e:
            print(f"Ошибка получения размеров подграфов: {e}")
            return []

    def get_results_by_filters(self, contest_id: int, problem_code: str, subgraph_size: int) -> List[tuple]:
        try:
            cursor = self.conn.cursor()
            query = """
            SELECT 
                r.subgraphs_from,
                r.isomorphism_to, 
                r.subgraph_size,
                r.result,
                t1.team_code as from_team,
                t2.team_code as to_team,
                p.problem_code,
                s1.attempt as from_attempt,
                s2.attempt as to_attempt
            FROM results r
            JOIN submissions s1 ON r.subgraphs_from = s1.submission_id
            JOIN submissions s2 ON r.isomorphism_to = s2.submission_id
            JOIN teams t1 ON s1.team_id = t1.team_id
            JOIN teams t2 ON s2.team_id = t2.team_id
            JOIN problems p ON s1.problem_id = p.problem_id
            WHERE p.contest_id = ? AND p.problem_code = ? AND r.subgraph_size = ?
            ORDER BY r.result DESC
            """

            cursor.execute(query, (contest_id, problem_code, subgraph_size))
            return cursor.fetchall()
        except Error as e:
            print(f"Ошибка получения результатов: {e}")
            return []

    def get_problem_codes_by_contest(self, contest_id: int) -> List[str]:
        try:
            cursor = self.conn.cursor()
            cursor.execute("""
                SELECT DISTINCT problem_code 
                FROM problems 
                WHERE contest_id = ? 
                ORDER BY problem_code
            """, (contest_id,))
            return [row[0] for row in cursor.fetchall()]
        except Error as e:
            print(f"Ошибка получения кодов задач: {e}")
            return []

    def get_final_results_by_filters(self, contest_id: int, problem_code: str, subgraph_size: int,
                                     limit: int = 50, offset: int = 0) -> List[tuple]:
        try:
            cursor = self.conn.cursor()
            query = """
            SELECT 
                s1.submission_code AS sub1,
                s2.submission_code AS sub2,
                t1.team_name AS team1,
                t2.team_name AS team2,
                r1.subgraph_size AS size,
                r1.result AS result1,
                r2.result AS result2,
                s1.code AS code1,
                s2.code AS code2,
                CASE 
                    WHEN r1.result < r2.result THEN r1.result 
                    ELSE r2.result 
                END AS final_result
            FROM results r1
            JOIN results r2 ON r1.subgraphs_from = r2.isomorphism_to 
                        AND r1.isomorphism_to = r2.subgraphs_from 
                        AND r1.subgraph_size = r2.subgraph_size
            JOIN submissions s1 ON r1.subgraphs_from = s1.submission_id
            JOIN submissions s2 ON r1.isomorphism_to = s2.submission_id
            JOIN teams t1 ON s1.team_id = t1.team_id
            JOIN teams t2 ON s2.team_id = t2.team_id
            JOIN problems p ON s1.problem_id = p.problem_id
            WHERE p.contest_id = ?
                AND p.problem_code = ?
                AND r1.subgraph_size = ?
                AND r1.subgraphs_from < r1.isomorphism_to  -- избегаем дубликатов
            ORDER BY final_result DESC
            LIMIT ? OFFSET ?
            """

            cursor.execute(query, (contest_id, problem_code, subgraph_size, limit, offset))
            return cursor.fetchall()
        except Error as e:
            print(f"Ошибка получения финальных результатов: {e}")
            return []


if __name__ == "__main__":
    db = PlagiarismDB('plagiarism.db')
    # db.codeforces_parse('../log.txt', '../602776')
    # print(db.problems)
    # print(db.get_problems_by_contest(1))
    # print(db.get_submissions_by_problem(11))
    # print(db.get_submissions_by_team(11))
    # print(db.get_final_results_by_filters(1, 'B', 4))
    # print(db.get_final_results_by_filters(1, 'C', 4))
    # print(db.teams)
    # print(db.submissions)

    db.yandex_parse('../log-911-2.xml', '../submits911')

    db.close_db()