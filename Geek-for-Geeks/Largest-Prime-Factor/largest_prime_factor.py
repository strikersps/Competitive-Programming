'''
Problem Statement: https://practice.geeksforgeeks.org/problems/largest-prime-factor/0
Author: striker
'''

def compute_largest_prime_factor(n):
    largest_prime_factor = 0
    if not n % 2:
        largest_prime_factor = 2
        while not n % 2:
            n //= 2
    i = 3
    while i * i <= n:
        if not n % i:
            largest_prime_factor = i
            while not n % i:
                n //= i
        i += 2
    if n > 1:
        largest_prime_factor = n
    return largest_prime_factor

def main():
    for test in range(int(input().rstrip())):
        print("{0}".format(compute_largest_prime_factor(int(input().rstrip()))))

if __name__ == "__main__":
    main()
