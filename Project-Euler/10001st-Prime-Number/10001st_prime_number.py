'''
Problem Statement: https://www.hackerrank.com/contests/projecteuler/challenges/euler007/problem or https://projecteuler.net/problem=7
Author: striker
'''

MAX_LIMIT = 10**6

def prime_number_generator():
    sieve_table = [True] * MAX_LIMIT
    sieve_table[0] = False
    sieve_table[1] = False
    prime_numbers = list()
    for i in range(2,MAX_LIMIT):
        if sieve_table[i]:
            prime_numbers.append(i)
            j = i**2
            while j < MAX_LIMIT:
                sieve_table[j] = False
                j += i
    return prime_numbers

def main():
    test = int(input())
    assert(test > 0)
    prime_numbers = prime_number_generator()
    for _ in range(test):
        n = int(input())
        print(prime_numbers[n - 1])


if __name__ == "__main__":
    main()