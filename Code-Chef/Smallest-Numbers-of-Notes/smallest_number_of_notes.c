    /*  Problem Statement: https://www.codechef.com/problems/FLOW005
        Author: striker
    */

    #include<stdio.h>
    #include<stdlib.h>
    #include<inttypes.h>
    #include<assert.h>

    #define HUNDRED 100
    #define FIFTY 50
    #define TEN 10
    #define FIVE 5
    #define TWO 2

    int main(void) {
        uint32_t test;
        scanf("%"SCNu32, &test);
        assert(test > 0 && test < 1001);
        while(test--) {
            uint32_t money_rs;
            scanf("%"SCNu32, &money_rs);
            assert(money_rs > 0 && money_rs < 1000001);
            uint32_t no_of_notes = 0;
            while(money_rs) {
                if(money_rs >= HUNDRED) {
                    no_of_notes += (money_rs / HUNDRED);
                    money_rs %= HUNDRED;
                } else if(money_rs >= FIFTY) {
                    no_of_notes += (money_rs / FIFTY);
                    money_rs %= FIFTY;
                } else if(money_rs >= TEN) {
                    no_of_notes += (money_rs / TEN);
                    money_rs %= TEN;
                } else if(money_rs >= FIVE) {
                    no_of_notes += (money_rs / FIVE);
                    money_rs %= FIVE;
                } else if(money_rs >= TWO) {
                    no_of_notes += (money_rs / TWO);
                    money_rs %= TWO;
                } else {
                    no_of_notes += money_rs;
                    money_rs = 0;
                }
            }
            printf("%"PRIu32"\n", no_of_notes);
        }
        return 0;
    }
