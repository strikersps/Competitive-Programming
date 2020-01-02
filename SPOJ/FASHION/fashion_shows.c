/*  Problem Statement: https://www.spoj.com/problems/FASHION/
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>

#define MAX_SIZE 11

int compare_ints(const void*, const void*);

int main(void) {
    uint32_t test;
    scanf("%"SCNu32, &test);
    assert(test > 0);
    while(test--) {
        uint16_t n;
        scanf("%"SCNu16, &n);
        assert(n > 0);
        uint8_t *const hotness_level_men = calloc(n, sizeof(uint8_t));
        if(hotness_level_men) {
            for(uint16_t i = 0; i < n; ++i) {
                scanf("%"SCNu8, &hotness_level_men[i]);
            }
            qsort(hotness_level_men, n, sizeof(uint8_t), compare_ints);
        } else {
            fprintf(stderr, "Not able to allocate %lu bytes of memory\n", (n * sizeof(uint8_t)));
        }
        uint8_t *const hotness_level_women = calloc(n, sizeof(uint8_t));
        if(hotness_level_women) {
            for(uint16_t i = 0; i < n; ++i) {
                scanf("%"SCNu8, &hotness_level_women[i]);
            }
            qsort(hotness_level_women, n, sizeof(uint8_t), compare_ints);
        } else {
            fprintf(stderr, "Not able to allocate %lu bytes of memory\n", (n * sizeof(uint8_t)));
        }
        uint32_t sum_of_hotness_bonds = 0;
        for(uint16_t i = 0; i < n; ++i) {
            if(hotness_level_men[i] && hotness_level_women[i]) {
                sum_of_hotness_bonds += (hotness_level_men[i] * hotness_level_women[i]);
            }
        }
        printf("%"PRIu32"\n", sum_of_hotness_bonds);
        free(hotness_level_men);
        free(hotness_level_women);
    }
    return EXIT_SUCCESS;
}

int compare_ints(const void *a, const void *b) {
    uint8_t v1 = *(const uint8_t*) a;
    uint8_t v2 = *(const uint8_t*) b;
    if(v1 > v2) {
        return true;
    } else {
        return false;
    }
}
