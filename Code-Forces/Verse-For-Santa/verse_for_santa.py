'''
Problem Statement: https://codeforces.com/problemset/problem/1279/B
Author: striker
'''

def main():
    for test in range(int(input())):
        n, time_limit = tuple(map(int, input().rstrip().split()))
        time_taken = list(map(int, input().rstrip().split()))
        skip_index = 0
        if sum(time_taken) > time_limit:
            time_elapsed = 0; max_time = 0
            for index, time in enumerate(time_taken):
                time_elapsed += time
                if time > max_time:
                    max_time = time
                    skip_index = index + 1
                if time_elapsed > time_limit:
                    break
        print(skip_index)

if __name__ == "__main__":
    main()
