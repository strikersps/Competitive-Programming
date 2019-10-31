/*  * Program to generate the test-cases for the problem: https://www.spoj.com/problems/COINS/
    * Program is based on command-line arguments which takes a filename as an argument.
    * Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<time.h>
#include<assert.h>

#ifdef _WIN32
    #include<Windows.h>
#else
    #include<unistd.h>
#endif

typedef unsigned long long ull_t;
ull_t MAX_LIMIT = 100;

int main(int argc,char *const argv[]) {
    srand(time(NULL));
    if(argc == 2) {
        FILE *test_file = fopen(argv[1],"w");
        if(test_file) {
            sleep(1);
            srand(time(NULL));
            for(int i = 0; i < 10; ++i) {
                fprintf(test_file,"%llu\n",(rand() % MAX_LIMIT));
            }
            fclose(test_file);
        } else {
            fprintf(stderr,"File not opened successfully\n");
            return EXIT_FAILURE;
        }
    } else {
        fprintf(stderr,"Insufficient or More number of command line arguments\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}