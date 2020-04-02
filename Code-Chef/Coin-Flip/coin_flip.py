'''
Problem Statement: https://www.codechef.com/problems/CONFLIP
Author: striker
'''

def main():
    for test in range(int(input().strip())):
        number_of_games_played = int(input().strip())
        for game in range(number_of_games_played):
            initial_state, number_of_rounds, prediction = tuple(map(int, input().strip().split()))
            if not number_of_rounds % 2 or initial_state == prediction:
                print("{}".format(number_of_rounds >> 1))
                continue
            print("{}".format((number_of_rounds >> 1) + 1))

if __name__ == "__main__":
    main()

