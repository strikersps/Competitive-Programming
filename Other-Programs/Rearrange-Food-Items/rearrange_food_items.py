"""
Problem Statement: Refer to readme.md file.
Author: striker
"""

from collections import defaultdict

def main():
    for test in range(int(input().strip())):
        fruit_prices = defaultdict(list) # Creating a defaultdict object by specifying the dafault value with which it should be intitialised with i.e. list.
        """
        Creation of dictionary from the user-input.
        """
        for _ in range(int(input().strip())):
            fruit_price_pair = tuple(input().strip().split())
            fruit_prices[fruit_price_pair[0]].append(int(fruit_price_pair[1]))
        """
        Updating the dictionary according to what is asked in the problem statement.
        """
        for fruit_name, price in fruit_prices.items():
            fruit_prices[fruit_name] = [min(price), max(price), sum(price) // len(price)]
        """
        Sorting the dictionary by keys using sorted().
        NOTE: Do remember that, sorted() function returns a list of values which in this case is list of tuples. But if you convert the sorted list back to the dictionary object then sorted order will not remain same as dictionary stores data in an un-ordered fashion.
        """
        fruit_prices = sorted(fruit_prices.items())
        """
        Printing the data as suggested in the problem statement.
        """
        print(f"Case #{test + 1}:")
        for fruit_name, price_list in fruit_prices:
            print(f"{fruit_name} {' '.join(map(str, price_list))}")

if __name__ == "__main__":
    main()
