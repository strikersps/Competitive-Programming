'''
Problem Statement: https://www.hackerrank.com/challenges/symmetric-difference/problem?h_r=next-challenge&h_v=zen
Author: striker
'''

def symmetric_diff(m,n):
    symmetric_diff = list((m.difference(n)).union(n.difference(m)))
    symmetric_diff.sort()
    for data in symmetric_diff:
        print(data)


def main():
    m_len = int(input())
    m = list(map(int,input().split()))
    n_len = int(input())
    n = list(map(int,input().split()))
    symmetric_diff(set(m),set(n))

if __name__ == "__main__":
    main()