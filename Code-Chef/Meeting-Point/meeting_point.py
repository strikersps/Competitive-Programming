'''
Problem Statement: https://www.codechef.com/problems/ICM2008
Author: striker
'''

def main():
    for test in range(int(input().rstrip())):
        a, b, c, d = tuple(map(int, input().rstrip().split()))
        if a == b:
            print("{}".format("YES"))
        elif c == d:
            print("{}".format("YES" if a == b else "NO"))
        else:
            print("{}".format("YES" if not abs(a - b) % abs(c - d) else "NO"))

if __name__ == "__main__":
    main()
