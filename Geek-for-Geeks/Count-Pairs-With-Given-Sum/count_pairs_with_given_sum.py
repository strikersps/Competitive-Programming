'''
Problem Statement: https://www.geeksforgeeks.org/count-pairs-with-given-sum/
Author: striker
'''

from collections import Counter

def count_pairs_with_given_sum(sequence, freq_map, k):
    tot_pairs = 0
    for integer in sequence:
        tot_pairs += freq_map[k - integer]
        if integer == (k - integer):
            tot_pairs -= 1
    return tot_pairs >> 1

def main():
    for test in range(int(input().rstrip())):
        n, k = tuple(map(int, input().rstrip().split()))
        sequence = list(map(int, input().rstrip().split()))
        print("{0}".format(count_pairs_with_given_sum(sequence, Counter(sequence), k)))

if __name__ == "__main__":
    main()
