'''
Problem Statement: https://www.spoj.com/problems/MMASS/
Author: striker
'''

molecular_mass_of_atom = {'H' : 1, 'C' : 12, 'O' : 16} # Dictionary of molecular mass of an atom

def compute_molecular_mass(molecular_formula):
    stack = list()
    for data in molecular_formula:
        if data == ')':
            intermediate_mass = 0
            for index in range(len(stack) - 1, -1, -1):
                if stack[index] == ord('('):
                    del stack[index]
                    break
                intermediate_mass += stack.pop()
            stack.append(intermediate_mass)
            continue
        if data == '(':
            stack.append(ord('('))
            continue
        if data >= '2' and data <= '9':
            stack[-1] *= int(data)
            continue
        stack.append(molecular_mass_of_atom[data])
    return sum(stack)

def main():
    print("{0}".format(compute_molecular_mass(input().rstrip())))

if __name__ == "__main__":
    main()
