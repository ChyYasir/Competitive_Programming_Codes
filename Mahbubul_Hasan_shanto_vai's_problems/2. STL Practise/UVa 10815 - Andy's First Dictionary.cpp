#include<bits/stdc++.h>

using namespace std;

#define debug(x)        cerr << #x << " == " << (x) << '\n';
int main() {

    string s;
    set<string> dict;

    map<string, int> cnt;
    while (getline(cin, s)) {

        for (int i = 0; i < s.size(); i++) {
            string t = "";
            while (i < s.size() && ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))) {
                s[i] = tolower(s[i]);
                t.push_back(s[i]);
                i++;
            }
            if (t != "") dict.insert(t);

        }
    }

    for (string x : dict) {
        cout << x << endl;
    }


}