/*  Problem Statement: https://www.codechef.com/problems/EATTWICE
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<assert.h>

struct menu {
    uint32_t tastiness,day_served;
};

typedef struct menu menu_t;

void take_input(menu_t *const,uint32_t);
uint32_t max_possible(menu_t *const,uint32_t);

int main(void) {
    uint16_t test;
    scanf("%"SCNu16,&test);
    assert(test > 0 && test < 1001);
    while(test--) {
        uint32_t n,m;
        scanf("%"SCNu32"%"SCNu32,&n,&m);
        assert((n > 1 && n < 100001) && (m > 1 && m < 100001));
        menu_t *const food_list = calloc(n,sizeof(menu_t));
        if(food_list) {
            take_input(food_list,n);
            printf("%"PRIu32"\n",max_possible(food_list,n));
            free(food_list);
        } else {
            fprintf(stderr,"Memory not allocated to food-list pointer!\n");
        }
    }
    return 0;
}

void take_input(menu_t *const food_list,uint32_t n) {
    for(uint32_t i = 0; i < n; ++i) {
        scanf("%"SCNu32"%"SCNu32,&food_list[i].day_served,&food_list[i].tastiness);
        assert(food_list[i].tastiness > 0 && food_list[i].tastiness < 1000000001);
    }
}

uint32_t max_possible(menu_t *const food_list,uint32_t n) {
    uint32_t first_max,second_max,first_max_served;
    first_max = food_list[0].tastiness;
    first_max_served = food_list[0].day_served;
    second_max = 0;
    for(uint32_t i = 1; i < n; ++i) {
        if(food_list[i].tastiness > first_max) {
            if(food_list[i].day_served != first_max_served) {
                second_max = first_max;
                first_max_served = food_list[i].day_served;
            }
            first_max = (food_list[i].tastiness);
        } else {
            if((food_list[i].tastiness > second_max) && (food_list[i].day_served != first_max_served)) {
                second_max = food_list[i].tastiness;
            }
        }
    }
    return (first_max + second_max);
}