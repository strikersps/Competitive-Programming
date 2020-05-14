"""
Problem Statement: https://cses.fi/problemset/task/1617
Author: striker
"""

MOD = 10**9 + 7

def modular_exponentiation(base : int, exponent : int, modulus : int) ->  int:
    if modulus == 1:
        return 0
    if exponent == 0:
        return 1
    if exponent == 1:
        return base
    result = 1
    while exponent:
        if exponent & 1:
            result = (result * base) % modulus
        base = (base * base) % modulus
        exponent >>= 1
    return result

def compute_number_of_bit_strings(n : int) -> int:
    if n == 1:
        return 2
    return modular_exponentiation(2, n, MOD)

def main():
    print(compute_number_of_bit_strings(int(input().strip())))

if __name__ == "__main__":
    main()