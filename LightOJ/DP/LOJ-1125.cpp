#include<bits/stdc++.h>

using namespace std;


#define ll long long
void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

const int N = 200 + 5;
int n;

int arr[N];
int q;
int d, m;
ll mem[N][12][25];

ll dp(int i, int rem, int sum) {

    if (i == 0) {
        if (rem == 0 && sum == 0) return 1;
        return 0;
    }
    ll &ans = mem[i][rem][sum];
    if (ans != -1) return ans;
    // take the element if "rem" is greater than 0

    int val = (sum + arr[i]) % d;
    if (val < 0) val += d; // for negative

    ll op1 = (rem > 0) ? dp(i - 1, rem - 1, val) : 0;

    // do not take the element
    ll op2 = dp(i - 1, rem, sum);

    ans = op1 + op2;
    return ans;
}
signed main() {

    int t; cin >> t;
    int cnt = 1;
    while (t--) {
        cin >> n >> q;

        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        cout << "Case " << cnt++ << ": " << endl;
        while (q--) {

            cin >> d  >> m;
            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= m; j++) {
                    for (int k = 0; k <= d; k++) {
                        mem[i][j][k] = -1;
                    }
                }
            }


            cout << dp(n, m, 0) << endl;
        }

    }
}
