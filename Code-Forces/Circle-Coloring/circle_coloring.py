"""
Problem Statement: https://codeforces.com/problemset/problem/1408/A
Author: striker
"""

def generate_required_sequence(n: int, sequence1: list, sequence2: list, sequence3: list) -> str:
    resultant_sequence = list()
    for index, v in enumerate(zip(sequence1, sequence2, sequence3)):
        if not index:
            resultant_sequence.append(v[0])
            continue
        if resultant_sequence[0] != v[0] and resultant_sequence[index - 1] != v[0]:
            resultant_sequence.append(v[0])
            continue
        if resultant_sequence[0] != v[1] and resultant_sequence[index - 1] != v[1]:
            resultant_sequence.append(v[1])
            continue
        resultant_sequence.append(v[2])
    return ' '.join(list(map(str, resultant_sequence)))



def main():
    for _ in range(int(input().strip())):
        print(generate_required_sequence(int(input().strip()), list(map(int, input().strip().split())), list(map(int, input().strip().split())), list(map(int, input().strip().split()))))

if __name__ == "__main__":
    main()