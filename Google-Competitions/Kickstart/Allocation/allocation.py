'''
Problem Statement: https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d3f56
Author: striker
'''

def main():
    for test in range(1, int(input()) + 1):
        tot_houses, tot_budget = tuple(map(int, input().rstrip().split()))
        max_houses = 0
        for cost in sorted(list(map(int, input().rstrip().split()))):
            if cost <= tot_budget:
                tot_budget -= cost
                max_houses += 1
        print("Case #{0}: {1}".format(test, max_houses))

if __name__ == "__main__":
    main()
