#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int numSevens = 0;
    
    for (int i = 0; i < n*3; i++) {
        int x;
        cin >> x;
        
        if (x == 7)
            numSevens++;
    }
    
    if (numSevens == 3) {
        cout << "777" << endl;
    } else {
        cout << "0" << endl;
    }
    
    return 0;
}