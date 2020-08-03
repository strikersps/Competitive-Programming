"""
Problem Statement: https://cses.fi/problemset/task/1618
Author: striker
"""

def compute_power(base: int, exponent: int) -> int:
    if not exponent:
        return 1
    if exponent == 1:
        return base
    result = 1
    while exponent:
        if exponent % 2:
            result *= base
        base *= base
        exponent //= 2
    return result

def compute_trailing_zeroes(n: int) -> int:
    if n < 5:
        return 0
    power_of_five = compute_power(5, 1)
    trailing_zeroes_count = 0
    for exponent in range(2, n):
        if not (n // power_of_five):
            break
        trailing_zeroes_count += (n // power_of_five)
        power_of_five = compute_power(5, exponent)
    return trailing_zeroes_count

def main():
    print(compute_trailing_zeroes(int(input().strip())))

if __name__ == "__main__":
    main()
