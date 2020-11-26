"""
Problem Statement: https://www.hackerrank.com/challenges/balanced-brackets/problem
Author: striker
"""

from collections import deque

def check_balance_bracket(expression: str) -> bool:
    is_balanced = True
    bracket_stack = deque()
    for bracket in expression:
        if bracket == '(' or bracket == '[' or bracket == '{':
            bracket_stack.append(bracket)
            continue
        if not bracket_stack or (bracket == ')' and bracket_stack[-1] != '(') or (bracket == ']' and bracket_stack[-1] != '[') or (bracket == '}' and bracket_stack[-1] != '{'):
            is_balanced = False
            break
        bracket_stack.pop()
    if bracket_stack:
        is_balanced = False
    return is_balanced

def main():
    for _ in range(int(input().strip())):
        print('YES' if check_balance_bracket(input().strip()) else 'NO')

if __name__ == "__main__":
    main()