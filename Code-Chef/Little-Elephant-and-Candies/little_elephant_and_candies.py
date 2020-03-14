'''
Problem Statement: https://www.codechef.com/problems/LECANDY
Author: striker
'''

def main():
    for test in range(int(input().rstrip())):
        tot_elephants, tot_candies = tuple(map(int, input().rstrip().split()))
        print("{0}".format("Yes" if sum(list(map(int, input().rstrip().split()))) <= tot_candies else "No"))

if __name__ == "__main__":
    main()
