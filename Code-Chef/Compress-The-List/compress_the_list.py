'''
Problem Statement: https://www.codechef.com/problems/CMPRSS
Author: striker
'''

def compress_the_list(sequence):
    compress_list = list()
    start = 0; end = 0
    subsequence_length = 1
    for index, value in enumerate(sequence):
        if 1 == subsequence_length:
            start = index
        if index < (len(sequence) - 1) and 1 == (sequence[index + 1] - sequence[index]):
            subsequence_length += 1
            continue
        end = index
        if 3 <= subsequence_length:
            compress_list.append("{}...{}".format(sequence[start], sequence[end]))
        elif 2 == subsequence_length:
            compress_list.append("{},{}".format(sequence[start], sequence[end]))
        else:
            compress_list.append("{}".format(sequence[start]))
        subsequence_length = 1
    return ",".join(compress_list)

def main():
    for test in range(int(input().rstrip())):
        n = int(input().rstrip())
        print("{}".format(compress_the_list(list(map(int, input().rstrip().split())))))

if __name__ == "__main__":
    main()
