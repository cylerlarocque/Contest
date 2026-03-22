#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> n(4, 0);

    for (auto &x : n) {
        cin >> x;
    }

    sort(n.begin(), n.end());

    cout << n[0] * n[2] << endl;

    return 0;
}