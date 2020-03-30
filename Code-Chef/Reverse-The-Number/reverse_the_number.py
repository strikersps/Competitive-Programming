'''
Problem Statement: https://www.codechef.com/problems/FLOW007
Author: striker
'''

def compute_reverse_number(number):
    return int(number[: : -1])

def main():
    for test in range(int(input().strip())):
        print("{0}".format(compute_reverse_number(input().strip())))

if __name__ == "__main__":
    main()
