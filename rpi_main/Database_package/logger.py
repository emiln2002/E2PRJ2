import sqlite3
from datetime import datetime

class Database:

    def __init__(self, db_path):
        self.db_path = db_path
        self.create_database()

    #funktion til at oprette database og tabellen
    def create_database(self):
        conn = sqlite3.connect(self.db_path)
        c = conn.cursor()
        c.execute('''
            CREATE TABLE IF NOT EXISTS logs (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                timestamp TEXT,
                level TEXT,
                message TEXT,
                value INT
            )
        ''')
        conn.commit()
        conn.close()

    #funktion til at gemme en log
    def save_log(self, level, message, value):
        conn = sqlite3.connect(self.db_path)
        c = conn.cursor()
        c.execute("INSERT INTO logs (timestamp, level, message, value) VALUES (?, ?, ?, ?)",(datetime.now().isoformat(),level,message, value))
        conn.commit()
        conn.close()

    # Funktion til at vise alle logs
    def get_logs(self, order):
        conn = sqlite3.connect(self.db_path)
        c = conn.cursor()
        c.execute(f"SELECT * FROM logs ORDER BY timestamp {order}")
        rows = c.fetchall()
        conn.close()
        return rows
