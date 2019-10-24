'''
Problem Statement: https://www.codechef.com/problems/MDL
Author: striker
'''

def main():
    test = int(input())
    for _ in range(test):
        n = int(input())
        sequence = list(map(int,input().split()))
        max_val = max(sequence) ; min_val = min(sequence)
        max_val_index = sequence.index(max_val) ; min_val_index = sequence.index(min_val)
        if max_val_index < min_val_index:
            print(str(max_val) + " " + str(min_val))
        else:
            print(str(min_val) + " " + str(max_val))

if __name__ == "__main__":
    main()