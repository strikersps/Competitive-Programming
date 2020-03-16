'''
Problem Statement: https://www.spoj.com/problems/JNEXT/
Author: striker
'''

def next_permutation(n, sequence):
    start = n - 1
    while start > 0 and sequence[start - 1] >= sequence[start]:
        start -= 1
    if not start:
        return False
    end = n - 1
    while sequence[end] <= sequence[start - 1]:
        end -= 1
    sequence[start - 1], sequence[end] = sequence[end], sequence[start - 1]
    end = n - 1
    while start < end:
        sequence[start], sequence[end] = sequence[end], sequence[start]
        start += 1
        end -= 1
    return True

def main():
    for test in range(int(input().rstrip())):
        n = int(input().rstrip())
        sequence = list(map(int, input().rstrip().split()))
        print("{}".format(-1 if not next_permutation(n, sequence) else "".join(list(map(str, sequence)))))

if __name__ == "__main__":
    main()
