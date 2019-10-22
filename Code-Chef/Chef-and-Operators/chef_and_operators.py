'''
Problem Statement: https://www.codechef.com/problems/CHOPRT
Author: striker
'''

def main():
    test = int(input())
    for _ in range(test):
        a,b = tuple(map(int,input().split()))
        if a == b:
            print("=")
        elif a > b:
            print(">")
        else:
            print("<")

if __name__ == "__main__":
    main()