'''
Problem Statement: https://www.hackerrank.com/challenges/no-idea/problem
Author: striker
'''

def compute_total_happiness(n,set_a,set_b):
    total_happiness = 0
    for data in n:
        if data in set_a:
            total_happiness += 1
        elif data in set_b:
            total_happiness -= 1
    return total_happiness

def main():
    n,m = tuple(map(int,input().split()))
    list_of_integers = list(map(int,input().split()))
    set_a = set(map(int,input().split()))
    set_b = set(map(int,input().split()))
    print(compute_total_happiness(list_of_integers,set_a,set_b))

if __name__ == "__main__":
    main()