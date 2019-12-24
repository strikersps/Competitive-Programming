/*  Problem Statement: https://codeforces.com/contest/1282/problem/A
 *  Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<inttypes.h>

typedef unsigned long long ull_t;
typedef long long ll_t;

#define MEMORY_ALLOCATION_FAILED_ERROR(variable, bytes) fprintf(stderr, "Line number: %u: Not able to allocate <%lu> bytes of memory to <%s> variable.\n", __LINE__, bytes, #variable)
#define CONSTRAINTS_NOT_SATISFIED(variable, constraints) fprintf(stderr, "Line number: %u: Constraints not satified for the variable <%s>, i.e. %s.\n", __LINE__, #variable, #constraints)

static void swap_data(int *const, int *const);
static int compute_offline_time(const int, const int, const int, const int);

int main(void) {
    int test;
    scanf("%d", &test);
    if(test < 1 || test > 1000) {
        CONSTRAINTS_NOT_SATISFIED(test, "1 <= test <= 1000");
        exit(0);
    }
    while(test--) {
        int a, b, base_station_loc, network_radius;
        scanf("%d%d%d%d", &a, &b, &base_station_loc, &network_radius);
        if(a < -100000000 || a > 100000000) {
            CONSTRAINTS_NOT_SATISFIED(a, "-10^8 <= a <= 10^8");
            exit(0);
        }
        if(b < -100000000 || b > 100000000) {
            CONSTRAINTS_NOT_SATISFIED(b, "-10^8 <= b <= 10^8");
            exit(0);
        }
        if(base_station_loc <  -100000000 || base_station_loc > 100000000) {
            CONSTRAINTS_NOT_SATISFIED(base_station_loc, "-10^8 <= base_station_loc <= 10^8");
            exit(0);
        }
        if(network_radius < 0 || network_radius > 100000000) {
            CONSTRAINTS_NOT_SATISFIED(network_radis, "0 <= network_radius <= 10^8");
            exit(0);
        }
        if(a > b) {
            swap_data(&a, &b);
        }
        printf("%d\n", compute_offline_time(a, b, base_station_loc, network_radius));
    }
    return EXIT_SUCCESS;
}


static void swap_data(int *const a, int *const b) {
    if(!(a == b)) {
        (*a) = (*a) ^ (*b);
        (*b) = (*a) ^ (*b);
        (*a) = (*a) ^ (*b);
    }
}

static int compute_offline_time(const int a, const int b, const int base_station_loc, int const network_radius) {
    int offline_time = 0;
    int online_start_loc, online_end_loc;
    online_start_loc = base_station_loc - network_radius;
    online_end_loc = base_station_loc + network_radius;
    if((a < online_start_loc && b < online_start_loc) || (a > online_end_loc && b > online_end_loc)) {
        offline_time = b - a;
    } else if(a < online_start_loc || b > online_end_loc) {
        if(b < online_end_loc) {
            offline_time = online_start_loc - a;
        } else if(a > online_start_loc) {
            offline_time = b - online_end_loc;
        } else {
            offline_time = (online_start_loc - a) + (b - online_end_loc);
        }
    }
    return abs(offline_time);
}
