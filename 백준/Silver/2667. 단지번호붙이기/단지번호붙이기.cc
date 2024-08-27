#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int temp;
int map[26][26];
vector<int> ans;
bool visited[26][26] = { false };
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void bfs(int row, int col)
{
	queue<pair<int, int>> q;
	q.push(make_pair(row, col));
	visited[row][col] = true;
	int cnt = 0;
	cnt++;
	while (!q.empty())
	{
		int front_x = q.front().first;
		int front_y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int next_x = front_x + dx[i];
			int next_y = front_y + dy[i];
			if (0 <= next_x && next_x < n && 0 <= next_y && next_y < n
				&& visited[next_x][next_y] == false && map[next_x][next_y] == 1)
			{
				q.push(make_pair(next_x, next_y));
				visited[next_x][next_y] = true;
				cnt++;
			}
		}
	}
	ans.push_back(cnt);
}

int main()
{
	cout.tie(nullptr);
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char temp;
			cin >> temp;
			map[i][j] = temp - '0';
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j] == false && map[i][j] == 1)
			{
				bfs(i, j);
			}
		}
	}
	
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << '\n';
}