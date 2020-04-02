'''
Problem Statement: https://www.codechef.com/CHPTRS01/problems/FUNRUN
Author: striker
'''

def main():
    for test in range(int(input().strip())):
        n = int(input().strip())
        print("{0}".format("NO" if max(list(map(int, input().strip().split()))) == max(list(map(int, input().strip().split()))) else "YES"))

if __name__ == "__main__":
    main()
