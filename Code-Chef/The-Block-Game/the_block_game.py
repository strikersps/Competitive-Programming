'''
Problem Statement: https://www.codechef.com/problems/PALL01
Author: striker
'''

def main():
    test = int(input())
    for _ in range(test):
        number_base10 = input()
        if number_base10 == number_base10[::-1]:
            print("wins")
        else:
            print("losses")

if __name__ == "__main__":
    main()