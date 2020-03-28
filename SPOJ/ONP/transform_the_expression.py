'''
Problem Statement: https://www.codechef.com/problems/ONP
Author: striker
'''

def compute_operator_precendence(operator):
    precedence_dict = dict()
    precedence_dict['^'] = 5
    precedence_dict['/'] = 4
    precedence_dict['*'] = 3
    precedence_dict['-'] = 2
    precedence_dict['+'] = 1
    return precedence_dict[operator]

def transform_to_rpn(expression):
    rpn_form = list()
    stack = list()
    for token in expression:
        if token == '(':
            stack.append(token)
            continue
        if token in ['+', '-', '*', '^', '/']:
            while stack and stack[-1] != '(' and compute_operator_precendence(stack[-1]) > compute_operator_precendence(token):
                popped_data = stack.pop()
                while popped_data != '(':
                    rpn_form.append(popped_data)
                    if stack:
                        popped_data = stack.pop()
                        continue
                    break
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
