"""
Problem Statement: https://www.hackerrank.com/challenges/py-collections-namedtuple/problem
Author: striker
"""

from collections import namedtuple

def main():
    total_students = int(input().strip())
    Student = namedtuple('Student', input().strip().split())
    print(f'{sum([int((Student._make(input().strip().split())).MARKS) for _ in range(total_students)]) / total_students:0.2f}')

if __name__ == "__main__":
    main()