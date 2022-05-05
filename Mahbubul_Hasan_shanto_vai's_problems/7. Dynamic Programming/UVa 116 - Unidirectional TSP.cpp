#include<bits/stdc++.h>

using namespace std;

#define int long long
#define debug(x)        cerr << #x << " == " << (x) << '\n';
const int INF = 1e18;


int grid[15][105];

int opt[15][105];

int mem[15][105];

int n, m;

int dp(int i, int j) {

    if (j == m) {
        return 0;
    }
    int &ans = mem[i][j];
    if (ans != -INF) return ans;

    ans = INF;

    if (j == 0) {
        for (int x = 0; x < n; x++) {
            ans = min(ans, dp(x, 1) + grid[x][1]);
        }

    } else {

        for (int x = i - 1; x <= i + 1; x++) {
            int row = (x + n) % n;

            ans = min(ans, dp(row, j + 1) + grid[row][j + 1]);



        }

    }
    return ans;
}

void print(int row, int j) {
    if (j == m) {
        cout << row;
    }
    else {
        cout << row << " ";
    }
}
signed main() {


    while (cin >> n >> m) {

        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> grid[i][j];
            }
        }

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                mem[i][j] = -INF;
                opt[i][j] = 0;
            }
        }
        int ans = dp(0, 0);

        // path printing

        int cur_row;
        for (int x = 0; x < n; x++) {

            if (ans == (dp(x, 1) + grid[x][1])) {

                print(x + 1, 1);
                cur_row = x;
                ans -= grid[x][1];
                break;
            }

        }


        for (int j = 1; j < m; j++) {

            int mn = INF;
            for (int x = cur_row - 1; x <= cur_row + 1; x++) {
                int row = (x + n) % n;
                if (ans == (dp(row, j + 1) + grid[row][j + 1])) {
                    mn = min(mn, row);
                }


            }

            print(mn + 1, j + 1);
            cur_row = mn;

            ans -= grid[mn][j + 1];

        }
        cout << endl;
        cout << dp(0, 0) << endl;
    }
}