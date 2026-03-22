#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    while (n--) {
        bool ps = false, p = false;
        int k;
        cin >> k;
        cin.ignore();
        string name, item;
        getline(cin, name);
        
        while (k--) {
            getline(cin, item);
            if (item == "pea soup") {
                ps = true;
            } else if (item == "pancakes") {
                p = true;
            }
            
            if (ps && p) {
                cout << name << endl;
                return 0;
            }
        }
    }
    
    cout << "Anywhere is fine I guess" << endl; 
    
    return 0;
}