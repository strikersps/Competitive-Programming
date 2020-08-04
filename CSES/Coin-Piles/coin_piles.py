"""
Problem Statement: https://cses.fi/problemset/task/1754
Author: striker
"""

def check_piles_empty_possible(a: int, b: int) -> bool:
    x = 2 * b - a; y = 2 * a - b
    if x < 0 or y < 0:
        return False
    return not (x % 3) and not (y % 3)


def main():
    for _ in range(int(input().strip())):
        a, b = map(int, input().strip().split())
        print("YES" if check_piles_empty_possible(a, b) else "NO")

if __name__ == "__main__":
    main()
