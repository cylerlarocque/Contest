#include <bits/stdc++.h>

using namespace std;

void solve(int n) {
    vector<int> sl1(n);
    vector<int> sl2(n);
    map<int,int> correspondance;

    for(auto &x: sl1) {
        cin >> x;
    }
    for (auto &x: sl2) {
        cin >> x;
    }

    vector<int> ul1 = sl1;
    sort(sl1.begin(), sl1.end());
    sort(sl2.begin(), sl2.end());

    for (int i = 0; i < n; i++) {
        correspondance[sl1[i]] = sl2[i];
    }

    for (auto x : ul1) {
        cout << correspondance[x] << endl;
    }

    cout << endl;
}

int main() {
    int n;
    cin >> n;

    while (n != 0) {
        solve(n);

        cin >> n;
    }

    return 0;
}