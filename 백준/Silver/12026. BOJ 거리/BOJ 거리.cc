#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 99999999;
int n;
vector<char> v;
int visited[1001];

void dp(int x) {
    visited[x] = 0;

    for (int i = x; i < n; i++) {
        if (visited[i] == INF) continue;

        for (int j = i + 1; j < n; j++) {
            if ((v[i] == 'B' && v[j] == 'O') ||
                (v[i] == 'O' && v[j] == 'J') ||
                (v[i] == 'J' && v[j] == 'B')) {

                int dist = (j - i) * (j - i);

                if (visited[j] > visited[i] + dist) {
                    visited[j] = visited[i] + dist;
                }
            }
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        char a;
        cin >> a;
        v.push_back(a);
    }

    fill(visited, visited + n, INF);

    dp(0);

    if (visited[n - 1] == INF) {
        cout << "-1";
    }
    else {
        cout << visited[n - 1]; 
    }

    return 0;
}
