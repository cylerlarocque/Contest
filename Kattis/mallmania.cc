#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int grid[2001][2001]; // 0? hasn't checked yet. 1? checked. 2? mall location

int solve(int _p1) {
    for (int i = 0; i < 2001; i++) {
        for (int j = 0; j < 2001; j++) {
            grid[i][j] = 0;
        }
    }

    int p1, p2;
    p1 = _p1;

    queue<pii> q;

    for (int i = 0; i < p1; i++) {
        int x, y;
        cin >> x >> y;

        pii p = make_pair(x,y);
        q.push(p);
        grid[p.first][p.second] = 1;
    }

    cin >> p2;
    for (int i = 0; i < p2; i++) {
        int x, y;
        cin >> x >> y;
        grid[x][y] = 2;
    }

    int iter = 1; // increment this each bfs step

    while (iter < 4001) {
        vector<pii> to_add;

        while (!q.empty()) {
            pii p = q.front();
            q.pop();
    
            for (int i = 0; i < 4; i++) {
                pii check = make_pair(p.first+dx[i], p.second+dy[i]);
                if (check.first < 0 || check.first > 2000 || check.second < 0 || check.second > 2000 || grid[check.first][check.second] == 1)
                    continue;
    
                if (grid[check.first][check.second] == 2)
                    return iter;
    
                to_add.push_back(check);
                grid[check.first][check.second] = 1;
            }
        }
        for (auto p : to_add) {
            q.push(p);
        }
        iter++;
    }

    return -1;
}

int main() {
    int p1;
    cin >> p1;

    do {
        cout << solve(p1) << endl;
        cin >> p1;
    } while (p1);

    return 0;
}