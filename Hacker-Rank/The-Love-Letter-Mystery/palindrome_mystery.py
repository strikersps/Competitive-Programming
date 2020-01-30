'''
Problem Statement: https://www.hackerrank.com/challenges/palindrome-index/problem
Author: striker
'''

def compute_min_operations(string_data):
    min_ops = 0
    start = 0; end = len(string_data) - 1
    while start < end:
        if string_data[start] != string_data[end]:
            min_ops += abs(ord(string_data[start]) - ord(string_data[end]))
        start += 1; end -= 1
    return min_ops

def main():
    for test in range(int(input().rstrip())):
        print("{}".format(compute_min_operations(input().rstrip())))

if __name__ == "__main__":
    main()
