'''
Problem Statement: https://www.codechef.com/problems/TRAINSET
Author: striker
'''

from collections import defaultdict

def main():
    for t in range(int(input())):
        spam_map = defaultdict(list)
        for w in range(int(input())):
            word, value = tuple(input().rstrip().split())
            spam_map[word].append(int(value))
        max_items = 0
        for word, values in spam_map.items():
            max_items += max(values.count(0),values.count(1))
        spam_map.clear()
        print(max_items)

if __name__ == "__main__":
    main()
