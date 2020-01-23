'''
Problem Statement: https://www.hackerrank.com/challenges/list-comprehensions/problem
Author: striker
'''

def main():
    x = int(input()); y = int(input()); z = int(input()); n = int(input())
    print("{}".format([[i, j, k] for i in range(x + 1) for j in range(y + 1) for k in range(z + 1) if not i + j + k == n]))

if __name__ == "__main__":
    main()
