#include <bits/stdc++.h>

using namespace std;

int asc_seq(int A[], int n)
{
  vector<int> last(n+1);
  if (n == 0) {
    return 0;
  }

  int len = 1;
  last[1] = A[0];

  for (int i = 1; i < n; i++) {
    int j = upper_bound(last.begin()+1, last.begin()+len+1, A[i]) -
      last.begin();
    last[j] = A[i];
    len = max(len, j);
  }

  return len;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> players;
    map<int, int> iPLayers;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;

        players.push_back(p);
        iPLayers[p] = i;
    }

    sort(players.begin(), players.end());

    int *sorted = new int[n];
    for (int i = 0; i < n; i++) {
        sorted[iPLayers[players[i]]] = i/k;
    }

    cout << n - asc_seq(sorted, n) << endl;

    delete[] sorted;

    return 0;
}