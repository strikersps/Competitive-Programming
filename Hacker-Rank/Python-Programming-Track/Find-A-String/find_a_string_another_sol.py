'''
Problem Statement: https://www.hackerrank.com/challenges/find-a-string/problem
Author: striker
'''

def count_substring(string, substring):
    if not substring in string:
        return 0
    substring_count = 0
    index = 0
    while True:
        index = string.find(substring, index)
        if index == -1:
            break
        index += 1
        substring_count += 1
    return substring_count

def main():
    print("{}".format(count_substring(input().rstrip(), input().rstrip())))

if __name__ == "__main__":
    main()
