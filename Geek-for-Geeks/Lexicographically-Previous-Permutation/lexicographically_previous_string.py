'''
Problem Statement: https://practice.geeksforgeeks.org/problems/lexicographically-previous-permutation/0
Author: striker
'''

def previous_permutation(word):
    word_len = len(word) - 1
    start = word_len
    while start > 0 and word[start - 1] <= word[start]:
        start -= 1
    if not start:
        return None
    end = word_len
    while word[end] >= word[start - 1]:
        end -= 1
    word[start - 1], word[end] = word[end], word[start - 1]
    end = word_len
    while start < end:
        word[start], word[end] = word[end], word[start]
        start += 1; end -= 1
    return "".join(word)

def main():
    for test in range(int(input().rstrip())):
        word = input().rstrip()
        rearranged_word = previous_permutation(list(word))
        if rearranged_word == None:
            print("-1")
            continue
        print(rearranged_word)

if __name__ == "__main__":
    main()
