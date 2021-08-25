#include<bits/stdc++.h>


using namespace std;

#define int         long long

const int N = 1000;
vector<int> g[N + 5];
int FT[2 * N + 5];

int Start[N + 5];
int End[N + 5];
int timer;


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

signed main() {


    int n; cin >> n;

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }
    timer = 1;
    dfs(1, -1);

    for (int i = 1; i <= n; i++) {
        cout << Start[i] << " ";
    }
    cout << endl;
    for (int i = 1; i <= n; i++) {
        cout << End[i] << " ";
    }
    cout << endl;
    for (int i = 1; i <= 2 * n; i++) {
        cout << FT[i] << " ";
    }
    cout << endl;
}