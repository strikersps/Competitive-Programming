'''
Problem Statement: https://www.codechef.com/problems/CONFLIP
Author: striker
'''

def main():
    for test in range(int(input().rstrip())):
        number_of_games_played = int(input().rstrip())
        for game in range(number_of_games_played):
            initial_state, number_of_rounds, q = tuple(map(int, input().rstrip().split()))
            if not number_of_rounds % 2:
                print("{}".format(number_of_rounds >> 1))
            else:
                if 1 == initial_state:
                    if 1 == q:
                        print("{}".format(number_of_rounds >> 1))
                    else:
                        print("{}".format((number_of_rounds >> 1) + 1))
                else:
                    if 1 == q:
                        print("{}".format((number_of_rounds >> 1) + 1))
                    else:
                        print("{}".format(number_of_rounds >> 1))

if __name__ == "__main__":
    main()

