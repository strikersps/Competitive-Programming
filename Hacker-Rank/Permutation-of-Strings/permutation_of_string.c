/*  Problem Statement: https://www.hackerrank.com/challenges/permutations-of-strings/problem
    Author: striker
*/

// Source Code is already given, I need to implement the int next_permutation(int,char**).

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Print the next lexicographic permutation of the given string if it exists and return true else false.
int next_permutation(int n, char **s)
{
    int i,j;
    if(n == 0) {
        return false;
    } else {
        for(i = n - 1; (i > 0 && strcmp(s[i - 1],s[i]) >= 0); --i);
        if(i == 0) {
            return false;
        } else {
            for(j = n - 1; strcmp(s[j],s[i - 1]) <= 0; --j);
            char *temp = s[i - 1];
            s[i - 1] = s[j];
            s[j] = temp;
            for(j = n - 1; i < j; ++i,--j) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
	return true;
}

int main(void)
{
	char **s; // Pointer to a character pointer.
	int n; // Total number of strings.
	scanf("%d", &n);
	s = calloc(n, sizeof(char*)); // Creating an array of character pointers and initialised it with NULL.
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char)); // Storing the base address of an array containing 11 location. Every location will store a character constant.
		scanf("%s", s[i]); // Taking input string.
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' '); // Print the string seperated by space until i == n.
	} while (next_permutation(n, s)); // The set of instructions in do {} will execute until the next_permutaion returns false i.e when there is no next lexicographic permutation available.
	for (int i = 0; i < n; i++) // Free the memory pointed by each of the pointers in the array.
		free(s[i]);
	free(s); // Free char **s.
	return 0;
}
