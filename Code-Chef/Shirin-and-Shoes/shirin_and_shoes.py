'''
Problem Statement: https://www.codechef.com/INTW2020/problems/SSHOES
Author: striker
'''

from collections import Counter

def main():
    for test in range(int(input().strip())):
        n, k = tuple(map(int, input().strip().split()))
        freq_map = Counter(input().strip())
        print("{0}".format(["YES", "NO"][any(freq_map[key] % 2 or (freq_map[key] >> 1) > k for key in freq_map)]))

if __name__ == "__main__":
    main()
