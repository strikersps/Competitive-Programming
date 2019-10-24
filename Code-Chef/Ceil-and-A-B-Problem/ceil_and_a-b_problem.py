'''
Problem Statement: https://www.codechef.com/problems/CIELAB
Author: striker
'''

def main():
    a,b = tuple(map(int,input().split()))
    print((a - b) - 1) if (a - b) % 10 == 9 else print((a - b) + 1)

if __name__ == "__main__":
    main()