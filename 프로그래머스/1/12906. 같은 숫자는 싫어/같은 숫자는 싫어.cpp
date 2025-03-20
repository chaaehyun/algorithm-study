#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int n = arr.size();
    queue<int> q;
    
    if(n!=0) {
        int x = arr[0];
        q.push(x);
    
        for(int i=1; i<n; i++){
            if(x!=arr[i]){
                q.push(arr[i]);
                x=arr[i];
            }
        }
    }
    
    int s = q.size();
    if(s!=0){
        for(int i=0; i<s; i++){
            answer.push_back(q.front());
            q.pop();
        }
    }
    
    return answer;
}