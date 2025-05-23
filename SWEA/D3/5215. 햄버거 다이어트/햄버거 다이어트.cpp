#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int maxv = 0;

void dfs(int cnt, int score, int cal, int n, int l, const vector<pair<int, int>>& member) {
	if (cal > l)
		return;
	if (cnt == n) {
		maxv = max(maxv, score);
		return;
	}

	dfs(cnt + 1, score, cal, n, l, member);

	dfs(cnt + 1, score + member[cnt].first, cal + member[cnt].second, n, l, member);

}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
        maxv = 0;
		int n;
		int l;
		cin >> n >> l;

		vector<pair<int, int>> member(n);

		for (int i = 0; i < n; i++) {
			cin >> member[i].first >> member[i].second;
		}


		dfs(0, 0, 0, n, l, member);

		cout << "#" << test_case << " " << maxv << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}