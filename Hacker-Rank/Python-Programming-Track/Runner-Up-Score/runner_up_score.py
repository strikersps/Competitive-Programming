'''
Problem Statement: https://www.hackerrank.com/challenges/find-second-maximum-number-in-a-list/problem
Author: striker
'''

def compute_second_runner_up(score_sheet):
    max_score = max(score_sheet)
    runner_up = -101
    for score in score_sheet:
        if score < max_score and score > runner_up:
            runner_up = score
    return runner_up

def main():
    n = int(input().rstrip())
    print("{}".format(compute_second_runner_up(list(map(int, input().rstrip().split())))))

if __name__ == "__main__":
    main()
