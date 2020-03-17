'''
Problem Statement: https://practice.geeksforgeeks.org/problems/prime-number-of-set-bits/0
Author: striker
'''

def check_prime(n):
    if n == 2 or n == 3:
        return True
    if n == 1 or not n % 2 or not n % 3:
        return False
    is_prime = True
    i = 5
    while i * i <= n:
        if not n % i:
            is_prime = False
            break
        i += 1
    return is_prime

def compute_set_bit(n):
    count_set_bit = 0
    while n:
        count_set_bit += 1
        n &= (n - 1)
    return count_set_bit

def compute_prime_set_bit(start, end):
    count_prime_set_bit = 0
    for i in range(start, end + 1):
        if check_prime(compute_set_bit(i)):
            count_prime_set_bit += 1
            continue
    return count_prime_set_bit

def main():
    for test in range(int(input().rstrip())):
        l, r = tuple(map(int, input().rstrip().split()))
        print("{0}".format(compute_prime_set_bit(l, r)))

if __name__ == "__main__":
    main()
