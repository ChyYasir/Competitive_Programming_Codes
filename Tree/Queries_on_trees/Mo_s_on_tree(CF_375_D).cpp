#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp> // common file
#include<ext/pb_ds/tree_policy.hpp> // including tree_order_statistics_node_update

using namespace __gnu_pbds;


#define int             long long
#define pb              push_back
#define ppb             pop_back
#define pf              push_front
#define ppf             pop_front
#define all(x)          (x).begin(), (x).end()
#define uniq(v)         (v).erase(unique(all(v)), (v).end())
#define sz(x)           (int)((x).size())
#define ff              first
#define ss              second
#define rep(i, a, b)    for(int i = a; i <= b; i++)
#define mem1(a)         memset(a, -1, sizeof(a))
#define mem0(a)         memset(a, 0, sizeof(a))
#define endl            "\n"
#define debug(x)        cerr << #x << " == " << (x) << '\n';
#define YES             cout << "YES\n"
#define NO              cout << "NO\n"
#define nn              "\n"

// bit manipulation
#define SetBit(x, k)    (x |= (1LL << k))
#define ClearBit(x, k)  (x &= ~(1LL << k))
#define CheckBit(x, k)  (x & (1LL << k))


typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

#define ordered_set tree<int, null_type, less<int> , rb_tree_tag, tree_order_statistics_node_update>

const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;


int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = a * res;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}


void fast_io()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
int gcd(int a, int b) {if (b == 0) return a; return gcd(b, a % b);}
int lcm(int a, int b) {return a / gcd(a, b) * b;}



const int N = 1e5 + 5;


vi g[N];
int FT[2 * N];
int Start[N];
int End[N];
int timer;
int n, m;

int color[N];

// Tree Flattening , ETT
void dfs(int node, int par) {
    Start[node] = timer;
    FT[timer] = node;
    timer++;

    for (int child : g[node]) {
        if (child != par) {
            dfs(child, node);
        }
    }
    End[node] = timer;
    FT[timer] = node;
    timer++;
}

const int blk_size = 450;
struct Query {
    int l, r, idx, blk, k;

    bool operator<(Query &other) const
    {
        if (blk != other.blk) return blk < other.blk;
        return (blk & 1) ? (r < other.r) : (r > other.r);
    }
};
vector<Query> queries;
vector<int> ans;
set<int> s;
int freq[N] , ff[N] , node_freq[N];
int block[blk_size];


void add(int idx) {
    int node = FT[idx];
    node_freq[node]++;
    int cur_col = color[node];
    if (node_freq[node] == 2) {
        // this node is present in the subtree
        freq[cur_col]++; // count of current color
        int cnt  = freq[cur_col];
        ff[cnt - 1]--;
        block[(cnt - 1) / blk_size] -= 1; // it is enought to update the block sum

        ff[cnt]++;
        block[cnt / blk_size] += 1;

    }

}
void remove(int idx) {
    int node = FT[idx];
    node_freq[node]--;
    int cur_col = color[node];
    if (node_freq[node] == 1) {
        // this node is not present in the subtree
        freq[cur_col]--;
        int cnt = freq[cur_col];
        ff[cnt + 1]--;
        block[(cnt + 1) / blk_size]--;
        ff[cnt]++;
        block[cnt / blk_size]++;
    }
}

int get_ans(int k) {
    // 0(sqrt(N));
    int lb = k / blk_size;
    int rb = n / blk_size;
    int res = 0;
    if (lb == rb) {
        for (int i = k; i <= n; i++) res += ff[i];
    }
    else {
        for (int i = k; i <= ((lb + 1)*blk_size) - 1; i++) res += ff[i];

        for (int i = lb + 1; i < rb; i++) res += block[i];

        for (int i = rb * blk_size; i <= n; i++) res += ff[i];
    }
    return res;
}

// mo's algo
void mo_s_algo() {
    sort(queries.begin(), queries.end());

    int lft = 0;
    int rht = -1;

    for (Query q : queries) {
        // O(sqrt(N))
        while (lft > q.l) {
            lft--;
            add(lft);
        }
        while (lft < q.l) {
            remove(lft);
            lft++;
        }
        while (rht < q.r) {
            rht++;
            add(rht);
        }
        while (rht > q.r) {
            remove(rht);
            rht--;
        }

        ans[q.idx] = get_ans(q.k);
    }


}
void KhelaFinal() {


    // total time complexity : O((N + Q)* sqrt(N) + Q * sqrt(N));
    cin >> n >> m;

    ans.resize(m);
    for (int i = 1; i <= n; i++) cin >> color[i];

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;

        g[u].pb(v);
        g[v].pb(u);
    }

    timer = 1;
    dfs(1, -1);

    // pii range[n + 1];
    // for (int i = 1; i <= n; i++) range[i] = { -1, -1};
    // for (int i = 1; i <= 2 * n; i++) {
    //     int node = FT[i];
    //     if (range[node].ff == -1) {
    //         range[node].ff = i;
    //     }
    //     else {
    //         range[node].ss = i;
    //     }
    // }

    for (int i = 0; i < m; i++) {
        int v, k; cin >> v >> k;
        queries.pb({Start[v], End[v], i, Start[v] / blk_size, k});
    }


    // for (int i = 1; i <= 2 * n; i++) {
    //     int node = FT[i];
    //     FT[i] = color[node];
    // }

    mo_s_algo();

    for (int i = 0; i < m; i++) cout << ans[i] << endl;




}

signed main()
{
    fast_io();
//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//#endif
    int t = 1;

    // cin >> t;


    while (t--) {

        KhelaFinal();


    }
    return 0;


}