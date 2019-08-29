/*  Command-line arguments program which take one argument i.e name of the input file in .txt format.
    Author: Suraj Sharma
*/
#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<assert.h>

int main(int argc,const char*argv[]) {
    if(argc > 1) {
        FILE*f_in = fopen(argv[1],"r");
        if(f_in) {
            uint64_t test,no_of_kids,max_no_of_kids,no_of_chocolates,max_no_of_chocolates;
            fscanf(f_in,"%"SCNu64,&test);
            max_no_of_kids = max_no_of_chocolates = 0;
            while(test--) {
                fscanf(f_in,"%"SCNu64,&no_of_kids);
                if(no_of_kids > max_no_of_kids) {
                    max_no_of_kids = no_of_kids;
                }
                for(uint64_t i=0;i<no_of_kids;++i) {
                    fscanf(f_in,"%"SCNu64,&no_of_chocolates);
                    if(no_of_chocolates > max_no_of_chocolates) {
                        max_no_of_chocolates = no_of_chocolates;
                    }
                }
            }
            printf("Upper Bound for Number of Kids: %"PRIu64"\t Upper Bound for Maximum Number of Chocolates a student can have: %"PRIu64"\n",max_no_of_kids,max_no_of_chocolates);
        } else {
            fprintf(stderr,"File name: large.txt doesn't opened successfully!\n");
        }
    } else {
        fprintf(stderr,"Please input the test-case file name!\n");
    }
    return 0;
}
