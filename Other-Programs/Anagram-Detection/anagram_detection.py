'''
Problem Statement: Refer to the readme.md file.
Author: striker
'''

def check_anagram(string1, string2):
    if not len(string1) == len(string2):
        return False
    freq_map = [0] * 26
    is_anagram = True
    for alphabet in string1:
        freq_map[ord(alphabet) - ord('a')] += 1
    for alphabet in string2:
        if not freq_map[ord(alphabet) - ord('a')]:
            is_anagram = False
            break
        freq_map[ord(alphabet) - ord('a')] -= 1
    return is_anagram

def main():
    for test in range(int(input().strip())):
        print("YES" if check_anagram(input().strip(), input().strip()) else "NO")

if __name__ == "__main__":
    main()
