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
        if len(word) & 1 and index == mid:
            continue
        if index < mid:
            freq_alphabet[ord(val) - 97] += 1
        else:
            freq_alphabet[ord(val) - 97] -= 1
    if len(set(freq_alphabet)) > 1:
        is_lapindrome = False
    return is_lapindrome

def main():
    for _ in range(int(input().rstrip())):
        print("{0}".format("YES" if check_lapindrome(input().rstrip()) else "NO"))

if __name__ == "__main__":
    main()
