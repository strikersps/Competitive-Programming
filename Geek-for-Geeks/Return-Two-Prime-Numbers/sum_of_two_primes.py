'''
Problem Statement: https://practice.geeksforgeeks.org/problems/return-two-prime-numbers/0
Author: striker
'''

MAX_LIMIT = 10001
TOTAL_PRIMES_UNDER_MAX_LIMIT = 1229

def prime_generator():
    primes = list()
    sieve = [True] * MAX_LIMIT
    sieve[0] = sieve[1] = False
    for number in range(2, MAX_LIMIT):
        if sieve[number]:
            primes.append(number)
            j = number * number
            while j < MAX_LIMIT:
                sieve[j] = False
                j += number
    return primes

def main():
    primes = prime_generator()
    for test in range(int(input().rstrip())):
        number = int(input().rstrip())
        start = 0; end = TOTAL_PRIMES_UNDER_MAX_LIMIT - 1
        while start <= end:
            pair_sum = primes[start] + primes[end]
            if number == pair_sum:
                print("{0} {1}".format(primes[start], primes[end]))
                break
            elif number < pair_sum:
                end -= 1
                continue
            start += 1

if __name__ == "__main__":
    main()
