#include <bits/stdc++.h>

using namespace std;

int main() {
    int w, h;
    cin >> w >> h;

    double rectangle = w + h;
    double diagonal = w*w + h*h;

    cout << fixed << setprecision(10) << rectangle - sqrt(diagonal) << endl;

    return 0;
}