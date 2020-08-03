"""
Problem Statement: https://www.spoj.com/problems/FCTRL/
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

def compute_trailing_zeros(n: int) -> int:
    if n < 5:
        return 0
    count_trailing_zeroes = 0; exponent = 2
    power_of_five = compute_power(5, 1)
    while n // power_of_five:
        count_trailing_zeroes += (n // power_of_five)
        power_of_five = compute_power(5, exponent)
        exponent += 1
    return count_trailing_zeroes

def main():
    for _ in range(int(input().strip())):
        print(compute_trailing_zeros(int(input().strip())))

if __name__ == "__main__":
    main()
