#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> chart(n);

    for (auto &x : chart) {
        int chartSpot;
        cin >> chartSpot;

        x = chartSpot;
    }

    int minimum = chart[n-1];
    set<int> ans;

    for (int i = n-2; i >= 0; i--) {
        if (chart[i] > minimum) {
            ans.insert(chart[i]);
        } else {
            minimum = chart[i];
        }
    }

    cout << ans.size() << endl;
    for (auto a : ans) {
        cout << a << endl;
    }
}

int main() {
    int N;
    cin >> N;

    while (N--) {
        solve();
    }

    return 0;
}