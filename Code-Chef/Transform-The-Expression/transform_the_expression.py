'''
Problem Statement: https://www.codechef.com/problems/ONP
Author: striker
'''

precedence_dict = {'^' : 5, '/' : 4, '*' : 3, '-' : 4, '+' : 1}

def transform_to_rpn(expression):
    rpn_form = list()
    stack = list()
    for token in expression:
        if token == '(':
            stack.append(token)
            continue
        if token in ['+', '-', '*', '^', '/']:
            while stack and stack[-1] != '(' and precedence_dict[stack[-1]] > precedence_dict[token]:
                rpn_form.append(stack.pop())
            stack.append(token)
            continue
        if token == ')':
            optr = stack.pop()
            while optr != '(':
                rpn_form.append(optr)
                optr = stack.pop()
            continue
        rpn_form.append(token)
    while stack:
        rpn_form.append(stack.pop())
    return rpn_form

def main():
    for test in range(int(input().rstrip())):
        print("".join(transform_to_rpn(input().rstrip())))

if __name__ == "__main__":
    main()
