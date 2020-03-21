'''
Problem Statement: https://practice.geeksforgeeks.org/problems/tom-and-jerry/0
Author: striker
'''

def main():
    for test in range(int(input().rstrip())):
        print("{0}".format("0" if int(input().rstrip()) % 2 else "1"))

if __name__ == "__main__":
    main()
