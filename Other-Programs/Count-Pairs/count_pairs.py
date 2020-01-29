'''
Problem Statement: Refer to the readme.md file.
Author: striker
'''

def compute_pairs(sequence, n, k):
    tot_pairs = 0
    start = 0; end = n - 1
    while start < end:
        if sequence[start] + sequence[end] < k:
            tot_pairs += (end - start)
            start += 1
            continue
        end -= 1
    return tot_pairs

def main():
    for test in range(int(input().rstrip())):
        n, k = tuple(map(int, input().rstrip().split()))
        print("{}".format(compute_pairs(sorted(list(map(int, input().rstrip().split()))), n, k)))

if __name__ == "__main__":
    main()
