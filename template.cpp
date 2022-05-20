#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp> // common file
#include<ext/pb_ds/tree_policy.hpp> // including tree_order_statistics_node_update

using namespace __gnu_pbds;


#define ll             long long
#define pb              push_back
#define ppb             pop_back
#define pf              push_front
#define ppf             pop_front
#define all(x)          (x).begin(), (x).end()
#define uniq(v)         (v).erase(unique(all(v)), (v).end())
#define sz(x)           (ll)((x).size())
#define ff              first
#define ss              second
#define rep(i, a, b)    for(ll i = a; i <= b; i++)
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


typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<pii> vpii;

#define ordered_set tree<ll, null_type, less<ll> , rb_tree_tag, tree_order_statistics_node_update>

const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;


ll binpow(ll a, ll b) {
    ll res = 1;
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
ll gcd(ll a, ll b) {if (b == 0) return a; return gcd(b, a % b);}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll mul(ll a, ll b) {return ((a % M) * (b % M)) % M;}


void KhelaFinal() {




}

signed main()
{
    fast_io();
//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//#endif
    ll t = 1;

    cin >> t;


    while (t--) {

        KhelaFinal();


    }
    return 0;


}
