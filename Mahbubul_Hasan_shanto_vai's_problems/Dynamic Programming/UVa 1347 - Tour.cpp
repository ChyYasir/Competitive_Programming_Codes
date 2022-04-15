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