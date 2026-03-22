#include <bits/stdc++.h>

using namespace std;

int main() {
    set<int> processed;
    vector<int> order;
    queue<int> to_remove;

    vector<int> in_degree(1'000'001, 0);
    vector<vector<int>> sticks_under(1'000'001);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        in_degree[b]++;
        sticks_under[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        if (!(in_degree[i])) {
            to_remove.push(i);
            order.push_back(i);
            processed.insert(i);
        }
    }

    while (to_remove.size()) {
        int x = to_remove.front();
        to_remove.pop();

        for (auto y: sticks_under[x]) {
            in_degree[y]--;

            if (in_degree[y] <= 0 && !(processed.count(y))) {
                processed.insert(y);
                to_remove.push(y);
                order.push_back(y);
            }
        }
    }

    if (order.size() == n) {
        for (auto x: order) {
            cout << x << endl;
        }
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}