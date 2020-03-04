'''
Problem Statement: https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/mojtaba-prepares-contest-29b2a044/description/
Author: striker
'''

def main():
    for test in range(int(input().rstrip())):
        cost_green, cost_blue = tuple(map(int, input().rstrip().split()))
        count_first = count_second = 0
        for _ in range(int(input().rstrip())):
            solved_problem = list(map(int, input().rstrip().split()))
            if not solved_problem[0] and not solved_problem[1]:
                continue
            if not solved_problem[0] and solved_problem[1]:
                count_second += 1
            elif solved_problem[0] and not solved_problem[1]:
                count_first += 1
            else:
                count_first += 1; count_second += 1
        if count_first > count_second:
            tot_cost = (count_first * cost_green) + (count_second * cost_blue) if cost_green < cost_blue else (count_first * cost_blue) + (count_second * cost_green)
        else:
            tot_cost = (count_first * cost_blue) + (count_second * cost_green) if cost_green < cost_blue else (count_first * cost_green) + (count_second) * (cost_blue)
        print("{}".format(tot_cost))

if __name__ == "__main__":
    main()
