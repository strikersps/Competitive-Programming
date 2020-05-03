"""
Problem Statement: https://cses.fi/problemset/task/1068/
Author: striker
"""

def simulate_process(n):
    while n != 1:
        print(f'{n}', end = ' ')
        if n % 2:
            n = (3 * n) + 1;
        else:
            n //= 2
    print(f'{n}')

def main():
    n = int(input().strip())
    simulate_process(n)

if __name__ == "__main__":
    main()
