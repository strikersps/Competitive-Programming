"""
Problem Statement: https://www.hackerrank.com/challenges/py-collections-ordereddict/problem
Author: striker
"""

from collections import OrderedDict

def main():
    buyed_items = OrderedDict()
    for _ in range(int(input().strip())):
        data = input().strip().split()
        name_of_item, item_price = ' '.join(data[:len(data) - 1]), int(data[-1])
        if name_of_item not in buyed_items:
            buyed_items[name_of_item] = list([item_price])
            continue
        buyed_items[name_of_item].append(item_price)
    for item_name, paid_price in buyed_items.items():
        print(f'{item_name} {paid_price[0] * len(paid_price)}')

if __name__ == "__main__":
    main()