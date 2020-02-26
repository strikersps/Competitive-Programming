'''
Problem Statement: https://www.codechef.com/problems/UWCOI20A
Author: striker
'''

def main():
    for test in range(int(input().rstrip())):
        print("{}".format(max([int(input().rstrip()) for _ in range(int(input().rstrip()))])))

if __name__ == "__main__":
    main()
