#include<bits/stdc++.h>

using namespace std;
#define debug(x)        cerr << #x << " == " << (x) << '\n';

char grid[11][10];

int n, bx, by;

bool piece(char c) {
    c = tolower(c);
    if (c == 'g' || c == 'r' || c == 'h' || c == 'c' || c == 'b') {
        return true;
    }
    return false;
}

bool unchecked(char c) {
    if (c == 'G' || c == 'R' || c == 'H' || c == 'C') {
        return true;
    }
    return false;
}
void general_walk(int r, int c) {


    for (int i = r - 1; i >= 1; i--) {

        char &x = grid[i][c];
        if (tolower(x) == 'b') continue;
        if (piece(x)) {
            x = tolower(x);
            break;
        }
        else {
            x = '*';
        }
    }
}

void chariot_walk(int r, int c) {

    for (int i = r - 1; i >= 1; i--) {

        char &x = grid[i][c];
        if (tolower(x) == 'b') continue;

        if (piece(x)) {
            x = tolower(x);
            break;
        }
        else {
            x = '*';
        }
    }

    for (int i = r + 1; i <= 10; i++) {
        char &x = grid[i][c];

        if (tolower(x) == 'b') continue;
        if (piece(x)) {
            x = tolower(x);
            break;
        }
        else {
            x = '*';
        }
    }

    for (int i = c - 1; i >= 1; i--) {
        char &x = grid[r][i];
        if (tolower(x) == 'b') continue;
        if (piece(x)) {
            x = tolower(x);
            break;
        }
        else {
            x = '*';
        }
    }

    for (int i = c + 1; i <= 9; i++) {

        char &x = grid[r][i];
        if (tolower(x) == 'b') continue;
        if (piece(x)) {
            x = tolower(x);
            break;
        }
        else {
            x = '*';
        }
    }
}

void cannon_walk(int r, int c) {
    bool first = 0;
    for (int i = r - 1; i >= 1; i--) {
        bool p = 0;
        char &x = grid[i][c];
        // debug(i);
        if (!first) {
            if (piece(x) && tolower(x) != 'b') first = true;
        }
        else {
            if (tolower(x) == 'b') {
            }
            else if (piece(x)) {
                p = 1;
                x = tolower(x);
                break;
            }
            else {
                x = '*';
            }

        }
        // debug(p);
        if (p) {
            // cout << "adios" << endl;
            break;
        }
    }

    first = 0;
    for (int i = r + 1; i <= 10; i++) {
        bool p = 0;
        char &x = grid[i][c];
        if (!first) {
            if (piece(x) && tolower(x) != 'b') first = true;
        }
        else {
            if (tolower(x) == 'b') {
            }
            else if (piece(x)) {
                p = 1;
                x = tolower(x);
                break;
            }
            else {
                x = '*';
            }

        }
        if (p) break;
    }
    first = 0;
    for (int i = c - 1; i >= 1; i--) {
        bool p = 0;
        char &x = grid[r][i];
        if (!first) {
            if (piece(x) && tolower(x) != 'b') {
                first = true;
            }
        }
        else {
            if (tolower(x) == 'b') {
            }
            else if (piece(x)) {
                p = 1;
                x = tolower(x);
                break;
            }
            else {
                x = '*';
            }

        }
        if (p) break;
    }

    first = 0;
    for (int i = c + 1; i <= 9; i++) {
        bool p = 0;
        char &x = grid[r][i];
        if (!first) {
            if (piece(x) && tolower(x) != 'b') {
                first = true;
            }
        }
        else {
            if (tolower(x) == 'b') {
            }
            else if (piece(x)) {
                p = 1;
                x = tolower(x);
                break;
            }
            else {
                x = '*';
            }

        }
        if (p) break;
    }

}

bool is_valid(int r, int c) {

    if (r >= 1 && r <= 10 && c >= 1 && c <= 9) return true;
    return false;
}

void horse_walk(int r, int c) {

    if (is_valid(r - 1, c) && !piece(grid[r - 1][c])) {
        int dx[] = { -2, -2};
        int dy[] = { -1, 1};

        for (int i = 0; i < 2; i++) {
            int tx = r + dx[i];
            int ty = c + dy[i];

            if (is_valid(tx, ty)) {
                if (piece(grid[tx][ty])) {
                    grid[tx][ty] = tolower(grid[tx][ty]);
                }
                else {
                    grid[tx][ty] = '*';
                }
            }
        }
    }

    if (is_valid(r + 1, c) && !piece(grid[r + 1][c])) {
        int dx[] = {2, 2};
        int dy[] = { -1, 1};

        for (int i = 0; i < 2; i++) {
            int tx = r + dx[i];
            int ty = c + dy[i];

            if (is_valid(tx, ty)) {
                if (piece(grid[tx][ty])) {
                    grid[tx][ty] = tolower(grid[tx][ty]);
                }
                else {
                    grid[tx][ty] = '*';
                }
            }
        }
    }

    if (is_valid(r, c + 1) && !piece(grid[r][c + 1])) {
        int dx[] = {1, -1};
        int dy[] = {2, 2};

        for (int i = 0; i < 2; i++) {
            int tx = r + dx[i];
            int ty = c + dy[i];

            if (is_valid(tx, ty)) {
                if (piece(grid[tx][ty])) {
                    grid[tx][ty] = tolower(grid[tx][ty]);
                }
                else {
                    grid[tx][ty] = '*';
                }
            }
        }
    }


    if (is_valid(r, c - 1) && !piece(grid[r][c - 1])) {
        int dx[] = {1, -1};
        int dy[] = { -2, -2};

        for (int i = 0; i < 2; i++) {
            int tx = r + dx[i];
            int ty = c + dy[i];

            if (is_valid(tx, ty)) {
                if (piece(grid[tx][ty])) {
                    grid[tx][ty] = tolower(grid[tx][ty]);
                }
                else {
                    grid[tx][ty] = '*';
                }
            }
        }
    }
}
int main() {

    while (cin >> n >> bx >> by) {

        if (n == 0 && bx == 0 && by == 0) break;
        for (int i = 1; i <= 10; i++) {
            for (int j = 1; j <= 9; j++) {
                grid[i][j] = '.';
            }
        }
        grid[bx][by] = 'B';

        for (int i = 0; i < n; i++) {
            char c;
            int x, y;
            cin >> c >> x >> y;
            grid[x][y] = c;
        }
        string s;
        getline(cin, s);

        for (int i = 1; i <= 10; i++) {
            for (int j = 1; j <= 9; j++) {
                if (tolower(grid[i][j]) == 'g') general_walk(i, j);
                if (tolower(grid[i][j]) == 'r') chariot_walk(i, j);
                if (tolower(grid[i][j]) == 'h') horse_walk(i, j);
                if (tolower(grid[i][j]) == 'c') cannon_walk(i, j);
            }
        }

        // for (int i = 1; i <= 10; i++) {
        //     for (int j = 1; j <= 9; j++) {
        //         cout << grid[i][j];
        //     }
        //     cout << endl;
        // }

        // cout << endl;

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        bool ok = 1;
        for (int i = 0; i < 4; i++) {
            int tx = bx + dx[i];
            int ty = by + dy[i];
            if (tx >= 1 && tx <= 3 && ty >= 4 && ty <= 6) {
                // debug(tx);
                // debug(ty);
                if (grid[tx][ty] == '.' || unchecked(grid[tx][ty])) {
                    ok = 0;
                    break;
                }
            }
            if (!ok) break;
        }

        for (int i = bx + 1; i <= 10; i++) {
            bool br = 0;
            if (piece(grid[i][by])) {

                if (tolower(grid[i][by]) == 'g') {
                    ok = 0;

                }
                else {
                    br = 1;
                    break;
                }
            }
            if (br) break;
        }
        if (!ok) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }


    }


}