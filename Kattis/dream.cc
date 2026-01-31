#include <bits/stdc++.h>

using namespace std;

stack<string> events;
map<string, int> when;

void event() {
    string event;
    cin >> event;
    events.push(event);
    when[event] = events.size();
}

void dream() {
    int d;
    cin >> d;
    while (d--) {
        when.erase(events.top());
        events.pop();
    }
}

void scenario() {
    int k;
    cin >> k;

    int include = -1;
    int exclude = INT_MAX;

    for (int i = 0; i < k; i++) {
        string s;
        cin >> s;

        if (s[0] != '!') {
            if (when.find(s) != when.end()) {
                include = max(include, when[s]);
            } else {
                include = INT_MAX;
            }
        } else {
            s = s.substr(1);

            if (when.find(s) != when.end()) {
                exclude = min(exclude, when[s]);
            }
        }
    }

    if (exclude <= include) {
        cout << "Plot Error" << endl;
    } else if (exclude != INT_MAX) {
        cout << events.size() - exclude + 1 << " Just A Dream" << endl;
    } else {
        cout << "Yes" << endl;
    }
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        char code;
        cin >> code;

        switch (code) {
            case 'E':
                event();
                break;
            case 'D':
                dream();
                break;
            default:
                scenario();
                break;
        }
    }

    return 0;
}