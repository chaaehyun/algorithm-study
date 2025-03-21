#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> graph(n+1);
    
    for(int i=0;i<edge.size();i++){
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    
    vector<int> dist(n+1, -1);
    queue<int> q;
    
    dist[1]=0;
    q.push(1);
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(int i=0; i<graph[cur].size(); i++){
            int nxt = graph[cur][i];
            if(dist[nxt]==-1){
                dist[nxt] = dist[cur]+1;
                q.push(nxt);
            }
        }
    }
    
    int maxv = *max_element(dist.begin()+1, dist.end());
    
    answer = count(dist.begin()+1, dist.end(), maxv);
    
    return answer;
}