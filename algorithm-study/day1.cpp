// 백준 10828번 스택

#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

int n;
int x;
stack<int> s;

void push(int x) {
	s.push(x);
}

void pop() {
	if (!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}

	else
		cout << -1 << endl;
}

void size() {
	cout << s.size() << endl;
}

void empty() {
	cout << s.empty() << endl;
}

void top() {
	if (!s.empty())
		cout << s.top() << endl;

	else
		cout << -1 << endl;
}

int main() {
	string order;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> order;
		if (order == "push") {
			cin >> x;
			push(x);
		}

		else if (order == "pop")
			pop();

		else if (order == "size")
			size();

		else if (order == "empty")
			empty();

		else
			top();
	}

	return 0;
}