// 백준 9093번 단어 뒤집기

#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int n;
string sentence;
stack<char> s;
queue<char> q;

int main() {
	cin >> n;
	cin.ignore();

	for (int i = 1; i <= n; i++) {

		getline(cin, sentence);

		for (int j = 0; j < sentence.length(); j++) {
			if (sentence[j] == ' ') {
				while (!s.empty()) {
					q.push(s.top());
					s.pop();
				}
				q.push(' ');
			}
			else
				s.push(sentence[j]);
		}
		while (!s.empty()) {
			q.push(s.top());
			s.pop();
		}

		while (!q.empty()) {
			cout << q.front();
			q.pop();
		}
		cout << endl;
	}

	return 0;

}
