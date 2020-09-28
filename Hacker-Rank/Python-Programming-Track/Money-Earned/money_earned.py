"""
Problem Statement: https://www.hackerrank.com/challenges/collections-counter/problem
Author: striker
"""

from collections import Counter

def main():
    total_shoes = int(input().strip())
    shoe_sizes = Counter(list(map(int, input().strip().split())))
    money_earned = 0
    for _ in range(int(input().strip())):
        ask_size, spent_money = map(int, input().strip().split())
        if shoe_sizes[ask_size]:
            money_earned += spent_money
            shoe_sizes[ask_size] -= 1
    print(money_earned)

if __name__ == "__main__":
    main()