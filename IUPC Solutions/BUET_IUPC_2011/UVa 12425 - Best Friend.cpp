#include<bits/stdc++.h>

using namespace std;


#define ll long long
#define debug(x)        cerr << #x << " == " << (x) << '\n';
ll phi(ll n) {

    ll res = n;

    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            // i is prime
            while (n % i == 0) {
                n /= i;
            }
            res = (res - res / i);
        }
    }
    if (n > 1) {
        res = (res - res / n);
    }
    return res;
}
ll cnt;
void solve() {

    ll n , q; cin >> n >> q;
    vector<ll> divisors;

    for (ll i = 1; i * i <= n; i++) {

        if (n % i == 0) {
            ll div1 = i, div2 = n / i;

            divisors.push_back(div1);
            if (div1 != div2) divisors.push_back(div2);
        }
    }
    sort(divisors.begin(), divisors.end());

    ll sz = divisors.size();
    ll cum[sz];

    for (int i = 0; i < sz; i++) {
        ll div = n / divisors[i];
        ll res = phi(div);
        // debug(div);
        // debug(res);
        cum[i] = res;
    }
    for (int i = 1; i < sz; i++) {
        cum[i] += cum[i - 1];
    }
    cout << "Case " << cnt++ << endl;
    while (q--) {
        ll x; cin >> x;
        if (x <= 0) {
            cout << 0 << endl;
            continue;
        }
        auto it = upper_bound(divisors.begin(), divisors.end(), x);
        it--;
        ll idx = it - divisors.begin();
        cout << cum[idx] << endl;
    }

}
signed main() {

    ios::sync_with_stdio();
    cin.tie(0); cout.tie(0);
    cnt = 1;
    int t; cin >> t;
    while (t--) {
        solve();
    }
}