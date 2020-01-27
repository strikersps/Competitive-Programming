'''
Problem Statement: https://www.hackerrank.com/challenges/mark-and-toys/problem
Author: striker
'''

def main():
    total_toys, mark_budget = tuple(map(int, input().rstrip().split()))
    max_toys = money_spent = 0
    for price in sorted(list(map(int, input().rstrip().split()))):
        money_spent += price
        if money_spent <= mark_budget:
            max_toys += 1
            continue
        break
    print("{}".format(max_toys))

if __name__ == "__main__":
    main()
