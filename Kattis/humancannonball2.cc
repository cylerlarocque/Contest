#include <bits/stdc++.h>
#include <cmath>

using namespace std;

double pi = acos(-1);

void solve() {
    double v0, theta, x1, h1, h2;
    cin >> v0 >> theta >> x1 >> h1 >> h2;

    double t = x1 / (v0 * cos(theta*pi/180.0));

    double y = v0 * t * sin(theta*pi/180) - 0.5 * 9.81 * t * t;

    if (y >= h1+1 && y <= h2-1) {
        cout << "Safe" << endl;
    } else {
        cout << "Not Safe" << endl;
    }

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