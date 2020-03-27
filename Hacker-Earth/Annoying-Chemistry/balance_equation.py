'''
Problem Statement: https://www.hackerearth.com/challenges/competitive/march-circuits-20/algorithm/annoying-chemistry-f5fb9556/
Author: striker
'''

MAX_LIMIT = 100000000

def main():
    x, y, p, q = tuple(map(int, input().rstrip().split()))
    for b3 in range(1, MAX_LIMIT + 1):
        if not (p * b3) % x and not (q * b3) % y:
            b1 = (p * b3) // x
            b2 = (q * b3) // y
            break
    print("{0} {1} {2}".format(b1, b2, b3))

if __name__ == "__main__":
    main()
