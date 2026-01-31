#include <bits/stdc++.h>

using namespace std;

typedef pair<double,double> pdd;

vector<pdd> houses;

double f(double x) {
    double ans = 0;

    for (auto &h : houses) {
        ans = max(ans, hypot(h.first - x, h.second));
    }

    return ans;
}

void solve(int n) {
    houses.clear();
    houses.resize(n);

    for (auto &h : houses) {
        cin >> h.first;
        cin >> h.second;
    }

    // ternary search for answer
    double left = -200000.0;
    double right = 200000.0;
    double mid1 = left + (right - left) / 3;
    double mid2 = right - (right - left) / 3;

    while (mid2 - mid1 > 1e-6) {
        if (f(mid1) < f(mid2)) {
            right = mid2;
        } else {
            left = mid1;
        }

        mid1 = left + (right - left) / 3;
        mid2 = right - (right - left) / 3;
    }

    cout << fixed << setprecision(10) << mid1 << " " << f(mid1) << endl;
}

int main() {
    int n;
    cin >> n;

    while (n) {
        solve(n);
        cin >> n;
    }

    return 0;
}