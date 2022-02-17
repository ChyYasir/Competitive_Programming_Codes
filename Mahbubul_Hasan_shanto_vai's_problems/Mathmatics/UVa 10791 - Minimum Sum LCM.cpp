#include<bits/stdc++.h>

using namespace std;

#define int long long


int binpow(int a, int b) {
    int res = 1;

    while (b > 0) {
        if (b & 1) {
            res = a * res;
        }
        a = a * a;
        b = b >> 1;
    }
    return res;
}
map<int, int> mp;

void func(int n) {

    while (n % 2 == 0) {
        n /= 2;
        mp[2]++;
    }
    for (int i = 3; i * i <= n; i++) {
        while (n % i == 0) {
            n /= i;
            mp[i]++;
        }
    }

    if (n > 1) {
        mp[n]++;
    }
}
signed main() {


    int cnt = 1;
    int n;
    while (cin >> n) {
        if (n == 0) break;
        if (n == 1) {
            cout << "Case " << cnt++ << ": " << 2 << endl;
            continue;
        }
        mp.clear();
        int ans = 0;


        func(n);

        for (auto x : mp) {
            ans += binpow(x.first, x.second);
        }
        if ((int)mp.size() == 1) ans++;
        cout << "Case " << cnt++ << ": " << ans << endl;
    }

}