import sqlite3
from datetime import datetime

class Database:
    #funktion til at oprette database og tabellen
    def create_database(db_path):
        conn = sqlite3.connect(db_path)
        c = conn.cursor()
        c.execute('''
            CREATE TABLE IF NOT EXISTS logs (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                timestamp TEXT,
                level TEXT,
                message TEXT
            )
        ''')
        conn.commit()
        conn.close()

    #funktion til at gemme en log
    def save_log(db_path, level, message):
        conn = sqlite3.connect(db_path)
        c = conn.cursor()
        c.execute("INSERT INTO logs (timestamp, level, message) VALUES (?, ?, ?)",(datetime.now().isoformat(),level,message))
        conn.commit()
        conn.close()

    # Funktion til at vise alle logs
    def get_logs(db_path, order="DESC"):
        conn = sqlite3.connect(db_path)
        c = conn.cursor()
        c.execute(f"SELECT * FROM logs ORDER BY timestamp {order}")
        rows = c.fetchall()
        conn.close()
        return rows

