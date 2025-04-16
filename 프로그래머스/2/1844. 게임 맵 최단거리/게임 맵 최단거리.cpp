#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};


int solution(vector<vector<int> > maps)
{
    int n = maps.size(); // 실제 y값
    int m = maps[0].size(); // 실제 x값
    // 원래 배열은 arr[y][x] 형태 but 통상적으로 이해쉽도록 n을 x취급, m을 y취급
    vector<vector<int>> visited(n, vector<int>(m, 0));
    
    queue<pair<pair<int,int>,int>> q;
    q.push({{0,0},1});
    visited[0][0]=1;
    
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dist = q.front().second;
        q.pop();
        
        if (x == n - 1 && y == m - 1)
            return dist;
        
        for(int i=0; i<=3; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            
            if(nx>=0 && nx<n && ny>=0 && ny<m){
                if(!visited[nx][ny] && maps[nx][ny]!=0){
                    visited[nx][ny] = 1;
                    q.push({{nx, ny}, dist + 1});
                }
            }
        }
    }
    
    return -1;
}