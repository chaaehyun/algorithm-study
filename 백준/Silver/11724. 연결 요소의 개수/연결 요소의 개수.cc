#include <iostream>
#include <vector>
using namespace std;

vector<int> vec[1002]; 
int visited[1002];      
int n, m;

void DFS(int x)
{
    visited[x] = 1;
    for (int i = 0; i < vec[x].size(); i++) //최댓값 주의 : 벡터 그 원소에 해당하는 크기만큼 돌아야함
    {
        int idx = vec[x][i];
        if (visited[idx] == 0)
        {
            DFS(idx);
        }
    }
}

int main()
{
    int u, v;
    int cnt = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            cnt++;
            DFS(i);
        }
    }
    cout << cnt << "\n";
}