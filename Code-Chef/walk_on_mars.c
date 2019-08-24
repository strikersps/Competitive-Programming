#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<assert.h>

#define MOD 1e18

typedef unsigned long long _ull;

_ull _compute_distance_travelled(_ull,size_t,size_t);

int main(int argc,const char*argv[]) {
    size_t test,t1,t2,x;
    _ull s1,s2;
    for(fscanf(stdin,"%ld",&test);test>0;--test) {
        fprintf(stdout,"Enter the value of s1,s2,t1,t2\n");
        fscanf(stdin,"%lld%lld%ld%ld",&s1,&s2,&t1,&t2);
        assert((s1>0 && s1<(_ull)MOD) && (s2>0 && s2<=(_ull)MOD) && (s1<s2) && (s1>=t1) && (s2>=t2));
        assert((t1>0 && t1<51) && (t2>0 && t2<51) && ((t2-t1)<=2));
        fprintf(stdout,"Enter the value of X\n");
        fscanf(stdin,"%ld",&x);
        assert(x>0 && x<51);
        fprintf(stdout,"%lld\n",_compute_distance_travelled(s1,t1,x));
    }
    return 0;
}

_ull _compute_distance_travelled(_ull s1,size_t t1,size_t x) {
    _ull distance_travelled_in_1s = s1/(pow(2,t1-1));
    return (distance_travelled_in_1s*(pow(2,(x-1))));
}