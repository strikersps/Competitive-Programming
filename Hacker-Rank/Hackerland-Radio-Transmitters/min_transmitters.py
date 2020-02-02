'''
Problem Statement: https://www.hackerrank.com/challenges/hackerland-radio-transmitters/problem
Author: striker
'''

def compute_min_transmitter_installment(location, total_houses, transmitter_range):
    min_transmitter_installed = i = 0
    while i < total_houses:
        j = i + 1
        '''
        The following while loop finds out the house in which the transmitter should be installed.
        '''
        while j < total_houses and location[j] - location[i] <= transmitter_range:
            j += 1
        min_transmitter_installed += 1
        i = j
        '''
        The following while loop finds the last house which is going to receive the signal from the transmitter installed at location[j - 1] house.
        '''
        while i < total_houses and location[i] - location[j - 1] <= transmitter_range:
            i += 1
    return min_transmitter_installed

def main():
    total_houses, transmitter_range = tuple(map(int, input().rstrip().split()))
    print("{}".format(compute_min_transmitter_installment(sorted(list(map(int, input().rstrip().split()))), total_houses, transmitter_range)))

if __name__ == "__main__":
    main()
