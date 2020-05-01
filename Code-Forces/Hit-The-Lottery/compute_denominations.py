"""
Problem Statement: https://codeforces.com/problemset/problem/996/A
Author: striker
"""

def main():
    total_dollars = int(input().strip())
    total_bills = 0
    while(total_dollars):
        if total_dollars >= 100:
            total_bills += total_dollars // 100
            total_dollars %= 100
            continue
        if total_dollars >= 20:
            total_bills += total_dollars // 20
            total_dollars %= 20
            continue
        if total_dollars >= 10:
            total_bills += total_dollars // 10
            total_dollars %= 10
            continue
        if total_dollars >= 5:
            total_bills += total_dollars // 5
            total_dollars %= 5
            continue
        total_bills += total_dollars
        total_dollars = 0
    print(total_bills)

if __name__ == "__main__":
    main()
