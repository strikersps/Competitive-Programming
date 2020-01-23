'''
Problem Statement: Refer to the readme.md file.
Author: striker
'''

def check_anagram(src, dst):
    if not len(src) == len(dst):
        return False
    freq_map = [0] * 26
    is_anagram = True
    for alphabet in src:
        freq_map[ord(alphabet) - ord('a')] += 1
    for alphabet in dst:
        if not freq_map[ord(alphabet) - ord('a')]:
            is_anagram = False
            break
        freq_map[ord(alphabet) - ord('a')] -= 1
    return is_anagram

def main():
    for test in range(int(input().rstrip())):
        src = input()
        dst = input()
        if not check_anagram(src, dst):
            print("{}".format("NO"))
        else:
            print("{}".format("YES"))

if __name__ == "__main__":
    main()
