'''
Problem Statement: https://www.hackerrank.com/challenges/counter-game/problem
Author: striker
'''

def count_set_bits(n):
    set_bit_count = 0
    while n:
        set_bit_count += 1
        n &= (n - 1)
    return set_bit_count

def play_counter_game(n):
    return count_set_bits(n - 1)

def main():
    for test in range(int(input().rstrip())):
        if play_counter_game(int(input().rstrip())) % 2:
            print("{}".format("Louise"))
        else:
            print("{}".format("Richard"))

if __name__ == "__main__":
    main()
