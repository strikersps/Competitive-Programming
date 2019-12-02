"""
Problem Statement: https://www.hackerrank.com/challenges/new-year-chaos/problem
Author: striker
"""

def compute_min_bribes(final_state):
    min_bribe = 0
    is_chaotic = False
    for index in range((len(final_state) - 1),-1,-1):
        if not final_state[index] == (index + 1):
            if final_state[index - 1] == (index + 1):
                min_bribe += 1
                final_state[index - 1], final_state[index] = final_state[index], final_state[index - 1]
            elif final_state[index - 2] == (index + 1):
                min_bribe += 2
                final_state[index - 2], final_state[index - 1] = final_state[index - 1], final_state[index - 2]
                final_state[index], final_state[index - 1] = final_state[index - 1], final_state[index]
            else:
                is_chaotic = True
                break
    if not is_chaotic:
        return min_bribe
    else:
        return "Too chaotic"


def main():
    test = int(input())
    for t in range(test):
        n = int(input())
        final_state = list(map(int,input().rstrip().split()))
        print(compute_min_bribes(final_state))

if __name__ == "__main__":
    main()