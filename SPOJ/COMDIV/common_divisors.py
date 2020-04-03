'''
Problem Statement: https://www.spoj.com/problems/COMDIV/
Author: striker
'''

def compute_gcd(a, b):
    if not a:
        return b
    if not b:
        return a
    return compute_gcd(b, a % b)

def compute_total_divisors(n):
    total_divisors = 0
    i = 1
    while i <= (n // i):
        if not n % i:
            if n // i != i:
                total_divisors += 2
            else:
                total_divisors += 1
        i += 1
    return total_divisors

def main():
    for test in range(int(input().strip())):
        a, b = map(int, input().strip().split())
        print(f"{compute_total_divisors(compute_gcd(a, b))}")

if __name__ == "__main__":
    main()
