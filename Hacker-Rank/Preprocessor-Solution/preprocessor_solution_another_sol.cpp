/* Enter your macros here */

#define INF 1e9
#define foreach(container_name, itr) for(size_t itr = 0; itr < container_name.size(); ++itr)
#define toStr(data) #data
#define io(container_name) cin >> container_name
#define FUNCTION(function_name, operator_sign) void function_name(int &x, int y) {if(!(x operator_sign y)) {x = y;}}

/*Locked Code From Here In Hacker-Rank i.e. You cannot change the code below.*/

#include <iostream>
#include <vector>
using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main() {
    int n; cin >> n;
    vector<int> v(n);
    foreach(v, i) {
        io(v)[i];
    }
    int mn = INF;
    int mx = -INF;
    foreach(v, i) {
        minimum(mn, v[i]);
        maximum(mx, v[i]);
    }
    int ans = mx - mn;
    cout << toStr(Result =) <<' '<< ans;
    return 0;
}
