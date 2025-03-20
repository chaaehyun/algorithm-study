#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> s, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    int first = 0;
    int second = 0;

    for(int i=0; i<s.size(); i++)
        pq.push(s[i]);
    
    while(pq.size()>1 && pq.top()<K){
        first = pq.top();
        pq.pop();
        
        second = pq.top();
        pq.pop();
        
        pq.push(first+(second * 2));
        answer++;
    }
    
    if(pq.top()<K)
        answer = -1;
    
    return answer;
}