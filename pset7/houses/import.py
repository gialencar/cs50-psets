from cs50 import SQL
from sys import argv
import csv


def main():
    # check for correct usage
    if len(argv) != 2:
        print("Usage: python import.py data.csv")
        return 1

    # set up database connection
    db = SQL("sqlite:///students.db")

    with open(argv[1]) as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:

            house = row['house']
            birth = row['birth']

            # Split name
            name = row['name'].split(' ')

            # Insert names
            # If there is no middle name it's value should be set to NULL in db
            if len(name) == 2:
                db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)",
                           name[0], None, name[1], house, birth)

            else:
                db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)",
                           name[0], name[1], name[2], house, birth)


if __name__ == "__main__":
    main()
