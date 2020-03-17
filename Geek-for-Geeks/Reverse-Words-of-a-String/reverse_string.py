'''
Problem Statement: https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1
Author: striker
'''

def reverse_string(sentence):
    print(".".join([word for word in sentence.split(".")][: : -1]))

def main():
    for test in range(int(input().rstrip())):
        reverse_string(input().rstrip())

if __name__ == "__main__":
    main()
