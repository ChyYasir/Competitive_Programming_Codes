#include<bits/stdc++.h>

using namespace std;
#define debug(x)        cerr << #x << " == " << (x) << '\n';
int main() {


    string s, t;
    while (cin >> s) {
        cin >> t;
        map<char, int> cnt_s, cnt_t;
        set<char> unique_s, unique_t;
        for (char c : s) {
            cnt_s[c]++;
            unique_s.insert(c);
        }
        for (char c : t) {
            cnt_t[c]++;
            unique_t.insert(c);
        }

        vector<int> occ_s, occ_t;
        for (char c : unique_s) {
            occ_s.push_back(cnt_s[c]);
        }

        for (char c : unique_t) {
            occ_t.push_back(cnt_t[c]);
        }
        sort(occ_s.begin(), occ_s.end());
        sort(occ_t.begin(), occ_t.end());
        int n = occ_s.size();
        int m = occ_t.size();
        if (n != m) {
            cout << "NO" << endl;
            continue;
        }
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (occ_s[i] != occ_t[i]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}