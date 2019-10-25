/*  Problem Statement: https://www.codechef.com/problems/FLOW010
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<ctype.h>
#include<assert.h>

int main(void) {
    uint16_t test;
    scanf("%"SCNu16, &test);
    assert(test > 0 && test < 1001);
    while(test--) {
        char id;
        getchar();
        scanf("%c", &id);
        if(islower(id)) {
            id = toupper(id);
        }
        switch(id) {
            case 'B':
                printf("BattleShip\n");
                break;
            case 'C':
                printf("Cruiser\n");
                break;
            case 'D':
                printf("Destroyer\n");
                break;
            case 'F':
                printf("Frigate\n");
                break;
            default:
                fprintf(stderr,"Invalid ID\n");
                break;
        }
    }
    return EXIT_SUCCESS;
}