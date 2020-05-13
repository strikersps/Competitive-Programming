'''
Problem Statement: https://www.codechef.com/problems/AMIFIB
Author: striker
'''

'''
Algorithm Explanation:
1. Compute and store all the Fibonacci Numbers till 4788 because, 4788th Fibonacii number is last number which consist of 1000 digits.
2. As Fibonacci numbers is an stricly increasing sequence i.e. after pre-computation you will have a strictly increasing sequence, that means you can use Binary-Search for each test-case and if for the case the number is present in the list print "YES" otherwise "NO".

Time-Complexity: O(n) + O(log(n)) where n = size of the sequence, i.e. 4788.

The approach above works efficiently because Python supports Big Integers but in C and C++ programming language you need to store all the Fibonacci numbers as a string and then perform the search for each test-case.
'''

fibonacii_sequence = list()
fibonacii_sequence.append(0)
fibonacii_sequence.append(1)

def compute_fibonacci_number():
    global fibonacii_sequence
    for index in range(2, 4790):
        fibonacii_sequence.append(fibonacii_sequence[index - 1] + fibonacii_sequence[index - 2])

def main():
    compute_fibonacci_number() # Pre-computation of all Fibonacci Numbers
    for test in range(int(input().rstrip())):
        number = int(input())
        if number in fibonacii_sequence:
            print("{}".format("YES"))
            continue
        print("{}".format("NO"))

if __name__ == "__main__":
    main()
