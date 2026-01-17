#include <bits/stdc++.h>

using namespace std;

int main() {
    string p1, p2;

    cin >> p1 >> p2;

    int ans = 1;

    for (int i = 0; i < 4; i++) {
        if (p1[i] != p2[i]) {
            ans *= 2;
        }
    }

    cout << ans << endl;

    return 0;
}