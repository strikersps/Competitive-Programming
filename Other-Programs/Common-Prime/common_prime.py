'''
You can refer to the screen-shot in the directory for the problem statement. Problem was asked in JP Morgan Chase Online Programming Challenge.
Author: striker
'''

import math

def compute_gcd(a,b):
    if b == 0:
        return a
    else:
        return compute_gcd(b,(a % b))

def find_smallest_prime_factor(n):
    prime_factors = list()
    while (n % 2) == 0:
        prime_factors.append(2)
        n = n / 2
    for i in range(3,int(math.floor((math.sqrt(n)) + 1))):
        if n % i == 0:
            prime_factors.append(i)
            n = n / i
    if n > 2:
        prime_factors.append(int(n))
    return prime_factors

def main():
    a,b = input().split()
    a = int(a)
    b = int(b)
    if compute_gcd(a,b) == 1:
        print("-1")
    else:
        prime_factors = find_smallest_prime_factor(compute_gcd(a,b))
        print(min(prime_factors))

if __name__ == "__main__":
    main()
