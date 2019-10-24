'''
Problem Statement: https://www.hackerrank.com/challenges/symmetric-difference/problem
Author: striker
'''

def symmetric_diff(m,n):
    print("\n".join(list((map(str,(sorted(list(m ^ n))))))))

def main():
    set_m_len = int(input())
    set_m = set(list(map(int,input().split())))
    set_n_len = int(input())
    set_n = set(list(map(int,input().split())))
    symmetric_diff(set_m,set_n)

if __name__ == "__main__":
    main()