'''
Problem Statement: https://www.hackerrank.com/challenges/merge-the-tools/problem
Author: striker
'''

def remove_duplicates(string):
    letter_occurrences = set()
    sub_sequence = list()
    for letter in string:
        if letter in letter_occurrences:
            continue
        letter_occurrences.add(letter)
        sub_sequence.append(letter)
    return "".join(sub_sequence)

def merge_the_tools(my_string, k):
    total_sub_segment = int(len(my_string) / k)
    sub_segment_len = int(len(my_string) / total_sub_segment)
    start = 0
    end = sub_segment_len
    while not start == len(my_string):
        sub_sequence = remove_duplicates(my_string[start: end])
        print("{}".format(sub_sequence))
        start = end
        end += sub_segment_len


def main():
    my_string = input().rstrip()
    k = int(input().rstrip())
    merge_the_tools(my_string, k)

if __name__ == "__main__":
    main()
