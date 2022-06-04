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

ll dp(int i, int taken, int sum) {

    if (i == (n + 1)) {
        if (taken == m && sum == 0) return 1;
        return 0;
    }
    ll &ans = mem[i][taken][sum];
    if (ans != -1) return ans;
    // take the element if you have taken less than "taken"

    int val = (sum + arr[i]) % d;
    if (val < 0) val += d; // for negative

    ll op1 = (taken < m) ? dp(i + 1, taken + 1, val) : 0;

    // do not take the element
    ll op2 = dp(i + 1, taken, sum);

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


            cout << dp(1, 0, 0) << endl;
        }

    }
}