'''
Problem Statement: https://practice.geeksforgeeks.org/problems/doctors-clinic/0
Author: striker
'''

def main():
    for test in range(int(input().rstrip())):
        n, x = tuple(map(int, input().rstrip().split()))
        print("{}".format("0" if x > 10 else (n - 1) * (10 - x)))

if __name__ == "__main__":
    main()
