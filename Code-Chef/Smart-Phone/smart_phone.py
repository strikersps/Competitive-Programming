'''
Problem Statement: https://www.codechef.com/LRNDSA01/problems/ZCO14003
Author: striker
'''

def compute_maximum_revenue(n, budget_list):
    max_revenue = 0
    for index, budget in enumerate(budget_list):
        max_revenue = max(max_revenue, budget * (n - index))
    return max_revenue

def main():
    n = int(input().strip())
    print("{0}".format(compute_maximum_revenue(n, sorted([int(input().strip()) for _ in range(n)]))))

if __name__ == "__main__":
    main()
