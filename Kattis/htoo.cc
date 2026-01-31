#include <bits/stdc++.h>

using namespace std;

void parse(string s, int freq[]) {
    istringstream iss(s);

    char atom;
    int count;

    while(iss >> atom) {
        if (!(iss >> count)) {
            count = 1;
            iss.clear();
        }
        freq[atom] += count;
    }
}

int main() {
    string sin, sout;
    int k;
    cin >> sin >> k >> sout;

    int infreq[128] = {0}, outfreq[128] = {0};

    parse(sin, infreq);
    parse(sout, outfreq);

    int ans = INT_MAX;

    for (int i = 0; i < 128; i++) {
        if (!outfreq[i])
            continue;
        
        int quo = (infreq[i]*k) / outfreq[i];
        ans = min(quo, ans);
    }

    cout << ans << endl;

    return 0;
}