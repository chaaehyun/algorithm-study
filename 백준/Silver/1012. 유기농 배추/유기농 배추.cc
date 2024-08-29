#include <iostream>
#include <algorithm>
using namespace std;

int t, m, n, k, x, y, ans;
int map[50][50];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void DFS(int x, int y) {
	map[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];
		if (next_x < 0 || next_y < 0 || next_x >= m || next_y >= n) continue;
		if (map[next_x][next_y] == 1) {
			DFS(next_x, next_y);
		}
	}
}

int main() {
	cin >> t;
	for (int q = 0; q < t; q++) {
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			map[x][y] = 1;
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 1) {
					DFS(i, j);
					ans++;
				}
			}
		}

		cout << ans << '\n';
		ans = 0;
		for (int i = 0; i < m; i++) {
			fill(map[i], map[i] + n, 0);
		}
	}
}