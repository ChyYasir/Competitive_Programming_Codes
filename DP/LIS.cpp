#include<bits/stdc++.h>

using namespace std;
#define ll long long
const ll N = 1e6 + 5;
const ll INF = 1e18;
ll dp[N];

ll p[N];
vector<int> a;


int main() {
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a.push_back(x);

    }

    // dp[l] ---> the element at which a sequence of length 'l' terminates
    // if there are multiple sequences then we take the smallest element at which the sequence terminates


    for (int l = 0; l <= n; l++) {
        dp[l] = INF;

    }
    dp[0] = -INF;


    // // //o(N^2) solution
    // for (int i = 0; i < n; i++) {

    //     for (int l = 1; l <= n; l++) {
    //         if (dp[l - 1] < a[i] && a[i] < dp[l]) {
    //             dp[l] = a[i];
    //         }
    //     }
    // }

    // o(NlogN) solution

    for (int i = 0; i < n; i++) {

        ll idx = upper_bound(dp, dp + n, a[i]) - dp;

        if (dp[idx - 1] < a[i] && a[i] < dp[idx]) {
            dp[idx] = a[i];

        }
    }

    ll ans = 0;

    for (ll l = 1; l <= n; l++) {
        if (dp[l] < INF) {
            ans = max(ans, l);

        }
    }


    cout << ans << endl;


}