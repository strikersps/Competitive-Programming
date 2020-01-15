/*
 * Problem Statement: https://www.codechef.com/problems/JOHNY
 * Author: striker
 *
 * Copyright 2020 striker
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <time.h>

typedef unsigned long long ull_t;
typedef long long ll_t;

typedef struct Point2D {
    int x, y;
} point_2d;

#define MOD (1000000000 + 7) // Prime Number
#define PI 3.141592653589793 // Number of digits(15) of Pi which JPL uses for Interplanetary Caculations.

#define MEMORY_ALLOCATION_FAILED_ERROR(variable, bytes) fprintf(stderr, "Line number: %u: Not able to allocate <%lu> bytes of memory to <%s> variable.\n", __LINE__, (bytes), #variable)
#define CONSTRAINTS_OUT_OF_BOUND_ERROR(variable, constraints) fprintf(stderr, "Line number: %u: Constraints not satisfied for the variable <%s>, i.e. %s.\n", __LINE__, #variable, #constraints)
#define INITIALISE_CONTAINER_ZERO(container, bytes) memset(container, 0, (bytes))
#define FIND_MAX(a, b) (a) > (b) ? (a) : (b)
#define FIND_MIN(a, b) (a) < (b) ? (a) : (b)
#define FIND_MID(start, end) (((end) - (start)) >> 1) + (start)

#define NOT_FOUND -1

static bool check_sorted(const int *const, const int);
static void merge_sort(int *const, const int, const int);
static void merge_data(int *const, const int, const int, const int);
static int binary_search(const int *const, int, int, const int);

int main(void) {
    #ifndef ONLINE_JUDGE
        freopen("test-cases/test-case-1.in", "r", stdin);
        freopen("test-cases/test-case-1.out", "w", stdout);
    #endif
    int test;
    scanf("%d", &test);
    while(test--) {
        int n;
        scanf("%d", &n);
        int *const song_length = calloc(n, sizeof *song_length);
        if(song_length) {
            for(int i = 0; i < n; ++i) {
                scanf("%d", &song_length[i]);
            }
            int uncle_johny_position;
            scanf("%d", &uncle_johny_position);
            int search_uncle_johny = song_length[uncle_johny_position - 1];
            if(!check_sorted(song_length, n)) {
                merge_sort(song_length, 0, n - 1);
            }
            int found_index = binary_search(song_length, 0, n - 1, search_uncle_johny);
            if(!(NOT_FOUND == found_index)) {
                printf("%d\n", found_index + 1);
            } else {
                printf("NOT-FOUND\n");
            }
            free(song_length);
        } else {
            MEMORY_ALLOCATION_FAILED_ERROR(song_length, n * sizeof *song_length);
            exit(0);
        }
    }
    return EXIT_SUCCESS;
}

static bool check_sorted(const int *const data, const int n) {
    bool is_sorted = true;
    for(int i = 0; i < (n - 1); ++i) {
        if(data[i] > data[i + 1]) {
            is_sorted = false;
            break;
        }
    }
    return is_sorted;
}

static void merge_sort(int *const data, const int start, const int end) {
    if(start < end) {
        const int mid = FIND_MID(start, end);
        merge_sort(data, start, mid);
        merge_sort(data, mid + 1, end);
        merge_data(data, start, mid, end);
    }
}

static void merge_data(int *const data, const int start, const int mid, const int end) {
    const int left_size = (mid - start) + 1;
    int *const left_data = calloc(left_size, sizeof *left_data);
    if(left_data) {
        memcpy(left_data, &data[start], left_size * sizeof *left_data);
    } else {
        MEMORY_ALLOCATION_FAILED_ERROR(left_data, left_size * sizeof *left_data);
        exit(0);
    }
    const int right_size = end - mid;
    int *const right_data = calloc(right_size, sizeof *right_data);
    if(right_data) {
        memcpy(right_data, &data[mid + 1], right_size * sizeof *right_data);
    } else {
        MEMORY_ALLOCATION_FAILED_ERROR(right_data, right_size * sizeof *right_data);
        exit(0);
    }
    for(int i = 0, j = 0, k = start; k <= end; ++k) {
        if(i == left_size) {
            data[k] = right_data[j++];
        } else if(j == right_size) {
            data[k] = left_data[i++];
        } else if(left_data[i] < right_data[j]) {
            data[k] = left_data[i++];
        } else {
            data[k] = right_data[j++];
        }
    }
    free(left_data);
    free(right_data);
}

static int binary_search(const int *const data, int start, int end, const int search_data) {
    while(start <= end) {
        const int mid = FIND_MID(start, end);
        if(search_data == data[mid]) {
            return mid;
        } else if(search_data > data[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return NOT_FOUND;
}
