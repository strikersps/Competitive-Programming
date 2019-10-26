'''
Problem Statement: https://www.spoj.com/problems/FASHION/
Author: striker
'''

def main():
    test = int(input())
    assert(test > 0)
    for t in range(test):
        n = int(input())
        assert(n > 0)
        hotness_men = sorted(list(map(int,input().split())))
        hotness_women = sorted(list(map(int,input().split())))
        print(sum([(hotness_men[i] * hotness_women[i]) for i in range(n) if (hotness_men[i] != 0 and hotness_women[i] != 0)]))

if __name__ == "__main__":
    main()