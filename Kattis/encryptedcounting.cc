#include <bits/stdc++.h>

using namespace std;

string encrypt(string s) {
    string ans;
    int clen;

    for (int i = 0; i < s.length(); i += clen) {
        for(clen = 1; i+clen < s.length() && s[i] == s[i+clen]; clen++) {}

        ans += to_string(clen) + s[i];
    }

    return ans;
}

int main() {
    string s, c;
    cin >> s >> c;

    int ans = 0;

    while (s != c) {
        s = encrypt(s);
        ans++;
    }

    cout << ans << endl;

    return 0;
}