// incomplete

#include <bits/stdc++.h>

using namespace std;

int d[40];

int height[41][1001];
string ans[41][1001];

void f(int m, int h) {

    int temp = 99999999;

    // jump down to here
    f(m-1, h+d[m-1]);
    if (height[m-1][h+d[m-1]] != -9) {
        temp = min(temp, height[m-1][h+d[m-1]]);
        if (temp == height[m-1][h+d[m-1]]) {
            
        }
    }


    // go down, if you can
}

void solve() {
    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> d[i];
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 1001; j++) {
            height[i][j] = -1;
            ans[i][j] = "";
        }
    }

    f(m-1, 0);





}

int main() {
    int n;
    cin >> n;

    while (n--)
        solve();

    return 0;
}