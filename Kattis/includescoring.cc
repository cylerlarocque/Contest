#include <bits/stdc++.h>

using namespace std;

class player {
 public:
    player(int _n, int _s, int _p, int _f, int _o) {
        n = _n;
        s = _s;
        p = _p;
        f = _f;
        o = _o;
        ans = 0;
    }

    int n;
    int s,p,f,o;
    int ans;
};

bool sortFunc(player *p1, player *p2) {
    if (p1->s != p2->s) {
        return p1->s > p2->s; 
    }
    if (p1->p != p2->p) {
        return p1->p < p2->p; 
    }
    return p1->f < p2->f; 
}

bool sortFunc2(player *p1, player *p2) {
    return p1->n < p2->n; 
}

bool sameRank(player *p1, player *p2) {
    return p1->s == p2->s && p1->p == p2->p && p1->f == p2->f;
}

int main() {
    int n;
    cin >> n;

    map<int,int> scoreTable = {
        {1, 100},
        {2, 75},
        {3, 60},
        {4, 50},
        {5, 45},
        {6, 40},
        {7, 36},
        {8, 32},
        {9, 29},
        {10, 26},
        {11, 24},
        {12, 22},
        {13, 20},
        {14, 18},
        {15, 16},
        {16, 15},
        {17, 14},
        {18, 13},
        {19, 12},
        {20, 11},
        {21, 10},
        {22, 9},
        {23, 8},
        {24, 7},
        {25, 6},
        {26, 5},
        {27, 4},
        {28, 3},
        {29, 2},
        {30, 1}
    };

    vector<player*> players(n);

    for (int i = 0; i < n; i++) {
        int s,p,f,o;
        cin >> s >> p >> f >> o;
        players[i] = new player(i, s, p, f, o);
    }

    sort(begin(players), end(players), sortFunc);

    int j = 0;
    for (int i = 0; i < n; i = j) {
        for (j = i+1; j < n && sameRank(players[i], players[j]); j++) {}

        // find the score to assign to this group
        int ans = 0;
        for (int x = i; x < j; x++) {
            ans += (x+1 <= 30) ? scoreTable[x+1] : 0;
        }
        ans = (ans + (j-i-1)) / (j-i);

        for (int x = i; x < j; x++) {
            players[x]->ans = ans;
        }
    }

    sort(begin(players), end(players), sortFunc2);

    for (auto *p : players) {
        cout << p->ans + p->o << endl;
    }

    return 0;
}