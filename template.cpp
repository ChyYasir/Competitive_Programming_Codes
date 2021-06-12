#include<bits/stdc++.h>
using namespace std;


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
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;


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


void solve() {




}

signed main()
{
    fast_io();
//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//#endif
    int t = 1;

    cin >> t;


    while (t--) {

        solve();


    }
    return 0;


}