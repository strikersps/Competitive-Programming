"""
Problem Statement: Refer to readme.md file.
Author: striker
"""

def reverse_words_and_swap_cases(sentence: str) -> str:
    reverse_words_with_swap_cases = list()
    for word in sentence.split()[: : -1]:
        wrd = list()
        for character in word:
            if character.islower():
                wrd.append(character.upper())
                continue
            wrd.append(character.lower())
        reverse_words_with_swap_cases.append(''.join(wrd))
    return ' '.join(reverse_words_with_swap_cases)

def main():
    print(reverse_words_and_swap_cases(input().strip()))

if __name__ == "__main__":
    main()
