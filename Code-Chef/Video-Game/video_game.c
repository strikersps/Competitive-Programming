/*  Problem Statement: https://www.codechef.com/ZCOPRAC/problems/ZCO14001
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>
#include<assert.h>

#define START_POSITION 0
#define MOVE_LEFT 1
#define MOVE_RIGHT 2
#define PICK_UP_THE_BOX 3
#define DROP_THE_BOX 4

void play_game(uint32_t *const,uint32_t,uint32_t);

int main(void) {
    uint32_t total_no_of_stacks, max_height_of_stack;
    scanf("%"SCNu32"%"SCNu32, &total_no_of_stacks,&max_height_of_stack);
    assert((total_no_of_stacks > 0 && total_no_of_stacks < 100001) && (max_height_of_stack > 0 && max_height_of_stack < 100000001));
    uint32_t *const stack_config = calloc(total_no_of_stacks,sizeof(uint32_t));
    if(stack_config ) {
        for(uint32_t i = 0; i < total_no_of_stacks; ++i) {
            scanf("%"SCNu32, &stack_config[i]);
        }
        play_game(stack_config,total_no_of_stacks,max_height_of_stack);
        for(uint32_t i = 0; i < total_no_of_stacks; ++i) {
            printf("%"PRIu32" ", stack_config[i]);
        }
        printf("\n");
        free(stack_config);
    } else {
        fprintf(stderr,"Memory not allocated to *stack_config pointer!\n");
    }
    return 0;
}

void play_game(uint32_t *const stack_config,uint32_t total_no_of_stack,uint32_t max_height_of_stack) {
    uint32_t crane_location = 0;
    bool is_crane_has_box = false;
    while(true) {
        uint32_t command_code;
        scanf("%"SCNu32, &command_code);
        assert(command_code >= 0 && command_code < 5);
        if(!command_code) {
            break;
        } else {
            assert(crane_location >=0 && crane_location < total_no_of_stack);
            switch(command_code) {
                case MOVE_LEFT: // Move left
                    if(crane_location > START_POSITION) {
                        --crane_location;
                    }
                    break;
                case MOVE_RIGHT: // Move right
                    if(crane_location < (total_no_of_stack - 1)) {
                        ++crane_location;
                    }
                    break;
                case PICK_UP_THE_BOX: // Pick up the box
                    if(!(is_crane_has_box) && stack_config[crane_location]) {
                        is_crane_has_box = true;
                        --stack_config[crane_location];
                    }
                    break;
                case DROP_THE_BOX: // Drop the box
                    if(is_crane_has_box && (stack_config[crane_location] < max_height_of_stack)) {
                        is_crane_has_box = false;
                        ++stack_config[crane_location];
                    }
                    break;
                default:
                    fprintf(stderr,"Invalid Command!\n");
                    break;
            }
        }
    }
}