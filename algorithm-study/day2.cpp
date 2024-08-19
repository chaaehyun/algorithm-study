// ���� 1058 �似Ǫ��

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int k;
queue<int> q;

int main() {
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	cout << "<";
	while (!q.empty()) {
		for (int i = 0; i < k-1; i++) {
			q.push(q.front());
			q.pop();
		}

		cout << q.front();
		q.pop();

		if (!q.empty())
			cout << ", ";
	}
	cout << ">";
	return 0;
}