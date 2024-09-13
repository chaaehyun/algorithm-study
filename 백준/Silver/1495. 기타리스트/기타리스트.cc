#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, s;
int visited[51][1001]; 
int volume[51];
int maxv = -1;

void dp(int v, int idx) {
    if (idx == n) { 
        return;
    }

    if (v + volume[idx] <= m && !visited[idx + 1][v + volume[idx]]) {
        visited[idx + 1][v + volume[idx]] = 1;
        dp(v + volume[idx], idx + 1);
    }

    if (v - volume[idx] >= 0 && !visited[idx + 1][v - volume[idx]]) {
        visited[idx + 1][v - volume[idx]] = 1;
        dp(v - volume[idx], idx + 1);
    }
}

int main() {
    cin >> n >> s >> m;
    for (int i = 0; i < n; i++) {
        cin >> volume[i];
    }

    visited[0][s] = 1;
    dp(s, 0);

    for (int i = 0; i <= m; i++) {
        if (visited[n][i] == 1) {
            maxv = max(maxv, i);
        }
    }

    cout << maxv << "\n";

    return 0;
}
