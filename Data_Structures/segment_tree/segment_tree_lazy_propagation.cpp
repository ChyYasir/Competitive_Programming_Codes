#include<bits/stdc++.h>

using namespace std;
#define debug(x)        cerr << #x << " == " << (x) << '\n';

void fast_io()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
const int N = 1e5 + 5;


int t[4 * N];
// this stores the sum

int a[N];

bool lazy[4 * N];
int upd[4 * N];


// merging two nodes
int merge(int a, int b) {
    return a + b;
}

void apply(int node, int tl, int tr, int val) {
    t[node] += (tr - tl + 1) * val;

    if (tl != tr) {

        lazy[node] = true; // mark it lazy

        upd[node] += val;

    }
}

void push_down(int node, int tl, int tr) {

    if (lazy[node]) {
        lazy[node] = false;
        int tm = tl + (tr - tl) / 2;

        apply(2 * node, tl, tm, upd[node]); // propagate the value to the left child
        apply(2 * node + 1, tm + 1, tr, upd[node]); // propagate the value to the right child

        upd[node] = 0; // no more values to propagate

    }
}
void build(int node, int tl, int tr) {
    if (tl == tr) {
        t[node] = a[tl];
        lazy[node] = 0;
        upd[node] = 0;
        return;
    }
    lazy[node] = 0;
    upd[node] = 0;
    int tm = tl + (tr - tl) / 2;

    build(2 * node, tl, tm);
    build(2 * node + 1, tm + 1, tr);

    t[node] = merge(t[2 * node] , t[2 * node + 1]);
}

void update(int node, int tl, int tr, int l, int r, int val) {

    if (tl > r || tr < l) {
        return;
    }

    if (tl >= l && tr <= r) {
        apply(node, tl, tr, val);
        return ;

    }
    push_down(node, tl, tr); // we remove the lazy tag before going down
    // so that the children have correct information


    int tm = tl + (tr - tl) / 2;
    update(2 * node, tl, tm, l, r, val);
    update(2 * node + 1, tm + 1, tr, l, r, val);

    t[node] = merge(t[2 * node], t[2 * node + 1]);


}

int query(int node, int tl, int tr, int l, int r) {

    if (tl > r || tr < l) { // no overlap
        return 0;
    }
    if (tl >= l && tr <= r) { // fully overlap
        return t[node];
    }
    push_down(node, tl, tr); // we remove lazy tag before going down
    // so that the children have correct information

    int tm = tl + (tr - tl) / 2;

    int left = query(2 * node, tl, tm, l, r);
    int right = query(2 * node + 1, tm + 1, tr, l, r);

    return merge(left, right);
}


int main() {
    fast_io();

    int t; cin >> t;

    for (int i = 1; i <= t; i++) {

        string s; cin >> s;
        int n = s.size();
        build(1, 0, n - 1);

        cout << "Case " << i << ":" << endl;
        int q; cin >> q;
        while (q--) {
            char c; cin >> c;

            if (c == 'I') {
                int l, r; cin >> l >> r;
                l--;
                r--;
                update(1, 0, n - 1, l, r, 1);
            }
            else {
                int x; cin >> x;
                x--;
                int val = query(1, 0, n - 1, x, x);
                // debug(val);
                if (val & 1) {
                    // the bit is flipped

                    if (s[x] == '0') cout << '1' << endl;
                    else cout << '0' << endl;
                }
                else {
                    cout << s[x] << endl;
                }
            }
        }

    }
}