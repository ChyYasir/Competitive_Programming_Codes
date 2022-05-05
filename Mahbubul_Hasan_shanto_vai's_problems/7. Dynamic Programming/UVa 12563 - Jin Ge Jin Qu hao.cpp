#include<bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;
const int N = 50 + 5;
int n, x;
int song[N];

int mem[N][9005];
int dp(int k, int tot) {
// what is the maximum number of song we can take from
// first k songs so that the total singing time is equal to tot

    if (k == 0) {
        if (tot == 0) return 0;
        return -INF;
    }
    int &ans = mem[k][tot];

    if (ans != -1) return ans;

    // we take the k-th song
    // we need to take the maximum number of songs from first k-1 songs
    // so that the total singing time is equal to (tot - song[k]) seconds
    int op1 = (tot >= song[k]) ? dp(k - 1, tot - song[k]) + 1 : -INF;

    // we do not take the k-th song
    // we need to take the maximum number of songs from first k-1 songs
    // so that the total singing time is equal to tot seconds
    int op2 = dp(k - 1, tot);

    ans = max(op1, op2);

    return ans;
}

signed main() {

    int t; cin >> t;
    for (int test = 1; test <= t; test++) {
        cin >> n >> x;

        int sum = 0;

        for (int i = 1; i <= n; i++) {
            cin >> song[i];
            sum += song[i];
        }
        cout << "Case " << test << ": ";
        if (sum < x) {
            cout << n + 1 << " " << sum + 678 << endl;
            continue;
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= x; j++) {
                mem[i][j] = -1;
            }
        }
        int mx_song = 0;
        int mx_time = 0;
        for (int i = 1; i < x; i++) {
            int ans = dp(n, i);

            if (ans > mx_song) {
                mx_song = ans;
                mx_time = i;
            } else if (ans == mx_song) {
                mx_time = max(mx_time, i);
            }
        }
        cout << mx_song + 1 << " " << mx_time + 678 << endl;



    }
}