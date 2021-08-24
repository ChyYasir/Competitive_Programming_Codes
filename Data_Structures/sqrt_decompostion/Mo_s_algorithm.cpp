#include<bits/stdc++.h>

using namespace std;

#define int             long long
#define endl            "\n"
void fast_io()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
const int blk_size = 550; // sqrt(3e5)
int n, q;

vector<int> a, ans;

struct Query {
    int l, r, idx, blk_no;
    bool operator <(Query other) const
    {
        if ((blk_no) != (other.blk_no)) return blk_no < other.blk_no; // smaller blocks first

        // otherwise for Even blocks sort in ascending order , for Odd blocks sort in descending order
        return (blk_no & 1) ? (r < other.r) : (r > other.r);
    }
};

vector<Query> queries;

int cur_ans;;
int occ[(int)1e6 + 5];

// TODO : add value at idx and update cur_ans
void add(int idx) {
    cur_ans -= (occ[a[idx]] * occ[a[idx]] * a[idx]);
    occ[a[idx]]++;
    cur_ans += (occ[a[idx]] * occ[a[idx]] * a[idx]);

}

// TODO : remove value at idx and update cur_ans
void remove(int idx) {
    cur_ans -= (occ[a[idx]] * occ[a[idx]] * a[idx]);
    occ[a[idx]]--;
    cur_ans += (occ[a[idx]] * occ[a[idx]] * a[idx]);

}

// return the ans for current range
int get_ans() {
    return cur_ans;
}
void mo_s_algo() {
    sort(queries.begin(), queries.end());

    int cur_l = 0;
    int cur_r = -1;

    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        ans[q.idx] = get_ans();
    }

}
signed main() {

    fast_io();
    cin >> n;

    cin >> q;
    ans.resize(q);

    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < q; i++) {
        int idx_l, idx_r; cin >> idx_l >> idx_r;
        idx_l--;
        idx_r--;
        queries.push_back({idx_l, idx_r, i, idx_l / blk_size});


    }
    cur_ans = 0;
    mo_s_algo();

    for (int i = 0; i < q; i++) cout << ans[i] << endl;

    return 0;
}