// o(n^3) solution

#include<bits/stdc++.h>

using namespace std;
#define debug(x)        cerr << #x << " == " << (x) << '\n';

struct Point {
    int x, y;
};
const int N = 500;
vector<Point> p;
int n;

double mem[N][N][N];


double dis(Point a, Point b) {
    double ans = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    ans = sqrt(ans);
    return ans;
}
double dp(int pos, int right, int left) {

    if (pos == n - 1) {
        return dis(p[right], p[n - 1]) + dis(p[n - 1], p[left]);
    }
    double &ans = mem[pos][right][left];
    if (ans != -1) return ans;

    double op1 = dp(pos + 1, pos, left) + dis(p[right], p[pos]); // take the point while going right
    double op2 = dp(pos + 1, right, pos) + dis(p[left], p[pos]); // take the point while going left

    ans = min(op1, op2);
    return ans;
}

int main() {


    while (cin >> n) {
        p.clear();

        for (int i = 0; i < n; i++) {
            int x, y; cin >> x >> y;
            p.push_back({x, y});
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    mem[i][j][k] = -1;
                }
            }
        }

        double ans = dp(1, 0, 0);
        printf("%.2f\n", ans);

    }
}


//o(n^2) solution

#include<bits/stdc++.h>
using namespace std;

#define int long long


const int N = 1005;
struct point {
    int x, y;
};
int n;
vector<point> p;
double mem[N][N];
double dist(point a, point b) {

    double ans = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    ans = sqrt(ans);
    return ans;
}

double dp(int i, int j) {
    // current position of first path is i-th point
    // current position of second path is j-th point
    if (i == (n - 1)) {
        return dist(p[j], p[n - 1]);
    }

    if (j == (n - 1)) {
        return dist(p[i], p[n - 1]);
    }
    double &ans = mem[i][j];

    if (ans != -1) return ans;

    int k = max(i, j) + 1; // next point to go

    // go to the k-th point from i-th point in the first path
    double op1 = dp(k, j) + dist(p[i], p[k]);

    // go to the k-th point from j-th point in the second path
    double op2 = dp(i, k) + dist(p[j], p[k]);

    ans = min(op1, op2);
    return ans;
}
signed main() {

    while (cin >> n) {
        p.clear();
        for (int i = 0; i < n; i++) {
            int x, y; cin >> x >> y;
            p.push_back({x, y});
        }

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                mem[i][j] = -1;
            }
        }

        printf("%.2f\n", dp(0, 0));
    }
    return 0;
}
