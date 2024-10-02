from cs50 import get_string
import csv

with open("foo.csv") as file:
    reader = csv.DictReader(file)
    print(reader.fieldnames)

rows = []
with open("foo.csv") as file:
    reader = csv.DictReader(file)
    for row in reader:
        rows.append(row)


def main():
    pass


main()
