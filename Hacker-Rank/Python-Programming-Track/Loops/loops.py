'''
Problem Statement: https://www.hackerrank.com/challenges/python-loops/problem
Author: striker
'''

def print_square_of_sequence(n):
    for _ in [(i ** 2) for i in range(n) if n > i]: print(_)

def main():
    n = int(input())
    assert(n > 0 and n < 21)
    print_square_of_sequence(n)

if __name__ == "__main__":
    main()