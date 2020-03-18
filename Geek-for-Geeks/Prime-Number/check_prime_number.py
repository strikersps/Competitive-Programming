'''
Problem Statement: https://practice.geeksforgeeks.org/problems/prime-number/0
Author: striker
'''

def check_prime(n):
    if n == 2 or n == 3:
        return True
    if n == 1 or not n % 2 or not n % 3:
        return False
    is_prime = True
    i = 5
    while i*i <= n:
        if not n % i:
            is_prime = False
            break
        i += 1
    return is_prime

def main():
    for test in range(int(input().rstrip())):
        number = int(input().rstrip())
        print("{0}".format("Yes" if check_prime(number) else "No"))

if __name__ == "__main__":
    main()
