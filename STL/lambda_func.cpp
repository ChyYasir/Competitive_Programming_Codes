#include<bits/stdc++.h>

using namespace std;


int main() {

    // lambda function
    auto func = [](int i, int j) {
        return i + j;
    };
    cout << func(10, 20) << endl;

    function<double(int, double)> var = [](int i, double j) {

        return i + j;
    };
    cout << var(10, 20.1) << endl;

    // recursive lamba function. cannot use auto in recursive lambda function.
    // in [] you have to pass the reference of fib
    // if you put [&] then all will be automically captured
    function<int(int)> fib = [&fib] (int i) {
        if (i <= 1) return 1;
        return fib(i - 1) + fib(i - 2);
    };
    printf("printing 1st eleven fibonacchi numbers...\n");
    for (int i = 0; i <= 10; i++) {
        cout << fib(i) << endl;
    }
}