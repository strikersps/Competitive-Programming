/*  Problem Statement: https://www.hackerrank.com/challenges/apple-and-orange/problem
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<assert.h>

int main(void) {
    int32_t house_start_loc,house_end_loc,apple_tree_loc,orange_tree_loc,no_of_apples_fall,no_of_oranges_fall;
    scanf("%"SCNd32"%"SCNd32, &house_start_loc,&house_end_loc);
    assert((house_start_loc > 0 && house_start_loc < 100001) && (house_end_loc > 0 && house_end_loc < 100001));
    scanf("%"SCNd32"%"SCNd32, &apple_tree_loc,&orange_tree_loc);
    assert((apple_tree_loc > 0 && apple_tree_loc < 100001) && (orange_tree_loc > 0 && orange_tree_loc < 100001));
    scanf("%"SCNd32"%"SCNd32, &no_of_apples_fall,&no_of_oranges_fall);
    assert((no_of_apples_fall > 0 && no_of_apples_fall < 100001) && (no_of_oranges_fall > 0 && no_of_oranges_fall < 100001));
    uint32_t count_of_apples_fall_on_house = 0;
    int32_t distance_from_tree;
    for(uint32_t i = 0; i < no_of_apples_fall; ++i) {
        scanf("%"SCNd32, &distance_from_tree);
        int32_t distance_of_apple = apple_tree_loc + distance_from_tree;
        if(distance_of_apple >= house_start_loc && distance_of_apple <= house_end_loc) {
            ++count_of_apples_fall_on_house;
        }
    }
    uint32_t count_of_oranges_fall_on_house = 0;
    for(uint32_t i = 0; i < no_of_oranges_fall; ++i) {
        scanf("%"SCNd32, &distance_from_tree);
        int32_t distance_of_orange = orange_tree_loc + distance_from_tree;
        if(distance_of_orange >= house_start_loc && distance_of_orange <= house_end_loc) {
            ++count_of_oranges_fall_on_house;
        }
    }
    printf("%"PRIu32"\n%"PRIu32"\n", count_of_apples_fall_on_house,count_of_oranges_fall_on_house);
    return EXIT_SUCCESS;
}