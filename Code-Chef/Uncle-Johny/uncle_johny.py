'''
Problem Statement: https://www.codechef.com/problems/JOHNY
Author: striker
'''

def binary_search(song_length, start, end, search_data):
    if start <= end:
        mid = ((end - start) >> 1) + start
        if search_data == song_length[mid]:
            return mid
        elif search_data > song_length[mid]:
            return binary_search(song_length, mid + 1, end, search_data)
        else:
            return binary_search(song_length, start, mid - 1, search_data)
    return -1

def main():
    for test in range(int(input().rstrip())):
        n = int(input())
        song_length = list(map(int, input().rstrip().split()))
        uncle_johny_song_length = song_length[int(input()) - 1]
        found_index = binary_search(sorted(song_length), 0, n - 1, uncle_johny_song_length)
        if not (-1 == found_index):
            print("{}".format(found_index + 1))
        else:
            print("{}".format(-1))

if __name__ == "__main__":
    main()


