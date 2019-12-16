'''
Problem Statement: https://www.codechef.com/DEC19B/problems/SUBSPLAY
Author: striker
'''

def compute_maximum_k(word):
    last_occurences = {}
    max_k = -1
    for i in range(len(word)):
        if(not last_occurences or not word[i] in last_occurences):
            last_occurences[word[i]] = i
            continue
        print("len(word) - i: %d" %(len(word) - i))
        print("last_occurences[word[i]]: " + str(last_occurences[word[i]]))
        max_k = max(max_k,(len(word) - i) + last_occurences[word[i]])
        print("max_k: " + str(max_k))
        last_occurences[word[i]] = i
    print(last_occurences)
    return max_k

def main():
    test = int(input())
    for t in range(test):
        n = int(input())
        print(compute_maximum_k(input()))

if __name__ == "__main__":
    main()
