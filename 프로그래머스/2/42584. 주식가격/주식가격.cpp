#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<pair<int, int>> s;
    
    for(int i=0; i<prices.size(); i++){
        int current_time = i+1;
        
        if(s.empty() || s.top().first <= prices[i]){
            s.push({prices[i], current_time});
        }
        else{
            while(!s.empty() && s.top().first > prices[i]){
            int previous_time = s.top().second;
            int index = s.top().second - 1;
            s.pop();
            answer[index] = current_time - previous_time;
            }
            s.push({prices[i], current_time});
        }
    }
    
    int current_time = prices.size();
    
    while(!s.empty()){
        int previous_time = s.top().second;
        int index = s.top().second - 1;
        s.pop();
        answer[index] = current_time - previous_time;
    }
    
    return answer;
}