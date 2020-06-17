"""
Problem Statement: Refer to readme.md file.
Author: striker
"""

def generate_fibonacci_sequence(n):
    fibonacci_sequence = list()
    fibonacci_sequence.append(0)
    if n > 1:
        fibonacci_sequence.append(1)
        for index in range(2, n):
            fibonacci_sequence.append(fibonacci_sequence[index - 1] + fibonacci_sequence[index - 2])
    return fibonacci_sequence

def main():
    n = int(input().strip())
    fibonacci_sequence = generate_fibonacci_sequence(n)
    s_n = 3
    for index in range(1, n):
        s_n += (fibonacci_sequence[index] * fibonacci_sequence[index])
    print(s_n)

if __name__ == "__main__":
    main()
