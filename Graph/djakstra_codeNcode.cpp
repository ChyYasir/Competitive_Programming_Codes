#include<bits/stdc++.h>
using namespace std;


#define ff first
#define ss second
#define INF 1000000000


void djakstra(vector<pair<int, int>> g[], int src, int dis[]) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dis[src] = 0;
    pq.push({dis[src], src});
    while (!pq.empty()) {
        int curr = pq.top().ss;
        int curr_d = pq.top().ff;
        pq.pop();
        for (auto edge : g[curr]) {
            // edge.ss = weight of the edge curr-edge.ss
            // v ---> edge.ff
            // edge.ss = cost[curr][v]

            //if(dis[u] + cost[u][v] < dist[v]){
            //dist[v] = dis[u] + cost[u][v];
            //}
            if (curr_d + edge.ss < dis[edge.ff]) {
                dis[edge.ff] = curr_d + edge.ss;
                pq.push({dis[edge.ff], edge.ff});
            }
        }
    }

}
int main() {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    int t; cin >> t;
    int cnt = 1;
    while (t--) {
        int n, m, s, d; cin >> n >> m >> s >> d;
        vector<pair<int, int>> g[n + 10];
        for (int i = 0; i < m ; i++) {
            int a, b, w; cin >> a >> b >> w;
            g[a].push_back({b, w});
            g[b].push_back({a, w});
        }
        int dis[n + 10];
        for (int i = 0; i <= n; i++) dis[i] = INF;
        djakstra(g, s, dis);
        cout << "Case #" << cnt++ << ": ";
        if (dis[d] == INF) {
            cout << "unreachable" << endl;
        }
        else {
            cout << dis[d] << endl;
        }
        // for(int i = 0; i< n; i++) cout<< dis[i] << " ";
        // cout<< endl;

    }

}
