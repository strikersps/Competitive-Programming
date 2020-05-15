"""
Problem Statement: https://codeforces.com/problemset/problem/271/A
Author: striker
"""

LIMIT = 9100

def check_distinct_digit(number: int) -> bool:
    has_distinct_digit = True
    digit_visited = set()
    while number:
        if (number % 10) in digit_visited:
            has_distinct_digit = False
            break
        digit_visited.add(number % 10)
        number //= 10
    return has_distinct_digit

def compute_distinct_year(year: int) -> int:
    for yr in range(year + 1, LIMIT):
        if check_distinct_digit(yr):
            distinct_year = yr
            break
    return distinct_year

def main():
    print(compute_distinct_year(int(input().strip())))

if __name__ == "__main__":
    main()
