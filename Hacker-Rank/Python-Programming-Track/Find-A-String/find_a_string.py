'''
Problem Statement: https://www.hackerrank.com/challenges/find-a-string/problem
Author: striker
'''

def count_substring(string, substring):
    if not substring in string:
        return 0
    return sum([1 for start_index in range((len(string) - (len(substring)) + 1)) if string[start_index: len(substring) + start_index] == substring])

def main():
    print("{}".format(count_substring(input().rstrip(), input().rstrip())))

if __name__ == "__main__":
    main()
