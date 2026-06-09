import os
import shutil

from PlagiarismDB import PlagiarismDB

# ИСПОЛЬЗОВАТЬ ТОЛЬКО 1 РАЗ, ибо в log файле нет привязок решений к файлам

# PLATFORM = "Codeforces"
# LOGPATH = "log.txt"
# ARCHIVEPATH = "602776"

# PLATFORM = "Yandex"
# LOGPATH = "log-911-1.xml"
# ARCHIVEPATH = "submits-911-1"

PLATFORM = "Yandex"
LOGPATH = "log-911-2.xml"
ARCHIVEPATH = "submits-911-2"

ARCHIVEPATH_OK = ARCHIVEPATH + '_OK'

# Создаем папку для правильных решений
if not os.path.exists(ARCHIVEPATH_OK):
    os.makedirs(ARCHIVEPATH_OK)

count = 0
db = PlagiarismDB('plagiarism.db')
if PLATFORM == "Yandex":
    contest_id = db.yandex_parse(LOGPATH, ARCHIVEPATH)
    for participant_dir in os.listdir(ARCHIVEPATH):
        dir_path = os.path.join(ARCHIVEPATH, participant_dir)
        if not os.path.isdir(dir_path):
            continue
        for sub in os.listdir(dir_path):
            filepath = os.path.join(dir_path, sub)
            if not os.path.isfile(filepath):
                continue
            filename, _ = os.path.splitext(sub)
            parts = filename.split('-')
            submission_code = parts[1]
            verdict = parts[-1]
            if verdict == "OK":
                cursor = db.conn.cursor()
                cursor.execute("""
                        SELECT language FROM submissions WHERE submission_code = ? AND contest_id = ?
                        """, (submission_code, contest_id))
                language = cursor.fetchone()[0]
                if language not in ('.py', '.c', '.cpp', '.java', '.js', '.cs', '.go', '.rs', '.php'):
                    continue
                count += 1
                fullfilename = filename + language
                source_file = os.path.join(dir_path, sub)
                target_file = os.path.join(ARCHIVEPATH_OK, fullfilename)
                if os.path.exists(source_file):
                    shutil.copy2(source_file, target_file)
elif PLATFORM == "Codeforces":
    contest_id = db.codeforces_parse(LOGPATH, ARCHIVEPATH)
    for sub in os.listdir(ARCHIVEPATH):
        filepath = os.path.join(ARCHIVEPATH, sub)
        if not os.path.isfile(filepath):
            continue
        filename, _ = os.path.splitext(sub)
        cursor = db.conn.cursor()
        cursor.execute("""
                SELECT verdict FROM submissions WHERE submission_code = ? AND contest_id = ?
                """, (filename, contest_id))
        verdict = cursor.fetchone()[0]
        if verdict == "OK":
            count += 1
            cursor = db.conn.cursor()
            cursor.execute("""
                    SELECT language FROM submissions WHERE submission_code = ? AND contest_id = ?
                    """, (filename, contest_id))
            language = cursor.fetchone()[0]
            fullfilename = filename + language
            source_file = os.path.join(ARCHIVEPATH, sub)
            target_file = os.path.join(ARCHIVEPATH_OK, fullfilename)
            if os.path.exists(source_file):
                shutil.copy2(source_file, target_file)
print(f"Всего {count}")