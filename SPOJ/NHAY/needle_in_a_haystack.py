'''
Problem Statement: https://www.spoj.com/problems/NHAY/
Author: striker
'''

def find_needle_in_haystack(needle_length, needle, haystack):
    if len(needle) > len(haystack):
        return " "
    return "\n".join(map(str, [start for start in range((len(haystack) - len(needle)) + 1) if haystack[start: start + len(needle)] == needle]))

def main():
    while True:
        try:
            needle_length = int(input().rstrip())
            needle = input().rstrip()
            haystack = input().rstrip()
            print("{0}".format(find_needle_in_haystack(needle_length, needle, haystack)))
        except:
            break

if __name__ == "__main__":
    main()
