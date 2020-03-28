'''
Problem Statement: https://www.codechef.com/problems/ONP
Author: striker
'''

def transform_to_rpn(expression):
    rpn_form = list()
    stack = list()
    for index in range(len(expression)):
        if expression[index] in ['(','+','-','*','^','/','%']:
            stack.append(expression[index])
            continue
        if expression[index] == ')':
            optr = stack.pop()
            while optr != '(':
                rpn_form.append(optr)
                optr = stack.pop()
            continue
        rpn_form.append(expression[index])
    while stack:
        rpn_form.append(stack.pop())
    return rpn_form

def main():
    for test in range(int(input().rstrip())):
        print("".join(transform_to_rpn(input().rstrip())))

if __name__ == "__main__":
    main()
