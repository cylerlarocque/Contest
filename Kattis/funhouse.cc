#include <bits/stdc++.h>

using namespace std;

void solve(int col, int row, int houseNum) {
    //       row col
    char grid[20][20];
    int dir = -1;
    int r, c;

    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    int turn[128][4];
    turn['.'][0] = 0;
    turn['.'][1] = 1;
    turn['.'][2] = 2;
    turn['.'][3] = 3;
    turn['/'][0] = 1;
    turn['/'][1] = 0;
    turn['/'][2] = 3;
    turn['/'][3] = 2;
    turn['\\'][0] = 3;
    turn['\\'][1] = 2;
    turn['\\'][2] = 1;
    turn['\\'][3] = 0;

    // make the grid
    for (int r = 0; r < row; r++) {
        string line;
        cin >> line;
        for (int c = 0; c < col; c++) {
            grid[r][c] = line[c];
        }
    }

    // find the entrace
    for (int i = 1; i < col-1; i++) {
        // north wall
        if (grid[0][i] == '*') {
            dir = 2;
            r = 0;
            c = i;
        // south wall
        } else if (grid[row-1][i] == '*') {
            dir = 0;
            r = row-1;
            c = i;
        }
    }
    for (int i = 1; i < row-1; i++) {
        // east wall
        if (grid[i][col-1] == '*') {
            dir = 3;
            r = i;
            c = col-1;
        // west wall
        } else if (grid[i][0] == '*') {
            dir = 1;
            r = i;
            c = 0;
        }
    }

    // START!!
    while (grid[r][c] != 'x') {
        r += dr[dir];
        c += dc[dir];
        dir = turn[grid[r][c]][dir];
    }

    grid[r][c] = '&';

    cout << "HOUSE " << houseNum << endl;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
}

int main() {
    int c, r;
    cin >> c >> r;

    int houseNum = 0;

    while (c != 0 && r != 0) {
        houseNum++;
        solve(c, r, houseNum);
        cin >> c >> r;
    }

    return 0;
}