#include <bits/stdc++.h>

using namespace std;

void shuffe(int data[], int N, const string &inout) {
    int p1, p2;
    int shuffled[1000];

    if (inout == "out") {
        p1 = 0;
        p2 = (N+1)/2;
    } else {
        p1 = N/2;
        p2 = 0;
    }

    int iPlacing = 0;

    for (int i = 0; i < N/2; i) {
        shuffled[iPlacing++] = data[p1++];
        shuffled[iPlacing++] = data[p2++];
    }
    if (N % 2 == 0) {
        shuffled[iPlacing] = data[p1];
    }

    copy(shuffled, shuffled+N, data);
}

int main() {
    int n;
    string inout;
    cin >> n >> inout;

    if (inout == "out") {
        
    } else {

    }


    return 0;
}

// cycle decomposition of permutation