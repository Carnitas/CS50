from cs50 import get_int

height = get_int("Number of rows: ")


def main():
    x = height
    while x > 0:
        print_space(x)
        print_blocks(height - x)
        x -= 1


def print_blocks(blocks):
    for i in range(blocks + 1):
        print("#", end="")
    print("")


def print_space(space):
    while space > 0:
        print(" ", end="")
        space -= 1


main()
