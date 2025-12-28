#include <bits/stdc++.h>

using namespace std;

int main() {
    // C - Num Countries
    // P - Number of trading partnerships
    // X - The number of your home country
    // L - The number of the first country to leave
    int C, P, X, L;
    cin >> C >> P >> X >> L;

    vector<vector<int>> countryTrades(C+1);
    vector<int> numPartnersLeft(C+1, 0);
    vector<bool> stay(C+1, true);

    for (int i = 0; i < P; i++) {
        int c1, c2;
        cin >> c1 >> c2;

        countryTrades[c1].push_back(c2);
        countryTrades[c2].push_back(c1);
    }

    queue<int> leaving;
    leaving.push(L);
    stay[L] = false;
    while(!leaving.empty()) {
        int leave = leaving.front();
        leaving.pop();

        for (auto c : countryTrades[leave]) {
            if (!stay[c]) continue;
            numPartnersLeft[c]++;
            if (numPartnersLeft[c]*2 >= countryTrades[c].size()) {
                stay[c] = false;
                leaving.push(c);
            }
        }
    }

    if (stay[X]) {
        cout << "stay" << endl;
    } else {
        cout << "leave" << endl;
    }
    
    return 0;
}