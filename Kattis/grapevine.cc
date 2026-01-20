// https://open.kattis.com/problems/grapevine

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, d;
    cin >> n >> m >> d;

    map<string,int> people;
    map<string, vector<string>> relation;

    for (int i = 0; i < n; i++) {
        string s;
        int t;
        cin >> s >> t;

        people[s] = t;
    }

    for (int i = 0; i < m; i++) {
        string u,v;
        cin >> u >> v;

        relation[u].push_back(v);
        relation[v].push_back(u);
    }

    string starter;
    cin >> starter;

    queue<string> rumorSpreaders;
    set<string> whoHeard;
    rumorSpreaders.push(starter);
    whoHeard.insert(starter);

    int ans = 0;

    for (int i = 0; i < d; i++) {
        vector<string> toTellTomorrow;

        while(rumorSpreaders.size() != 0) {
            string spreader = rumorSpreaders.front();
            rumorSpreaders.pop();

            for (auto &s : relation[spreader]) {
                if (whoHeard.find(s) == whoHeard.end()) {
                    whoHeard.insert(s);
                }

                people[s]--;
                if (people[s] == 0) {
                    toTellTomorrow.push_back(s);
                }
            }
        }

        for (auto &s: toTellTomorrow) {
            rumorSpreaders.push(s);
        }
    }

    cout << whoHeard.size() - 1 << endl;

    return 0;
}