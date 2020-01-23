'''
Problem Statement: https://www.hackerrank.com/challenges/no-idea/problem
Author: striker
'''

def compute_total_happiness(number_list, set_a, set_b):
    total_happiness = 0
    for number in number_list:
        if number in set_a:
            total_happiness += 1
        elif number in set_b:
            total_happiness -= 1
    return total_happiness

def main():
    n, m = tuple(map(int,input().split()))
    print("{}".format(compute_total_happiness(list(map(int, input().rstrip().split())), set(map(int, input().rstrip().split())), set(map(int, input().rstrip().split())))))

if __name__ == "__main__":
    main()
