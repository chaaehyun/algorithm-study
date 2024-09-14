#include <iostream>
#include <algorithm>

using namespace std;

int n;
int path[101][101];
long long visited[101][101];

void dp() {
    visited[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (path[i][j] == 0 || visited[i][j] == 0) {
                continue;
            }

            if (j + path[i][j] < n) {
                visited[i][j + path[i][j]] += visited[i][j];
            }

            if (i + path[i][j] < n) {
                visited[i + path[i][j]][j] += visited[i][j];
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

    dp();

    cout << visited[n - 1][n - 1] << endl;

    return 0;
}
