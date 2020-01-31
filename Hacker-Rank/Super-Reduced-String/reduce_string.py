'''
Problem Statement: https://www.hackerrank.com/challenges/reduced-string/problem
Author: striker
'''

def main():
    stack = list()
    for letter in input().rstrip():
        if stack and letter == stack[-1]:
            stack.pop()
            continue
        stack.append(letter)
    if stack:
        print("".join(stack))
    else:
        print("Empty String")

if __name__ == "__main__":
    main()
