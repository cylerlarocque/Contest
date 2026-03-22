#include <bits/stdc++.h>

using namespace std;


// THE FOLLOWING SOLUTION IS O(n!)
/* 
typedef pair<int,int> pii;

int dist(pii &b1, pii &b2) {
    auto [xi, yi] = b1;
    auto [xj, yj] = b2;
    return abs(xi - xj) + abs(yi - yj);
}

void solve() {
    int X, Y;
    cin >> X >> Y;

    pii start;
    cin >> start.first >> start.second;

    int n;
    cin >> n;

    pii beepers[11];

    for (int i = 1; i <= n; i++) {
        cin >> beepers[i].first >> beepers[i].second;
    }

    int order[10];
    iota(order, order+n, 1);

    int ans = INT_MAX;

    do {
        int d = dist(start, beepers[order[0]]);
        for (int i = 1; i < n; i++) {
            d += dist(beepers[order[i-1]], beepers[order[i]]);
        }
        d += dist(beepers[order[n-1]], start);

        ans = min(ans, d);
    } while (next_permutation(order, order+n));

    cout << ans << endl;

    return;
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        solve();
    }

    return 0;
}
*/

typedef pair<int,int> pii;

int n;
pii p[11];

int mem[11][2048];

int dist(int p1, int p2) {
    auto [xi, yi] = p[p1];
    auto [xj, yj] = p[p2];
    return abs(xi - xj) + abs(yi - yj);
}

int f(int v, int remset) {
    if (mem[v][remset] != -1) {
        return mem[v][remset];
    }

    if (!remset) {
        return dist(v, 0);
    }

    int ans = INT_MAX;
    for (int i = 1; i <= n; i++) {
        if (remset & (1 << i)) {
            ans = min(ans, dist(v, i) + f(i, remset - (1 << i)));
        }
    }

    return mem[v][remset] = ans;
}

void solve() {
    int X, Y;
    cin >> X >> Y;


    cin >> p[0].first >> p[0].second;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].first >> p[i].second;
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < (1 << 11); j++) {
            mem[i][j] = -1;
        }
    }

    int ans = f(0, (1 << (n+1)) - 2);

    cout << ans << endl;
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        solve();
    }

    return 0;
}