'''
Problem Statement: https://www.codechef.com/problems/ALTARAY
Author: striker
'''

def find_longest_alternating_sequence(sequence):
    dp = [1] * len(sequence)
    i = len(sequence) - 2
    while i >= 0:
        if sequence[i] > 0 and sequence[i + 1] < 0 or sequence[i] < 0 and sequence[i + 1] > 0:
            dp[i] = dp[i + 1] + 1
        i -= 1
    return " ".join(map(str,dp))


def main():
    test = int(input())
    for _ in range(test):
        n = int(input())
        seq = list(map(int,input().split()))
        print(find_longest_alternating_sequence(seq))
    
if __name__ == "__main__":
    main()

