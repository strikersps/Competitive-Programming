'''
Problem Statement: https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/is-zoo-f6f309e7/
Author: striker
'''

def main():
    word = input().rstrip()
    count_z = word.count('z')
    count_o = word.count('o')
    print("{}".format("Yes" if count_z << 1 == count_o else "No"))

if __name__ == "__main__":
    main()
