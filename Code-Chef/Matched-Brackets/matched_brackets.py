'''
Problem Statement: https://www.codechef.com/ZCOPRAC/problems/ZCO12001
Author: striker
'''

def matched_brackets(bracket_sequence):
    open_cnt = max_depth = max_number_of_symbols = number_of_symbols = 0
    for index, bracket in enumerate(bracket_sequence):
        number_of_symbols += 1
        if bracket == 1:
            open_cnt += 1
            if open_cnt > max_depth:
                max_depth = open_cnt
                index_depth = index
        else:
            open_cnt -= 1
            if not open_cnt:
                if number_of_symbols > max_number_of_symbols:
                    max_number_of_symbols = number_of_symbols
                    index_max_symbols = index - (max_number_of_symbols - 1)
                number_of_symbols = 0
    return (max_depth, index_depth + 1, max_number_of_symbols, index_max_symbols + 1)

def main():
    n = int(input().strip())
    bracket_sequence = list(map(int, input().strip().split()))
    answer = matched_brackets(bracket_sequence)
    print(f"{answer[0]} {answer[1]} {answer[2]} {answer[3]}")

if __name__ == "__main__":
    main()
