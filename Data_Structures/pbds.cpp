//...Bismillahir Rahmanir Rahim...

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

struct ordered_multiset { // multiset supporting duplicating values in set
    ll len = 0;
    const ll ADD = 1000010;
    const ll MAXVAL = 1000000010;
    unordered_map<ll, ll> mp; // hash = 96814
    tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> T;

    ordered_multiset() { len = 0; T.clear(), mp.clear(); }

    inline void insert(ll x) {
        len++, x += MAXVAL;
        ll c = mp[x]++;
        T.insert((x * ADD) + c);
    }

    inline void erase(ll x) {
        x += MAXVAL;
        ll c = mp[x];
        if (c) {
            c--, mp[x]--, len--;
            T.erase((x * ADD) + c);
        }
    }

    inline ll kth(ll k) {       // 1-based index,  returns the
        if (k < 1 || k > len) return -1; // K'th element in the treap,
        auto it = T.find_by_order(--k); // -1 if none exists
        return ((*it) / ADD) - MAXVAL;
    }

    inline ll lower_bound(ll x) {     // Count of value <x in treap
        x += MAXVAL;
        ll c = mp[x];
        return (T.order_of_key((x * ADD) + c));
    }

    inline ll upper_bound(ll x) {     // Count of value <=x in treap
        x += MAXVAL;
        ll c = mp[x];
        return (T.order_of_key((x * ADD) + c));
    }

    inline ll size() { return len; }   // Number of elements in treap
};

int main()
{
    indexed_set s1;
    ordered_multiset s2;


    s2.insert(2);
    s2.insert(2);
    s2.insert(3);

    cout << s2.kth(3) << endl;
    cout << s2.lower_bound(2) << endl;
    cout << s2.upper_bound(2) << endl;
    cout << s2.size() << endl;
    //  .. operations ..
    //  same ones as set..
    ///  extra: 1. s.order_of_key(x) // returns order of x;
    ///  extra: 2. s.find_by_order(K) // returns K-th element;

    return 0;
}
