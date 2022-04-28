#include<bits/stdc++.h>

using namespace std;

#define int long long
#define debug(x)        cerr << #x << " == " << (x) << '\n';
const int N = 3e7 + 5;
int gcd(int a, int b) {
    if ( b == 0) return a;
    return gcd(b, a % b);
}
int ans[N];
int cum[N];
signed main() {

    int t; cin >> t;
    // by seeing the pattern we can say that
    // if gcd(a, b) == a^b then gcd(a, b) = a^b = a-b

    // for every gcd we need to check whether two
    // successive multiples are satisfying the condition or not

    for (int g = 1; g <= N - 5; g++) {
        int prv = g;
        for (int j = 2 * g; j <= N - 5; j += g) {
            if (g == (prv ^ j)) ans[j]++;
            prv = j;
        }
    }

    for (int i = 1; i <= N; i++) {
        cum[i] = cum[i - 1] + ans[i];
    }

    for (int test = 1; test <= t; test++) {
        int n; cin >> n;

        cout << "Case " << test << ": " << cum[n] << endl;
    }
}