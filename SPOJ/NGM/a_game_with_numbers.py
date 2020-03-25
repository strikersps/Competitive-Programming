'''
Problem Statement: https://www.spoj.com/problems/NGM/
Author: striker
'''

def main():
    number = int(input().rstrip())
    if number % 10:
        print("{0}\n{1}".format("1", number % 10))
    else:
        print("{0}".format("2"))

if __name__ == "__main__":
    main()
