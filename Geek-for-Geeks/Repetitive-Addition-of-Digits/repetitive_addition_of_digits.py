'''
Problem Statement: https://practice.geeksforgeeks.org/problems/repetitive-addition-of-digits/0
Author: striker
'''

def main():
    for test in range(int(input().rstrip())):
        n = int(input().rstrip())
        print("{0}".format("9" if not n % 9 else n % 9))

if __name__ == "__main__":
    main()
