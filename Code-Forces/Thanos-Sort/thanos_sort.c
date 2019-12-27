/*  Problem Statement: https://codeforces.com/problemset/problem/1145/A
 *  Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>

#define CONSTRAINTS_OUT_OF_BOUND_ERROR(variable,constraints) fprintf(stderr,"Line number: %u: Constraint not satified. <%s> should be under the given constraints i.e %s.\n", __LINE__, #variable, #constraints)
#define MEMORY_ALLOCATION_FAILED_ERROR(variable,bytes) fprintf(stderr,"Line number: %u: Not able to allocate the memory to <%lu> bytes of memory to <%s> variable\n", __LINE__, (bytes), #variable)

static bool check_sorted(const uint32_t *const, const uint32_t, const uint32_t);
static int32_t thanos_sort(const uint32_t *const, const uint32_t, const uint32_t); // Recursive Function.
static int32_t max(const int32_t, const int32_t);

int main(void) {
    uint32_t n;
    scanf("%u", &n);
    if(n & (n - 1)) {
        CONSTRAINTS_OUT_OF_BOUND_ERROR(n, "2^n");
        exit(0);
    }
    uint32_t *const data = calloc(n, sizeof(*data));
    if(data) {
        for(uint32_t i = 0; i < n; ++i) {
            scanf("%u", (data + i));
            if(data[i] < 1 || data[i] > 101) {
                CONSTRAINTS_OUT_OF_BOUND_ERROR(data[i], "1 <= data[i] <= 100");
                exit(0);
            }
        }
        printf("%d\n", thanos_sort(data, 0, (n - 1)));
        free(data);
    } else {
        MEMORY_ALLOCATION_FAILED_ERROR(*data, n * sizeof(*data));
        exit(0);
    }
    return EXIT_SUCCESS;
}

static bool check_sorted(const uint32_t *const data, const uint32_t start, const uint32_t end) {
    bool is_sorted = true;
    for(uint32_t i = start; i < end; ++i) {
        if(data[i] > data[i + 1]) {
            is_sorted = false;
            break;
        }
    }
    return is_sorted;
}

static int32_t thanos_sort(const uint32_t *const data, const uint32_t start, const uint32_t end) {
    if(start < end) {
        if(check_sorted(data, start, end)) {
            return (int32_t) (1 + (end - start));
        }
        const uint32_t mid = ((end - start) >> 1) + start;
        return max(thanos_sort(data, mid + 1, end), thanos_sort(data, start, mid));
    }
    return 1;
}

static int32_t max(const int32_t a, const int32_t b) {
    return a > b ? a : b;
}
