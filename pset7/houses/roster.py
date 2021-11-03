from sys import argv
from cs50 import SQL


def main():
    # check for correct usage
    if len(argv) != 2:
        print("Usage: python roster.py house")
        return 1

    # Set up database connection
    db = SQL("sqlite:///students.db")

    # Execute query
    query = db.execute("SELECT * FROM students WHERE house = ? ORDER BY last, first", argv[1])

    for row in query:
        first = row['first']
        middle = row['middle']
        last = row['last']
        birth = row['birth']

        print(first, end=' ')

        # check for None(NULL) in middle name
        if middle != None:
            print(middle, end=' ')

        print(last, end=', ')

        print("born", birth)


if __name__ == "__main__":
    main()