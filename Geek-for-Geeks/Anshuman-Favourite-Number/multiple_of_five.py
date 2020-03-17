'''
Problem Statement: https://practice.geeksforgeeks.org/problems/anshumans-favourite-number/0
Author: striker
'''

def main():
    for test in range(int(input().rstrip())):
        n = int(input().rstrip())
        print("{0}".format("YES" if not n % 5 else "NO"))

if __name__ == "__main__":
    main()
