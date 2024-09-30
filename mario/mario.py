from cs50 import get_int

rows = get_int("Number of rows: ")
for i in range(rows):
    for j in range(rows):
        print("#", end="")
    print("")
