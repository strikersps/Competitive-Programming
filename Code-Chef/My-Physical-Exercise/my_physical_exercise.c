/*  Problem Statement: https://www.codechef.com/problems/PHCUL
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<string.h>
#include<float.h>
#include<math.h>
#include<assert.h>

#define MAX_LIMIT 1000000001

typedef struct point_2d {
    int32_t x,y;
} points;

static double compute_eucledian_dist(points *const,points*const);
static double find_minimum(double,double);

int main(void) {
    uint16_t test;
    scanf("%"SCNu16, &test);
    assert(test > 0 && test < 5001);
    while(test--) {
        points source;
        scanf("%"SCNu32"%"SCNu32, &source.x,&source.y);
        assert((source.x >= 0 && source.x <= MAX_LIMIT) && (source.y >= 0 && source.y <= MAX_LIMIT));
        uint16_t n,m,k;
        scanf("%"SCNu16"%"SCNu16"%"SCNu16, &n,&m,&k);
        assert((n > 0 && n < 5001) && (m > 0 && m < 5001) && (k > 0 && k < 5001));
        points set_of_n_points[n];
        double distance_from_source_to_n[n];
        for(uint16_t i = 0; i < n; ++i) {
            scanf("%"SCNu32"%"SCNu32, &set_of_n_points[i].x,&set_of_n_points[i].y);
            assert((set_of_n_points[i].x >= 0 && set_of_n_points[i].x <= MAX_LIMIT) && (set_of_n_points[i].y >= 0 && set_of_n_points[i].y < MAX_LIMIT));
            distance_from_source_to_n[i] = compute_eucledian_dist(&source,&set_of_n_points[i]);
        }
        points set_of_m_points[m];
        double distance_from_source_to_m[m];
        for(uint16_t i = 0; i < m; ++i) {
            scanf("%"SCNu32"%"SCNu32, &set_of_m_points[i].x,&set_of_m_points[i].y);
            assert((set_of_m_points[i].x >= 0 && set_of_m_points[i].y < MAX_LIMIT) && (set_of_m_points[i].y >= 0 && set_of_m_points[i].y < MAX_LIMIT));
            distance_from_source_to_m[i] = compute_eucledian_dist(&source,&set_of_m_points[i]);
        }
        points set_of_end_points[k];
        for(uint16_t i = 0; i < k; ++i) {
            scanf("%"SCNu32"%"SCNu32, &set_of_end_points[i].x,&set_of_end_points[i].y);
            assert((set_of_end_points[i].x >= 0 && set_of_end_points[i].x < MAX_LIMIT) && (set_of_end_points[i].y >= 0 && set_of_end_points[i].y < MAX_LIMIT));
        }
        double closest_end_points_from_set_n[n];
        double closest_end_points_from_set_m[m];
        double min_distance;
        for(uint16_t i = 0; i < n; ++i) {
            min_distance = DBL_MAX;
            for(uint16_t j = 0; j < k; ++j) {
                double curr_distance = compute_eucledian_dist(&set_of_n_points[i],&set_of_end_points[j]);
                if(curr_distance < min_distance) {
                    min_distance = curr_distance;
                    closest_end_points_from_set_n[i] = min_distance;
                }
            }
        }
        for(uint16_t i = 0; i < m; ++i) {
            min_distance = DBL_MAX;
            for(uint16_t j = 0; j < k; ++j) {
                double curr_distance = compute_eucledian_dist(&set_of_m_points[i],&set_of_end_points[j]);
                if(curr_distance < min_distance) {
                    min_distance = curr_distance;
                    closest_end_points_from_set_m[i] = min_distance;
                }
            }
        }
        min_distance = DBL_MAX;
        for(uint16_t i = 0; i < n; ++i) {
            for(uint16_t j = 0; j < m; ++j) {
                double distance_btw_points = compute_eucledian_dist(&set_of_n_points[i],&set_of_m_points[j]);
                double curr_distance = find_minimum((distance_from_source_to_n[i] + distance_btw_points + closest_end_points_from_set_m[j]),(distance_from_source_to_m[j] + distance_btw_points + closest_end_points_from_set_n[i]));
                if(curr_distance < min_distance) {
                    min_distance = curr_distance;
                }
            }
        }
        printf("%0.10lf\n", min_distance);
    }
    return EXIT_SUCCESS;
}

static double compute_eucledian_dist(points *const a,points *const b) {
    int64_t p1 = (b->x - a->x);
    int64_t p2 = (b->y - a->y);
    return sqrt((p1 * p1) + (p2 * p2));
}

static double find_minimum(double a,double b) {
    return (a > b ? b : a);
}