'''
Problem Statement: https://www.codechef.com/problems/SNUG_FIT
Author: striker
'''

def main():
    for test in range(int(input().rstrip())):
        n = int(input().rstrip())
        max_sum = 0
        for x1, x2 in zip(sorted(list(map(int, input().rstrip().split()))), sorted(list(map(int, input().rstrip().split())))):
            max_sum += min(x1, x2)
        print("{}".format(max_sum))

if __name__ == "__main__":
    main()
