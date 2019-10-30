/*  * Program genrates the test-cases for the given problem statement: https://www.spoj.com/problems/FASHION
    * Command Line arguments program, which takes one argument i.e. file-name as an argument.
    Author: striker
*/

#ifdef _WIN32
    #include<Windows.h>
#else
    #include<unistd.h>
#endif

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<ctype.h>
#include<time.h>
#include<assert.h>

#define MAX_TEST_CASES 5
#define MAX_LENGTH_OF_SEQUENCE 1000
#define SEQUENCE_GENERATION 2
#define MAX_VAL 11 // Maximum value that can be present in the sequence

void generate_sequence(FILE*,uint32_t);

int main(int argc,char *const argv[]) {
    if(argc == 2) {
        FILE *test_file = fopen(argv[1],"w");
        if(test_file) {
            sleep(1);
            srand(time(NULL));
            uint32_t test,n;
            test = rand() % MAX_TEST_CASES;
            if(!test) {
                test += 1;
            }
            fprintf(test_file,"%"PRIu32"\n",test);
            while(test--) {
                n = rand() % MAX_LENGTH_OF_SEQUENCE;
                if(!n) {
                    n += 3;
                }
                fprintf(test_file,"%"PRIu32"\n", n);
                generate_sequence(test_file,n);
                fprintf(test_file,"\n");
                generate_sequence(test_file,n);
                fprintf(test_file,"\n");
            }
            fclose(test_file);
        } else {
            fprintf(stderr,"File not opened succesfully\n");
            EXIT_FAILURE;
        }
    } else {
        fprintf(stderr,"Insufficient or more number of arguments!\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

void generate_sequence(FILE *test_file,uint32_t n) {
    for(uint32_t i = 0; i < n; ++i) {
        fprintf(test_file,"%"PRIu8" ", (rand() % MAX_VAL));
    }
}