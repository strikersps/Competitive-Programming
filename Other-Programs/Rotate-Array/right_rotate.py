'''
Problem Statement: Refer to the readme.md file.
Author: striker
'''

def right_rotate_list(sequence, k):
    return " ".join(sequence[: k: ][: : -1] + sequence[k : len(sequence):][: : -1])

def main():
     for test in range(int(input().rstrip())):
         n, k = tuple(map(int, input().rstrip().split()))
         k %= n
         print("{}".format(right_rotate_list(input().rstrip().split()[: : -1], k)))

if __name__ == "__main__":
    main()
