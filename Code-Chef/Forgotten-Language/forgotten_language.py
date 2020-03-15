'''
Problem Statement: https://www.codechef.com/problems/FRGTNLNG
Author: striker
'''

def main():
    for test in range(int(input().rstrip())):
        n, k = tuple(map(int, input().rstrip().split()))
        frgt_lang_dict = input().rstrip().split() # List of words in a forgotten language
        word_present = set() # Store the word from forgotten language which is present in phrase, to avoid repetition set() is used.
        for _ in range(k):
            phrase = input().rstrip().split() # List of words in a phrase.
            for word in phrase[1: ]: # iterating over the list after slicing it out because of the integer present i.e. L
                if word in frgt_lang_dict: # Check whether the phrase word is in forgotten language.
                    word_present.add(word) # If condition is true add the word to word_present set.
                    continue
        print("{0}".format(" ".join(["YES" if word in word_present else "NO" for word in frgt_lang_dict]).rstrip())) # Print the output in required format.
if __name__ == "__main__":
    main()
