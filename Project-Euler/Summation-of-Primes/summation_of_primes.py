'''
Problem Statement: https://www.hackerrank.com/contests/projecteuler/challenges/euler010/problem
Author: striker
'''

MAX_LIMIT = (10**6) + 1

def generate_prime_sum():
    is_prime = [True] * MAX_LIMIT
    is_prime[0] = is_prime[1] = False
    prime_sum = [0] * MAX_LIMIT
    for i in range(2, MAX_LIMIT):
        if is_prime[i]:
            prime_sum[i - 1] = prime_sum[i - 2] + i;
            j = i * i
            while j < MAX_LIMIT:
                is_prime[j] = False
                j += i
            continue
        prime_sum[i - 1] = prime_sum[i - 2]
    return prime_sum

def main():
    prime_sum = generate_prime_sum()
    for test in range(int(input().rstrip())):
        n = int(input().rstrip())
        print("{}".format(prime_sum[n - 1]))

if __name__ == "__main__":
    main()
