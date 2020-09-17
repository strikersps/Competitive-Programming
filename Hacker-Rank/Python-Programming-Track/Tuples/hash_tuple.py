"""
Problem Statement: https://www.hackerrank.com/challenges/python-tuples/problem
Author: striker
"""

def main():
    n = int(input().strip())
    print(hash(tuple(map(int, input().strip().split()))))

if __name__ == "__main__":
    main()