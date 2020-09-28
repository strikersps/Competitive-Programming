"""
Problem Statement: https://www.hackerrank.com/challenges/py-collections-deque/problem
Author: striker
"""

from collections import deque

def main():
    data = deque()
    for _ in range(int(input().strip())):
        operation_detail = input().strip().split()
        if operation_detail[0] == 'append':
            data.append(operation_detail[1])
        if operation_detail[0] == 'appendleft':
            data.appendleft(operation_detail[1])
        if operation_detail[0] == 'pop':
            data.pop()
        if operation_detail[0] == 'popleft':
            data.popleft()
    print(' '.join(data))

if __name__ == "__main__":
    main()