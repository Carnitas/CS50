coin_values = [("quarters", 25), ("dimes", 10), ("nickles", 5), ("pennies", 1)]


def main():
    change = get_change("How much? ")
    coins = 0
    for coin, value in coin_values:
        if change > 0:
            coin_count = change // value
            change = change - (coin_count * value)
            coins += coin_count
    print(f"Total coins: {coins}")


def get_change(prompt):
    while True:
        try:
            change = int(input(prompt))
            if change > 0:
                return int(change)
            else:
                print("Please enter an amount of change.")
        except ValueError:
            print("Please enter an amount of change.")


main()
