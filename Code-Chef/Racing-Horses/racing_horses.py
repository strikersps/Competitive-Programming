'''
Problem Statement: https://www.codechef.com/problems/HORSES
Author: striker
'''

def main():
    for test in range(int(input().rstrip())):
        n = int(input())
        horse_skill = sorted(list(map(int, input().rstrip().split())))
        min_diff = int(1e9)
        for index in range(len(horse_skill) - 1):
            curr_diff = horse_skill[index + 1] - horse_skill[index]
            if curr_diff < min_diff:
                min_diff = curr_diff
        print("{}".format(min_diff))

if __name__ == "__main__":
    main()
