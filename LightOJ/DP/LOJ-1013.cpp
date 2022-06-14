#include<bits/stdc++.h>

using namespace std;

#define int long long

const int N = 35;
string a, b;
int n, m;
int len;

int mem[N][N];

int dp(int i, int j) {
    if (i == n || j == m) {
        return 0;
    }
    int &ans = mem[i][j];

    if (ans != -1) return ans;

    int op1, op2;

    if (a[i] == b[j]) {
        ans = (i < n && j < m) ? dp(i + 1, j + 1) + 1 : 0;
        return ans;
    }

    op1 = (i < n) ? dp(i + 1, j) : 0;
    op2 = (j < m) ? dp(i, j + 1) : 0;

    ans = max(op1, op2);
    return ans;
}


int table[N][N][2 * N + 5];

int dyno(int i, int j, int rem) {

    if (i == n && j == m) {
        if (rem == 0) return 1;
        return 0;
    }
    int &ans = table[i][j][rem];

    if (ans != -1) return ans;

    int op1, op2;

    if (a[i] == b[j]) {
        ans = (i < n && j < m) ? dyno(i + 1, j + 1, rem - 1) : 0;
        return ans;
    }

    op1 = (i < n) ? dyno(i + 1, j, rem - 1) : 0;
    op2 = (j < m) ? dyno(i, j + 1, rem - 1) : 0;
    ans = op1 + op2;
    return ans;
}
signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    int t; cin >> t;
    int cnt = 1;
    while (t--) {
        cin >> a >> b;
        n = a.size();
        m = b.size();

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m ; j++) {
                mem[i][j] = -1;
            }
        }

        len = n + m - dp(0, 0);

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= len; k++) {
                    table[i][j][k] = -1;
                }
            }
        }

        cout << "Case " << cnt++ << ": " << len << " " << dyno(0, 0, len) << endl;


    }
}
