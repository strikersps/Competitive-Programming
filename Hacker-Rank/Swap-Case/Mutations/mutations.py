'''
Problem Statement: https://www.hackerrank.com/challenges/python-mutations/problem
Author: striker
'''

def mutate_string(string, position, replacement_char):
    string_list = list(string) # Converted the list into string so that I can change the characters of the string as list are mutable objects, string is not.
    string_list[position] = replacement_char
    return "".join(string_list)

def main():
    s = input().strip()
    position, replacement_char = input().rstrip().split()
    print("{0}".format(mutate_string(s, int(position), replacement_char)))

if __name__ == "__main__":
    main()
