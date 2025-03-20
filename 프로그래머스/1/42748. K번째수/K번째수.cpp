#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> c) {
    vector<int> answer;
    vector<int> middle;
    
    for(int i=0; i<c.size(); i++){
        for(int j=c[i][0]; j<=c[i][1]; j++){
            middle.push_back(array[j-1]);
        }
        
        sort(middle.begin(), middle.end());
        
        answer.push_back(middle[c[i][2]-1]);
        
        middle.clear();
    }
    return answer;
}