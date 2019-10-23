'''
Problem Statement: https://www.codechef.com/problems/ONP
Author: striker
'''

def transform_to_rpn(expression):
    rpn_form = list()
    stack = list()
    for _ in range(len(expression)):
        if expression[_] in ['(','+','-','*','^','/','%']:
            stack.append(expression[_])
        elif expression[_] == ')':
            optr = stack.pop()
            while optr != '(':
                rpn_form.append(optr)
                optr = stack.pop()
        else:
            rpn_form.append(expression[_])
    return rpn_form

def main():
    test = int(input())
    for _ in range(test):
        expression = input()
        print("".join(transform_to_rpn(expression)))


if __name__ == "__main__":
    main()