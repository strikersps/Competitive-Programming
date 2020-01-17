'''
Problem Statement: Refer to the readme.md or the Problem-Statement.jpeg in the current directory.
Author: striker
'''

def main():
    for test in range(int(input().rstrip())):
        n = int(input())
        sequence = list(map(int, input().rstrip().split()))
        non_repeated_element = 0
        for data in sequence:
            non_repeated_element ^= data
        print("{}".format(non_repeated_element))

if __name__ == "__main__":
    main()
