#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int l, c;
char a[16];
vector<char> p;
int m, j;

void dfs(int idx, int cnt) {
	if (cnt == l) {
		m = 0;
		j = 0;

		for (int i = 0; i < l; i++) {
			int test = p[i];
			if (test == 'a' || test == 'e' || test == 'i' || test == 'o' || test == 'u')
				m++;
			else
				j++;
		}

		if (m >= 1 && j >= 2) {
			for (int i = 0; i < p.size(); i++) {
				cout << p[i];
			}
			cout << "\n";
		}
		
		return;
	}

	if (idx >= c)
		return;

	p.push_back(a[idx]);
	dfs(idx + 1, cnt + 1);
	p.pop_back();
	dfs(idx + 1, cnt);
}

int main() {
	cin >> l >> c;

	for (int i = 0; i < c; i++) {
		cin >> a[i];
	}

	sort(a, a + c);

	dfs(0,0);


	return 0;
}