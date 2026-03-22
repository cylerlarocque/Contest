#include <bits/stdc++.h>

using namespace std;

int main() {
    set<string> seen;
    map<string, int> scores;

    int n;
    cin >> n;

    scores["999"] = INT_MIN;
    string ans = "999";

    for (int i = 0; i < n; i++) {
        string name;
        int views;
        cin >> name >> views;

        if (seen.find(name) == seen.end()) {
            seen.insert(name);
            scores[name] = views;
        } else {
            scores[name] += views;
        }

        if (scores[name] > scores[ans]) {
            ans = name;
        }
    }

    cout << ans << endl;

    return 0;
}