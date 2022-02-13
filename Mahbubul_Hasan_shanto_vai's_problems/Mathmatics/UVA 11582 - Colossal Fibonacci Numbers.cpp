#include<bits/stdc++.h>

using namespace std;

#define int unsigned long long int
#define debug(x)        cerr << #x << " == " << (x) << '\n';
int mul(int a, int b, int M) {return ((a % M) * (b % M)) % M;}

int binpow(int a, int b, int n) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = mul(a, res, n);
        }
        a = mul(a, a, n);
        b >>= 1;
    }
    return res;
}
void fast_io()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
signed main() {
    fast_io();
    vector<int> pattern[1005];
    vector<int> length(1005);
    for (int i = 1; i <= 1000; i++) {
        int n = i;

        int first = 0;
        int second = 1 % n;
        pattern[n].push_back(0);
        pattern[n].push_back(1 % n);
        for (int i = 0; i <= 9999; i++) {
            int current = (first + second) % n;
            pattern[n].push_back(current);
            first = second;
            second = current;
        }
        // for (int i = 0; i < pattern.size(); i++) {
        //     cout << pattern[i] << " ";
        // }
        int len = -1;
        for (int i = 1; i < 9999; i++) {
            // cout << pattern[i] << " ";
            if (pattern[n][i] == 0) {

                len = i;
                bool ok = 1;
                for (int j = i; j <= i + len - 1; j++) {
                    if (pattern[n][j] != pattern[n][j - len]) {
                        ok = 0;
                        break;
                    }
                }
                if (ok) {
                    break;
                }
                else {
                    len = -1;
                }
            }
            if (len != -1) {
                break;
            }
        }
        length[n] = len;
    }
    int t; cin >> t;
    while (t--) {
        int a, b, n; cin >> a >> b >> n;
        // debug(a);
        // debug(b);
        // debug(n);

        // cout << endl;
        // cout << len << endl;
        int pos = binpow(a, b, length[n]);

        cout << pattern[n][pos] << endl;



    }
}
