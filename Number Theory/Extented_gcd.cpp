#include<bits/stdc++.h>

using namespace std;


#define int long long

int egcd(int a, int b, int &x, int &y) {

    if ( b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int d = egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

signed main() {
    int x, y;

    cout << egcd(10, 6, x, y) << endl;
    cout << x << " " << y << endl;

}