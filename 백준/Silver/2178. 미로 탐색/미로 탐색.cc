#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int n, m;
int dist[101][101];
char map[101][101];
int visited[101][101];
int answer;

void BFS(int start_x, int start_y) {
    visited[start_x][start_y] = 1;

    queue<pair<int, int>> q;
    q.push(make_pair(start_x, start_y));

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m) {
                if (map[next_x][next_y] == '1' && visited[next_x][next_y] == 0) {
                    dist[next_x][next_y] = dist[x][y] + 1;
 
                    visited[next_x][next_y] = 1;
                    
                    q.push(make_pair(next_x, next_y));
                   
                }
            }
        }

    }
}

int main(void) {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> map[i];
    }
    BFS(0, 0);
    
    answer = dist[n - 1][m - 1] + 1;

    cout << answer << '\n';
    return 0;
}