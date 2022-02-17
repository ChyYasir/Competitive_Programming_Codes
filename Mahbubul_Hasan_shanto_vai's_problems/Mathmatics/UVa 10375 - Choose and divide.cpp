#include<bits/stdc++.h>


using namespace std;


#define int long long

void fast_io()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

signed main() {
    // fast_io();

    int p, q, r, s;

    while (cin >> p >> q >> r >> s) {

        double ans = 1;

        int diff1 = p - q;
        int diff2 = r - s;

        int mx1 = max(diff1, q);
        int mx2 = max(diff2, s);
        int mn1 = min(diff1, q);
        int mn2 = min(diff2, s);

        vector<double> numerator, denominator;

        for (int i = p; i >= mx1 + 1; i--) {
            numerator.push_back(i);
        }

        for (int i = 2; i <= mn2; i++) {
            numerator.push_back(i);
        }

        for (int i = 2; i <= mn1; i++) {
            denominator.push_back(i);
        }

        for (int i = r; i >= mx2 + 1; i--) {
            denominator.push_back(i);
        }

        sort(numerator.begin(), numerator.end());
        reverse(numerator.begin(), numerator.end());
        sort(denominator.begin(), denominator.end());
        reverse(denominator.begin(), denominator.end());

        int sz = min((int)numerator.size(), (int)denominator.size());
        for (int i = 0; i < sz; i++) {
            ans *= ((double)numerator[i] / denominator[i]);
        }

        if ((int)numerator.size() > sz) {
            for (int i = sz; i < (int)numerator.size(); i++) {
                ans *= numerator[i];
            }
        }

        if ((int)denominator.size() > sz) {
            for (int i = sz; i < (int)denominator.size(); i++) {
                ans /= denominator[i];
            }
        }
        printf("%.5f\n", ans);

    }


}
