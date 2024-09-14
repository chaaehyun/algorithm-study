#include <iostream>
#include <algorithm>

using namespace std;

int n;
int path[101][101];
long long dp[101][101];

void solve() {
    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (path[i][j] == 0 || dp[i][j] == 0) {
                continue;
            }

            if (j + path[i][j] < n) {
                dp[i][j + path[i][j]] += dp[i][j];
            }

            if (i + path[i][j] < n) {
                dp[i + path[i][j]][j] += dp[i][j];
            }
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> path[i][j];
        }
    }

    solve();
    
    cout << dp[n - 1][n - 1] << endl;

    return 0;
}
