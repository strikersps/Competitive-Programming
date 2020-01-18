'''
Problem Statement: https://www.codechef.com/problems/SUBGCD/
Author: striker
'''

def compute_gcd(a, b):
    if not b:
        return a
    elif not a:
        return b
    return compute_gcd(b, a % b)

def compute_subarray_length(data):
    seq_gcd = 0
    for index in range(len(data)):
        seq_gcd = compute_gcd(data[index], seq_gcd)
    if 1 == seq_gcd:
        return len(data)
    return -1

def main():
    for test in range(int(input().rstrip())):
        n = int(input())
        seq_data = list(map(int, input().rstrip().split()))
        print("{}".format(compute_subarray_length(seq_data)))

if __name__ == "__main__":
    main()
