#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
vector<int> g[N];

bool comparePairs(pair<int, int> &a, pair<int, int> &b) {
    if (a.first != b.first) {
        return a.first > b.first;
    }
    return a.second > b.second;
}


int mem[N][2];
int dfs(int cur, int par, int taken) {


    // if it is already calculated return it
    if (mem[cur][taken] != -1) return mem[cur][taken];


    vector<pair<int, int>> differences;

    int ans = 0;
    for (int child : g[cur]) {

        if (child != par) {

            if (taken) {
                // as the current node is taken , we cannot take any child.
                // as it will taken the current node again
                ans += dfs(child, cur, 0);

            } else {

                // i can only take one of the child in one edge for this current node
                // for other child i cannot take them.
                // op1 = number of maximum edge matching in the child's subtree if i do take the child in the edge.
                // op2 = number of maximum edge matching in the child's subtree if i do not take the child in the edge.


                int op1 = dfs(child, cur, 1) + 1;
                int op2 = dfs(child, cur, 0);

                int diff = op1 - op2;

                differences.push_back({diff, op2});
            }
        }
    }
    if (differences.size()) {

        sort(differences.begin(), differences.end(), comparePairs);

        // here , i will take that child who will contribute more if i take it in the edge rather than not taking it.
        ans = differences[0].first + differences[0].second;

        // i can only afford one edge involving the current node, hence can only take one child for the current node.
        // for the rest of the child , i will not take them in the edge, as i can take only one child in the edge.
        for (int i = 1; i < (int)differences.size(); i++) {
            ans += differences[i].second;
        }

    }

    // save the answer before returning it
    mem[cur][taken] = ans;
    return ans;






}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        mem[i][0] = -1;
        mem[i][1] = -1;
    }
    for (int i = 1; i <= n - 1; i++) {
        int u, v; cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);

    }

    // dfs(cur, -1, 0) --> what is the maximum edge matching if i don't take the current node in any previous edge
    // dfs(cur, -1, 1) --> what is the maximum edge matching if i take the current node in any previous edge
    cout << dfs(1, -1, 0) << "\n";
}