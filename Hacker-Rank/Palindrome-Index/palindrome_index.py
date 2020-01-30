'''
Problem Statement: https://www.hackerrank.com/challenges/palindrome-index/problem
Author: striker
'''

def find_delete_index(string_data):
    found_index = -1
    start = 0; end = len(string_data) - 1
    while start < end:
        if string_data[start] != string_data[end]:
            sub_string = string_data[start: end]
            if not sub_string == sub_string[: : -1]:
                found_index = start
                break
            found_index = end
            break
        start += 1; end -= 1
    return found_index

def main():
    for test in range(int(input().rstrip())):
        string_data = input().rstrip()
        if string_data == string_data[: : -1]:
            print("{}".format("-1"))
            continue
        print("{}".format(find_delete_index(string_data)))

if __name__ == "__main__":
    main()
