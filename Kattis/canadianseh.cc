#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    string eh = s.substr(s.length()-3);

    if (eh == "eh?") {
        cout << "Canadian!" << endl;
    } else {
        cout << "Imposter!" << endl;
    }

    return 0;
}