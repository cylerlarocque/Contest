// https://open.kattis.com/problems/builddeps


// WIP

#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();

    map<string, set<string>> deps;

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);

        istringstream iss(line);
        string file;
        string dep;
        iss >> file;
        file.pop_back();

        while(iss >> dep) {
            deps[dep].insert(file);
        }
    }

    queue<string> changedFiles;
    set<string> seen;
    vector<string> answers;

    string file;
    cin >> file;
    changedFiles.push(file);

    // simulate
    while(changedFiles.size() > 0) {
        file = changedFiles.front();
        changedFiles.pop();

        if (seen.find(file) == seen.end()) {
            answers.push_back(file);
            for (auto s : deps[file]) {
                changedFiles.push(s);
            }
        }

        seen.insert(file);
    }

    for (auto s : answers) {
        cout << s << endl;
    }

    return 0;
}