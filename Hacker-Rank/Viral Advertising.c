/*https://www.hackerrank.com/challenges/strange-advertising/problem*/
/*Authot:- invictus1599*/
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n,i,j,k=0;
    scanf("%d",&n);
    k=5/2;
    j=5/2;
    for(i=1;i<n;i++){
        j=j*3;
        j=j/2;
        k=k+j;
    }
    printf("%d",k);
    return 0;
}
