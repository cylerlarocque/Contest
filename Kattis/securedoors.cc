#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    set<string> here;
    cin >> n;

    while (n--) {
        string code, name;
        cin >> code >> name;

        if (code == "entry") {
            cout << name << " entered";

            if (here.count(name) > 0) {
                cout << " (ANOMALY)";
            }
            
            here.insert(name);
        } else {
            cout << name << " exited";
            
            if (here.count(name) == 0) {
                cout << " (ANOMALY)";
            }
            
            here.erase(name);
        }
        cout << endl;
    }


    return 0;
}