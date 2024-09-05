#include <iostream>
#include <algorithm>

using namespace std;

int n, s;
int x[21];
int cnt;
int total;

void dfs(int idx) {
	if (idx == n) return;

	total += x[idx];

	if (total == s) cnt++;

	dfs(idx+1);
	total -= x[idx];
	dfs(idx + 1);
}

int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}

	dfs(0);

	cout << cnt;
	return 0;
}