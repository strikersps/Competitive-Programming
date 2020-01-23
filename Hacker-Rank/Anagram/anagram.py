'''
Problem Statement: https://www.hackerrank.com/challenges/anagram/problem
Author: striker
'''

NUMBER_OF_ALPHABETS = 26

def compute_min_characters(word):
    if len(word) % 2:
        return -1
    size = len(word) >> 1
    char_freq = [0] * NUMBER_OF_ALPHABETS
    for index in range(size):
        char_freq[ord(word[index]) - ord('a')] += 1
    for index in range(size, len(word)):
        if not char_freq[ord(word[index]) - ord('a')]:
            continue
        char_freq[ord(word[index]) - ord('a')] -= 1
    min_ops = 0
    for value in char_freq:
        min_ops += value
    return min_ops

def main():
    for test in range(int(input().rstrip())):
        print("{}".format(compute_min_characters(input())))

if __name__ == "__main__":
    main()
