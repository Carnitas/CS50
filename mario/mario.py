from cs50 import get_int


def get_height(prompt):
    while True:
        try:
            height = int(input(prompt))
            if 2 <= height <= 8:
                return height
            else:
                print("Please select a number between 2 and 8 inclusive.")
        except ValueError:
            print("Please select a number between 2 and 8 inclusive.")


def main():
    height = get_height("Height? ")
    for x in range(height, 0, -1):
        print(" " * x, end="")
        print("#" * (height - x + 1))


main()
