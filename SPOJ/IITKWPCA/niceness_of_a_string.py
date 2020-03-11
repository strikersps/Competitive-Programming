'''
Problem Statement: https://www.spoj.com/problems/IITKWPCA/
Author: striker
'''

def main():
    for test in range(int(input().rstrip())):
        print("{0}".format(len(set(input().rstrip().split()))))

if __name__ == "__main__":
    main()
