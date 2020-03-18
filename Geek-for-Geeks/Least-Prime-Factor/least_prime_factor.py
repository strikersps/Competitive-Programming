'''
Problem Statement: https://practice.geeksforgeeks.org/problems/least-prime-factor/0
Author: striker
'''

def compute_least_prime_factor(n):
    if not n % 2:
        return 2
    least_prime_factor = n
    i = 3
    while i * i <= n:
        if not n % i:
            least_prime_factor = i
            break
        i += 2
    return least_prime_factor

def main():
    for test in range(int(input().rstrip())):
        n = int(input().rstrip())
        for number in range(1, n + 1):
            print("{0}".format("1" if number == 1 else compute_least_prime_factor(number)), end = " ")
        print()

if __name__ == "__main__":
    main()
