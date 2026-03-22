#include <bits/stdc++.h>

using namespace std;

int n, T;
int p[20], t[22], d[22];

int dist[22][22];

int mem[1<<21][22]; // mem[x][y]: min time to complete tasks x ending at task y 

// last will not be in subset
// f of subset of last means equals the minimum time it takes to complete all tasks
// of subset, AND last, ending on last
int f(int subset, int last) {
    if (subset == 0) {
        if (last == n) {
            return 0;
        }
        return INT_MAX;
    }
    if (mem[subset][last] != -1) {
        return mem[subset][last];
    }

    int running_min = INT_MAX;

    // find fastest way to 'last'
    for (int w = 0; w < n+1; w++) {
        if (subset & (1 << w)) { // if w is in S
            int sub_subset = f(subset & ~(1 << w), w);
            if (sub_subset == INT_MAX) {
                continue;
            }

            int time = sub_subset + dist[w][last] + t[last];
            if (time <= d[last] && time < running_min) {
                running_min = time;
            }
        }
    }

    // cout << "subset, last, t = " << subset << ' ' << last << ' ' << running_min << endl;
    return mem[subset][last] = running_min;
}

void solve() {
    // try all subsets, each including n, and the last being n+1.
    int max_points = 0;
    int indeces = 0;
    bool ans_found = false;

    for (int i = 0; i < (1 << n); i++) {
        int subset = i | (1 << n); // ensures n

        if (f(subset, n+1) <= T) {
            ans_found = true;
            int points = 0;
            for (int j = 0; j < n; j++) {
                if (subset & (1 << j)) {
                    points += p[j];
                }
            }

            if (points > max_points) {
                max_points = points;
                indeces = subset;
            }

            // tie check
            if (points == max_points) {
                for (int j = 0; j < n; j++) {
                    bool a = (subset & (1 << j));
                    bool b = (indeces & (1 << j)); 
                    if ((a || b) && !(a && b)) { // an edge is in one, but not the other
                        if (a) {
                            indeces = subset;
                        }
                        // else its in indeces already, so we have the smallest index
                        break;
                    }
                }
            }
        }
    }

    if (!ans_found) {
        cout << 0 << endl;
        return;
    }

    cerr << "ANSWER: " << endl;
    cout << max_points << endl;
    
    for (int i = 0; i < n; i++) {
        if (indeces & (1 << i)) {
            cout << i+1 << " ";
        }
    }
    cout << endl;
}

int main() {
    cin >> n >> T;

    for (int i = 0; i < n; i++) {
        cin >> p[i] >> t[i] >> d[i];
        
        if (d[i] == -1) {
            d[i] = T+1; // no deadline
        }
    }
    for (int i = n; i < n+2; i++) {
        t[i] = 0;
        d[i] = T+1;
    }

    for (int i = 0; i < n+2; i++) {
        for (int j = 0; j < n+2; j++) {
            cin >> dist[i][j];
        }
    }

    for (int i = 0; i < (1 << (n+1)); i++) {
        for (int j = 0; j < n+2; j++) {
            mem[i][j] = -1;
        }
    }

    solve();

    return 0;
}