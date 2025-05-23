#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int current = 0;
		int cnt = 0;
		string s;
		cin >> s;

		for (int i = 0; i < s.length(); i++) {
			if (s[i] - '0' != current) {
				current = s[i]- '0';
				cnt++;
			}
		}

		cout << "#" << test_case << " " << cnt << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}