'''
Problem Statement: https://www.codechef.com/problems/LAPIN
Author: striker
'''

TOTAL_NUMBER_OF_ALPHABETS = 26

def check_lapindrome(word):
    is_lapindrome = True
    freq_alphabet = [0] * TOTAL_NUMBER_OF_ALPHABETS
    mid = len(word) >> 1
    for index,val in enumerate(word):
        if index < mid:
            freq_alphabet[ord(val) - 97] += 1
        elif len(word) & 1:
            if index > mid:
                freq_alphabet[ord(val) - 97] -= 1
        else:
            freq_alphabet[ord(val) - 97] -= 1
    if len(set(freq_alphabet)) > 1:
        is_lapindrome = False
    return is_lapindrome

def main():
    test = int(input())
    for _ in range(test):
        word = input()
        if check_lapindrome(word):
            print("YES")
        else:
            print("NO")

if __name__ == "__main__":
    main()