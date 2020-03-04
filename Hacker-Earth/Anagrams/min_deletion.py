'''
Problem Statement: https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/anagrams-651/description/
Author: striker
'''

from collections import Counter

def compute_min_deletions(word1, word2):
    freq_map_word1 = Counter(word1)
    freq_map_word2 = Counter(word2)
    not_present = ((freq_map_word1 - freq_map_word2) + (freq_map_word2 - freq_map_word1))
    min_deletions = 0
    for key in not_present:
        min_deletions += not_present[key]
    return min_deletions

def main():
    for test in range(int(input().rstrip())):
        print("{}".format(compute_min_deletions(input().rstrip(), input().rstrip())))

if __name__ == "__main__":
    main()
