#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k;
int t[100001];
queue<int> q;
int now_n;
int sec;

int main() {
	cin >> n >> k;
	q.push(n);

	while (!q.empty()) {
		now_n = q.front();
		q.pop();

		if (now_n < 0 || now_n>100000) continue;

		if (now_n == k) {
			cout << t[now_n] <<endl;
			break;
		}

		if (now_n - 1 >= 0 && t[now_n - 1] == 0) {    
			t[now_n - 1] = t[now_n] + 1;
			q.push(now_n - 1);
		}

		if (now_n + 1 <= 100000 && t[now_n + 1] == 0) {
			t[now_n + 1] = t[now_n] + 1;
			q.push(now_n + 1);
		}

		if (2 * now_n <= 100000 && t[2 * now_n] == 0) {
			t[2 * now_n] = t[now_n] + 1;
			q.push(2 * now_n);
		}


	}
	return 0;
}