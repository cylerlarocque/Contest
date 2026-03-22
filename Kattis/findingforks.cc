#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int min1 = INT_MAX;
    int min2 = INT_MAX;

    while(n--) {
        int x;
        cin >> x;

        if (x < min1) {
            min2 = min1;
            min1 = x;
        } else if (x < min2) {
            min2 = x;
        }
    }

    cout << min1 + min2 << endl;

    return 0;
}