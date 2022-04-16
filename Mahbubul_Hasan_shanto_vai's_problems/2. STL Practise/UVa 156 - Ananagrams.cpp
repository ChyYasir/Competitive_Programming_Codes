#include<bits/stdc++.h>

using namespace std;

#define debug(x)        cerr << #x << " == " << (x) << '\n';
int main() {

    string s;
    vector<string> dict;

    map<string, int> cnt;
    while (cin >> s) {

        if (s == "#") break;
        dict.push_back(s);

        for (char &c : s) {
            c = tolower(c);
        }

        sort(s.begin(), s.end());
        cnt[s]++;
    }
    vector<string> ans;

    // checking letters with same occurance of characters appears more than once or not
    for (int i = 0; i < (int)dict.size(); i++) {
        string t = dict[i];
        for (char &c : t) {
            c = tolower(c);
        }


        sort(t.begin(), t.end());
        if (cnt[t] == 1) {
            ans.push_back(dict[i]);
        }
    }
    sort(ans.begin(), ans.end());
    for (string x : ans) {
        cout << x << endl;
    }
}