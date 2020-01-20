'''
Problem Statement: Refer to the readme.md.
Author: striker
'''

def merge_sort(sequence, start, end):
    if start < end:
        mid = ((end - start) >> 1) + start
        merge_sort(sequence, start, mid)
        merge_sort(sequence, mid + 1, end)
        merge_data(sequence, start, mid, end)

def merge_data(sequence, start, mid, end):
    left_size = (mid - start) + 1
    right_size = end - mid;
    left_data = [data for data in sequence[start: mid + 1]]
    right_data = [data for data in sequence[mid + 1: end + 1]]
    i = j = 0
    for k in range(start, end + 1):
        if i == 1 + (mid - start):
            sequence[k] = right_data[j]
            j += 1
        elif j == (end - mid):
            sequence[k] = left_data[i]
            i += 1
        elif not comparator(left_data[i], right_data[j]):
            sequence[k] = left_data[i]
            i += 1
        else:
            sequence[k] = right_data[j]
            j += 1

def comparator(a, b):
    if a + b > b + a:
        return False
    return True

def compute_largest_number(sequence):
    if any(list(map(int, sequence))):
        merge_sort(sequence, 0, len(sequence) - 1)
        return "".join(sequence)
    return "0"

def main():
    for test in range(int(input().rstrip())):
        n = int(input())
        print("{}".format(compute_largest_number(input().rstrip().split())))

if __name__ == "__main__":
    main()
