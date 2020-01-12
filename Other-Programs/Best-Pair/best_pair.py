'''
Problem Statement: https://github.com/strikersps/Competitive-Programming/blob/master/Other-Programs/Best-Pair/readme.md
Author: striker
'''

def main():
    for test in range(int(input().rstrip())):
        n = int(input())
        data_sequence = sorted(list(map(int, input().rstrip().split())))
        print("{}".format(max(data_sequence[0] * data_sequence[1], data_sequence[n - 1] * data_sequence[n - 2])))

if __name__ == "__main__":
    main()
