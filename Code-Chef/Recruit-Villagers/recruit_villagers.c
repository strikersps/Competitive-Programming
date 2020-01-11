/*  Problem Statement: https://www.codechef.com/PLIT2020/problems/VILLINE
 *  Author: striker
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <time.h>

typedef unsigned long long ull_t;
typedef long long ll_t;

typedef struct Point2D {
    int x, y;
} point_2d;

#define MOD (1000000000 + 7) // Prime Number
#define PI 3.141592653589793 // Number of digits JPL uses for Interplanetary Caculations.

#define MEMORY_ALLOCATION_FAILED_ERROR(variable, bytes) fprintf(stderr, "Line number: %u: Not able to allocate <%lu> bytes of memory to <%s> variable.\n", __LINE__, (bytes), #variable)
#define CONSTRAINTS_OUT_OF_BOUND_ERROR(variable, constraints) fprintf(stderr, "Line number: %u: Constraints not satisfied for the variable <%s>, i.e. %s.\n", __LINE__, #variable, #constraints)
#define INITIALISE_CONTAINER_ZERO(container, bytes) memset(container, 0, (bytes))
#define FIND_MAX(a, b) (a) > (b) ? (a) : (b)
#define FIND_MIN(a, b) (a) < (b) ? (a) : (b)
#define FIND_MID(start, end) (((end) - (start)) >> 1) + (start)

int main(void) {
    #ifndef ONLINE_JUDGE
        freopen("test-cases/test-case-1.in", "r", stdin);
        freopen("test-cases/test-case-1.out", "w", stdout);
    #endif
    int n, m, c;
    scanf("%d", &n);
    scanf("%d%d", &m, &c);
    unsigned int village_power_a, village_power_b;
    village_power_a = village_power_b = 0;
    for(int i = 0; i < n; ++i) {
        int x_coordinate_house, y_coordinate_house, minion_power;
        scanf("%d%d%d", &x_coordinate_house, &y_coordinate_house, &minion_power);
        if(((m * x_coordinate_house) + c) < y_coordinate_house) {
            village_power_b += minion_power;
        } else {
            village_power_a += minion_power;
        }
    }
    printf("%d\n", FIND_MAX(village_power_a, village_power_b));
    return EXIT_SUCCESS;
}
