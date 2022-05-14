#include<bits/stdc++.h>

using namespace std;

#define int             long long
#define debug(x)        cerr << #x << " == " << (x) << '\n';
#define endl            "\n"
void fast_io()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
const int INF = 1e18;
const int N = 2e5 + 5;

int t[4 * N];
int arr[N];

int merge(int a, int b) {
    return min(a, b);
}

void build(int node, int tl, int tr) {

    if (tl == tr) {

        t[node] = arr[tl];
        return;
    }
    int tm = tl + (tr - tl) / 2;

    build(2 * node , tl, tm);

    build(2 * node + 1, tm + 1, tr);
    t[node] = merge(t[2 * node ], t[2 * node + 1]);

}
void update(int node, int tl, int tr, int idx, int val) {

    if (idx == tl && idx == tr) {

        t[node] = val;
        return;

    }
    if (idx > tr || idx < tl) {

        return;
    }
    int tm = tl + (tr - tl) / 2;
    update(2 * node, tl, tm, idx, val);

    update(2 * node + 1, tm + 1, tr, idx, val);
    t[node] = merge(t[2 * node], t[2 * node + 1]);


}

int query(int node, int tl, int tr, int l, int r) {

    if (tl >= l && tr <= r) { // fully overlap
        return t[node];
    }
    if (tr < l || tl > r) { // no overlap
        return INF;
    }
    // partial overlap
    int tm = tl + (tr - tl) / 2;

    int lft = query(2 * node , tl, tm, l, r);
    int rht = query(2 * node + 1, tm + 1, tr, l, r);

    return merge(lft, rht);
}
signed main() {
    fast_io();
    int n, q; cin >> n >> q;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // debug(q);
    build(1, 0, n - 1);
    while (q--) {
        int x, a, b; cin >> x >> a >> b;

        if (x == 1) {
            a--;

            update(1, 0, n - 1, a, b);
        }
        else {
            a--;
            b--;
            cout << query(1, 0, n - 1, a, b) << endl;
        }

    }
    return 0;
}
