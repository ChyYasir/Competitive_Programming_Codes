#include<bits/stdc++.h>

using namespace std;


#define int long long
const int INF = 1e18;
struct info {
    int voltage;
    int cost_v;
    int cost_l;
    int lamp_num;
};

bool compare(info x, info y) {
    if (x.voltage != y.voltage) {

        return (x.voltage > y.voltage);
    }
    return x.cost_v < y.cost_v;
}
vector<info> a;

int mem[1005][15];
int n;

int dp(int i, int prv) {

    if (i == n) {
        return 0;
    }

    int &ans = mem[i][prv];

    if (ans != -1) return ans;

    // take this source
    int op1 = a[i].cost_v + (a[i].lamp_num * a[i].cost_l) + dp(i + 1, a[i].cost_l);
    // do not take the source
    int op2 = (a[i].lamp_num * prv) + dp(i + 1, prv);

    ans = min(op1, op2);
    return ans;
}
signed main() {


    while (cin >> n) {
        if (n == 0) break;
        a.clear();
        for (int i = 0; i < n; i++) {
            int m, n, o, p; cin >> m >> n >> o >> p;
            a.push_back({m, n, o, p});
        }

        sort(a.begin(), a.end(), compare);

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= 12; j++) {
                mem[i][j] = -1;
            }
        }

        for (int i = 0; i < n; i++) {
            int start = i;
            int end;
            int tot = 0;
            while (i < n && (a[i].voltage == a[start].voltage)) {
                tot += a[i].lamp_num; // total number of lamps of this voltage rating

                i++;
            }
            i--;
            end = i;

            int replace;
            int mn = INF;
            for (int j = start; j <= end; j++) {

                if ((a[j].cost_v + (a[j].cost_l * tot)) < mn) {
                    mn = a[j].cost_v + (a[j].cost_l * tot);
                    replace = j;
                }
            }

            // replacing all category of this voltage with minimum cost
            for (int j = start; j <= end; j++) {
                a[j].cost_v = a[replace].cost_v;
                a[j].cost_l = a[replace].cost_l;
            }
        }

        cout << a[0].cost_v + (a[0].lamp_num * a[0].cost_l) + dp(1, a[0].cost_l) << endl;




    }




}