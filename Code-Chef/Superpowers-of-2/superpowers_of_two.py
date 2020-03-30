'''
Problem Statement: https://www.codechef.com/problems/SPOTWO
Author: striker
'''

MOD = 10**9 + 7

def compute_modular_exponentiation(base, exponent):
    result = 1
    while exponent:
        if exponent & 1:
            result = (result * base) % MOD
        base = (base * base) % MOD
        exponent >>= 1
    return result

def main():
    for test in range(int(input().strip())):
        nth_power_binary = int("{0:b}".format(int(input().strip())))
        print("{0}".format(compute_modular_exponentiation(compute_modular_exponentiation(2, nth_power_binary), 2)))

if __name__ == "__main__":
    main()
