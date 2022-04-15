#include<bits/stdc++.h>

using namespace std;
#define debug(x)        cerr << #x << " == " << (x) << '\n';
struct block {
    int l, w, h;
};

const int N = 30 * 6 + 5;

vector<block> a;

int mem[N];

int n;
int dp(int pos) {

    int &ans = mem[pos];

    if (ans != -1) return ans;

    int op1 = 0;


    for (int i = 0; i < 6 * n; i++) {

        if ((i != pos) && (a[i].l < a[pos].l && a[i].w < a[pos].w)) {
            // if the block is smaller than current one than take it

            op1 = max(op1, dp(i) + a[i].h);


        }

    }


    ans = op1;
    return ans;
}

int main() {

    int cnt = 1;
    while (cin >> n) {
        if (n == 0) break;
        a.clear();
        for (int i = 0;  i < n; i++) {
            int l, w, h; cin >> l >> w >> h;
            // even if the number of particular block is infinite we just have to take one occurance because
            // each block is lesser than the downward block

            // to get rid from rotation we take every possible block

            a.push_back({l, w, h});
            a.push_back({w, l, h});
            a.push_back({l, h, w});
            a.push_back({h, l, w});
            a.push_back({w, h, l});
            a.push_back({h, w, l});
        }

        for (int i = 0; i <= n * 6; i++) {
            mem[i] = -1;
        }

        int ans = 0;
        for (int i = 0; i < 6 * n; i++) {
            ans = max(ans, dp(i) + a[i].h); // base block
        }
        cout << "Case " << cnt++ << ": maximum height = " << ans << endl;

    }

}