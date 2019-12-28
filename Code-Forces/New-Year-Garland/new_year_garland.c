/*  Problem Statement: https://codeforces.com/problemset/problem/1279/A
 *  Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef unsigned long long ull_t;
typedef long long ll_t;

#define CONSTRAINTS_OUT_OF_BOUND_ERROR(variable, constraints) fprintf(stderr, "Constraints not satified for <%s> variable, i.e. %s\n", #variable, constraints)

static bool is_garland_possible(const int, const int, const int);

int main(void) {
    int test;
    scanf("%d", &test);
    if(test < 1 || test > 100) {
        CONSTRAINTS_OUT_OF_BOUND_ERROR(test, "1 <= test <= 100");
        exit(0);
    }
    while(test--) {
        int red_count, green_count, blue_count; // For storing the number red, blue, and green lamps.
        scanf("%d%d%d", &red_count, &green_count, &blue_count);
        if(red_count < 1 || red_count > 1000000000) {
            CONSTRAINTS_OUT_OF_BOUND_ERROR(red_count, "1 <= red_count <= 10^9");
            exit(0);
        }
        if(green_count < 1 || green_count > 1000000000) {
            CONSTRAINTS_OUT_OF_BOUND_ERROR(green_count , "1 <= green_count <= 10^9");
            exit(0);
        }
        if(blue_count < 1 || blue_count > 1000000000) {
            CONSTRAINTS_OUT_OF_BOUND_ERROR(blue_count, "1 <= blue_count <= 10^9");
            exit(0);
        }
        printf("%s\n", is_garland_possible(red_count, green_count, blue_count) ? "Yes" : "No");
    }
    return EXIT_SUCCESS;
}

static bool is_garland_possible(const int red_count, const int green_count, const int blue_count) {
    bool is_possible = true;
    if((red_count - (blue_count + green_count)) > 1 || (blue_count - (red_count + green_count)) > 1 || (green_count - (red_count + blue_count)) > 1) {
        is_possible = false;
    }
    return is_possible;
}
