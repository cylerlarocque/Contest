#include <bits/stdc++.h>

using namespace std;

int main() {
    int g, r;
    cin >> g >> r;
    
    int ans = 0;
    
    ans += min(g, r) * 10;
    g -= min(g, r);
    
    ans += (g/3) * 10;
    g %= 3;
    
    ans += (g/2) * 3;
    g %= 2;
    
    ans += g;

    cout << ans << endl;
    
    return 0;
}