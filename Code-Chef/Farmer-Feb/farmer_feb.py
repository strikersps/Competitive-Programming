'''
Problem Statement: https://www.codechef.com/problems/POTATOES/
Author: striker
'''

MAX_LIMIT = 1000

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

def main():
    for test in range(int(input().strip())):
        x, y = map(int, input().strip().split())
        for z in range(1, MAX_LIMIT):
            if check_prime(x + y + z):
                print(z)
                break

if __name__ == "__main__":
    main()
