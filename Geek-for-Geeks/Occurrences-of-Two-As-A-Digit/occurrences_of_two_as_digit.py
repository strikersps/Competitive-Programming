'''
Problem Statement: https://practice.geeksforgeeks.org/problems/occurences-of-2-as-a-digit/1
Author: striker
'''

def number_of_two_in_range(limit):
    number_count = 0
    for number in range(limit + 1):
        number_count += list(str(number)).count('2')
    return number_count

def main():
    for test in range(int(input().rstrip())):
        limit = int(input().rstrip())
        print("{0}".format(number_of_two_in_range(limit)))

if __name__ == "__main__":
    main()
