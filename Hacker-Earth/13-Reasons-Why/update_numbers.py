'''
Problem Statement: https://www.hackerearth.com/practice/python/getting-started/input-and-output/practice-problems/algorithm/its-easy-1/
Author: striker
'''

def main():
    a, b, c = tuple(map(int, input().rstrip().split()))
    b, a = a, b
    a *= c
    b += c
    print("{} {}".format(a, b))

if __name__ == "__main__":
    main()
