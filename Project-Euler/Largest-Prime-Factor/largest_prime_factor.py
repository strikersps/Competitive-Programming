'''
Problem Statement: https://www.hackerrank.com/contests/projecteuler/challenges/euler003/problem || https://projecteuler.net/problem=3
Author: striker
'''

def find_largest_prime_factor(n):
    prime_factors = dict()
    while not (n & 1):
        n >>= 1
        if prime_factors.get(2) == None:
            prime_factors[2] = 1
        else:
            prime_factors[2] += 1 
    i = 3
    while i**2 <= n:
        while n % i == 0:
            if prime_factors.get(n) == None:
                prime_factors[i] = 1
            else:
                prime_factors[i] += 1
            n = int(n/i)
        i += 2
    if n > 2:
        if prime_factors.get(n) == None:
            prime_factors[n] = 1
    return max(prime_factors)

def main():
    test = int(input())
    for _ in range(test):
        n = int(input())
        print(find_largest_prime_factor(n))

if __name__ == "__main__":
    main()