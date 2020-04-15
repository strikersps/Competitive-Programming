/* Problem Statement: https://www.hackerrank.com/challenges/preprocessor-solution/problem
 * Author: striker
 *
 * Code Explanation:
 * This problem is basically about how to make the given code for calculating the difference between an max and min in a integers sequence correct by creating the macros which refers to the correct-code.
 * In the code already given, you can see there are five keywords which doesn't have any meaning which are INF, toStr, io, foreach, FUNCTION beacuse of which the code doesn't compile.
 *
 * If you analyse the code you will get an what INF should be, it should be value larger than all the values in the vector container so, I wrote #define INF 1e9
 *
 * toStr converts the value passed into it to a string. In macros, we have special operator known as '#' when converts the arguments passed into a function macro to a string. To do that just add #define toStr(data) #data.
 *
 * io is for taking an input using cin. Add #define io(container_name) cin >> containter_name
 *
 * foreach is referring to a loop which iterates from 0 to size of the container. Add #define foreach(container_name, itr) for(size_t itr = 0; itr < container_name.size(); ++itr).
 *
 * The tricky part of the problem is to figure out FUNCTION(function_name, operator_sign) i.e. how you are going to define the function depending upon the operator_sign because macro doesn't support string comparison.
 * According to me I think for this code I don't need FUNCTION(funtion_name, operator_sign), so I am remove it by adding #define FUNCTION(function_name, operator_sign) which basically removes that call to the macro from the file.
 *
 * If you look at the code, you need minimum() and maximum() and everytime you call minimum and maximum it should replace the min and max value you got till now.
 * Add #define minimum(a, b) a = min(a. b)
 * Add #define maximum(a, b) a = max(a, b)
 *
 * That's it if you want to check whether the preprocessed ouput is correct C++ code or not, run the following command from the terminal:
 * g++ -E name_of_the _program.cpp > name_of_the_program_preprocessed_ouput.txt.
 * If you don't redirect the output to the file, it will print the output on the terminal.
 *
 * When you look at the preprocessed ouput, you will get the following:
 * int main(void) {
    int n; cin >> n;
    vector<int> v(n);
    for(size_t i = 0; i < v.size(); ++i) {
        cin >> v[i];
    }
    int mn = 1e9;
    int mx = -1e9;
    for(size_t i = 0; i < v.size(); ++i) {
        mn = min(mn, v[i]);
        mx = max(mx, v[i]);
    }
    int ans = mx - mn;
    cout << "Result =" <<' '<< ans;
    return 0;
}
* The above code is what we wanted, it will now be passed into the C++ Compiler which will generate the object code, which when you will run gives the correct output.
 * */

#ifndef INF
#define INF 1e9
#endif

#ifndef toStr
#define toStr(data) #data
#endif

#ifndef io
#define io(container_name) cin >> container_name
#endif

#ifndef foreach
#define foreach(container_name, itr) for(size_t itr = 0; itr < container_name.size(); ++itr)
#endif

#define FUNCTION(function_name, operator_name)

#define minimum(a, b) a = min(a, b)
#define maximum(a, b) a = max(a, b)

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
