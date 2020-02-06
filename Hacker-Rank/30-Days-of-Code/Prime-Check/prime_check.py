'''
Problem Statement: https://www.hackerrank.com/challenges/30-running-time-and-complexity/problem
Author: striker
'''

def check_prime(n):
    if n == 2 or n == 3:
        return True
    elif n == 1 or not n % 2 or not n % 3:
        return False
    is_prime = True
    i = 5
    while i * i <= n:
        if not n % i:
            is_prime = False
            break
        i += 1
    return is_prime

def main():
    for test in range(int(input().rstrip())):
        print("{}".format("Prime" if check_prime(int(input().rstrip())) else "Not prime"))

if __name__ == "__main__":
    main()
