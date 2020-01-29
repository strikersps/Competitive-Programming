'''
Problem Statement: https://www.hackerrank.com/challenges/kangaroo/problem
Author: striker
'''

def main():
    x1, v1, x2, v2 = tuple(map(int, input().rstrip().split()))
    if v1 <= v2:
        print("{}".format("NO"))
    else:
        if not (x2 - x1) % (v1 - v2):
            print("{}".format("YES"))
        else:
            print("{}".format("NO"))

if __name__ == "__main__":
    main()
