/*  Problem Statement: https://codeforces.com/problemset/problem/393/A
 *  Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define STRING_MAX_LENGTH 101
#define MAX_NUMBER_OF_NINETEEN 14
#define NOT_FOUND -1
#define FIND_MIN(a, b) ((a) > (b)) ? (b) : (a)

static int binary_search_integers(const int *const, const int);
static int find_largest_element_smaller_than_n(const int *const, const int);

int main(void) {
    char string_data[STRING_MAX_LENGTH];
    scanf("%s", string_data);
    int e_count, i_count, n_count, t_count; // stores the number of times each e,i,n,t alphabet appear in the input string.
    e_count = i_count = n_count = t_count = 0;
    for(unsigned int i = 0; '\0' != string_data[i]; ++i) {
        switch(string_data[i]) {
            case 'e':
                ++e_count;
                break;
            case 'i':
                ++i_count;
                break;
            case 'n':
                ++n_count;
                break;
            case 't':
                ++t_count;
                break;
            default:
                break;
        }
    }
    int min_n_required[MAX_NUMBER_OF_NINETEEN];
    for(unsigned int i = 0; i < MAX_NUMBER_OF_NINETEEN; ++i) {
        min_n_required[i] = ((i + 1) * 3) - i;
    }
    n_count = find_largest_element_smaller_than_n(min_n_required, n_count);
    if(n_count == NOT_FOUND) {
        n_count = 0;
    } else {
        ++n_count;
    }
    printf("%d\n", FIND_MIN(FIND_MIN(n_count, e_count / 3), FIND_MIN(i_count, t_count)));
    return EXIT_SUCCESS;
}

static int binary_search_integers(const int *const search_space, const int key) {
    int start = 0, end = MAX_NUMBER_OF_NINETEEN;
    while(start <= end) {
        const int mid = ((end - start) >> 1) + start;
        if(search_space[mid] == key) {
            return mid;
        } else if(search_space[mid] > key) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return NOT_FOUND;
}

static int find_largest_element_smaller_than_n(const int *const search_space, const int number) {
    int found_index = binary_search_integers(search_space, number);
    if(NOT_FOUND == found_index) {
        int start = 0, end = MAX_NUMBER_OF_NINETEEN;
        while(start <= end) {
            const int mid = ((end - start) >> 1) + start;
            if(search_space[mid] >= number) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return end;
    } else {
        return found_index;
    }
}
