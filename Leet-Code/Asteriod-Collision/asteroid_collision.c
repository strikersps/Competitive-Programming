/*  Problem Statement: https://leetcode.com/problems/asteroid-collision/
    Author: Suraj Sharma
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>

#define DESTROYED -1001

int32_t* asteroid_collision(int32_t*,uint32_t,uint32_t*);

int main(void) {
    uint32_t n,test;
    int32_t *asteroid = NULL;
    scanf("%"SCNu32,&test); // Enter the number of test-cases.
    assert(test > 0);
    while(test--) {
        scanf("%"SCNu32,&n); // Enter the size of the array.
        assert(n > 0 && n < 10001);
        asteroid = calloc(sizeof(int32_t),n);
        if(asteroid) {
            uint32_t size = 0;
            for(uint32_t i = 0; i < n; ++i) {
                scanf("%"SCNd32,&asteroid[i]);
                assert(asteroid[i] > -1001 && asteroid[i] < 1001); // As per the constraints of the problem
            }
            int32_t *asteroid_after_collision = asteroid_collision(asteroid,n,&size);
            for(uint32_t i = 0; i < size; ++i) {
                printf("%"PRId32" ",asteroid_after_collision[i]);
            }
            free(asteroid_after_collision);
            printf("\n");
        } else {
            fprintf(stderr,"Memory not allocated to asteroid pointer!\n");
        }
    }
    return 0;
}

int32_t* asteroid_collision(int32_t *asteroid,uint32_t asteroid_size,uint32_t* size) {
    uint32_t count_of_destroyed = 0;
    for(int32_t i = 1, k = 0; i < asteroid_size; ++i) {
        if(asteroid[i] < 0) {
            for(int32_t j = (i - 1); j >= 0; --j) {
                if(asteroid[j] > 0) {
                    ++count_of_destroyed;
                    if(abs(asteroid[i]) == asteroid[j]) {
                        asteroid[i] = asteroid[j] = DESTROYED;
                        ++count_of_destroyed; // In this case both the asteroid gets destroyed.
                        break;
                    } else if(abs(asteroid[i]) > asteroid[j]) {
                        asteroid[j] = DESTROYED;
                    } else {
                        asteroid[i] = DESTROYED;
                        break;
                    }
                }
            }
        }
    }
    *size = asteroid_size - count_of_destroyed;
    int32_t* asteroid_after_collision = calloc(sizeof(int32_t),(*size));
    for(uint32_t i = 0,j = 0; (i < asteroid_size) && (j < (*size)); ++i) {
        if(asteroid[i] != DESTROYED) {
            asteroid_after_collision[j] = asteroid[i];
            ++j;
        }
    }
    free(asteroid);
    return asteroid_after_collision;
}