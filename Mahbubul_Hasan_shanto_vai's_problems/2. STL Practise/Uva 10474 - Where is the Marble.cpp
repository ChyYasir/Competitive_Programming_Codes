#include<bits/stdc++.h>

using namespace std;


int main() {

    int n, q;
    int cnt = 1;
    while (cin >> n >> q) {
        if (n == 0 && q == 0) break;
        vector<int> a(n);

        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());
        cout << "CASE# " << cnt++ << ":" << endl;
        while (q--) {
            int x; cin >> x;
            bool found = binary_search(a.begin(), a.end(), x);
            if (found) {
                auto it = lower_bound(a.begin(), a.end(), x);
                int ind = it - a.begin();

                cout << x << " found at " << ind + 1 << endl;
            }
            else {
                cout << x << " not found" << endl;
            }
        }
    }
}