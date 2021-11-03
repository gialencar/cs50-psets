import csv
from sys import argv


def main():
    # check for 2 command line arguments
    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        return 1

    # open the CSV file and read its contents into memory
    with open(argv[1]) as csvfile:
        reader = csv.DictReader(csvfile)
        fieldnames = reader.fieldnames[1:]

        # open the DNA sequence and read its contents into memory
        with open(argv[2], 'r') as sequence_file:
            sequence = sequence_file.read()

            str_counts = {}
            for STR in fieldnames:
                str_counts[STR] = count_STR(STR, sequence)

            match = False
            for row in reader:
                count = 0

                for STR in fieldnames:
                    if int(row[STR]) == str_counts[STR]:
                        count += 1

                if count == len(fieldnames):
                    print(row["name"])
                    match = True

            if match == False:
                print("No match")


def count_STR(sub, seq):
    counter = 0
    highest = 0

    index = seq.find(sub)
    # find returns -1 if sub not found
    if index == -1:
        return 0

    else:
        while index != - 1:
            counter += 1
            # partition text and get everything to the right of sub
            seq = seq.partition(sub)[-1]

            # reset counter if next occurrence is not consecutive
            if seq.find(sub) != 0:
                if counter > highest:
                    highest = counter
                counter = 0

            index = seq.find(sub)

    return highest


if __name__ == "__main__":
    main()