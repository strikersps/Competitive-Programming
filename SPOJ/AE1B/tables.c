/*  Problem Statement: https://www.spoj.com/problems/AE1B/
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<assert.h>

int comparator_callback(const void*,const void*);
static uint32_t compute_minimum_boxes(const uint32_t *const,uint32_t,int32_t);

int main(void) {
    uint32_t n,k,s;
    scanf("%"SCNu32"%"SCNu32"%"SCNu32, &n,&k,&s);
    assert((n > 0 && n < 1001) && (k > 0 && k < 1001) && (s > 0 && s < 1001));
    uint32_t *const boxes = calloc(sizeof(uint32_t), n);
    if(boxes) {
        for(uint32_t i = 0; i < n; ++i) {
            scanf("%"SCNu32, &boxes[i]);
            assert(boxes[i] > 0 && boxes[i] < 1001);
        }
        qsort(boxes,n,sizeof(uint32_t),comparator_callback);
        printf("%"PRIu32"\n", compute_minimum_boxes(boxes,n,(k * s)));
        free(boxes);
    } else {
        fprintf(stderr,"Not able to allocate %lu bytes of memory\n", sizeof(uint32_t) * n);
    }
    return EXIT_SUCCESS;
}

int comparator_callback(const void *a,const void *b) {
    return *(uint32_t*)a < *(uint32_t *)b;
}

static uint32_t compute_minimum_boxes(const uint32_t *const data,uint32_t n,int32_t screws_needed) {
    uint32_t min_boxes = 0,tot_screws = 0;
    for(uint32_t i = 0; i < n; ++i) {
        tot_screws += data[i];
        ++min_boxes;
        if(tot_screws >= screws_needed) {
            break;
        }
    }
    if(tot_screws >= screws_needed) {
        return min_boxes;
    } else {
        return 0;
    }
}