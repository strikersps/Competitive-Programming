'''
Problem Statement: https://www.hackerrank.com/challenges/the-minion-game/problem
Author: striker
'''

vowels = ['A', 'E', 'I', 'O', 'U']

def main():
    word = input().rstrip()
    stuart_points = 0
    kevin_points = 0
    for index, letter in enumerate(word):
        if letter in vowels:
            kevin_points += len(word) - index
            continue
        stuart_points += len(word) - index
    if stuart_points == kevin_points:
        print("{}".format("Draw"))
    elif stuart_points > kevin_points:
        print("{} {}".format("Stuart", stuart_points))
    else:
        print("{} {}".format("Kevin", kevin_points))

if __name__ == "__main__":
    main()
