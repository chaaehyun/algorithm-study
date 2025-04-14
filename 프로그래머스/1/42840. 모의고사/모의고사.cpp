#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int l = answers.size();
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> c = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    vector<int> sum(4, 0); // 벡터 초기화 방법
    int maxv = 0;
    
    for(int i=0;i<l;i++){
        if(a[i%a.size()]==answers[i])
            sum[1]++;
        if(b[i%b.size()]==answers[i])
            sum[2]++;
        if(c[i%c.size()]==answers[i])
            sum[3]++;
    }
        
    for(int i=1;i<=3;i++){
        if(maxv<=sum[i])
            maxv=sum[i];
        }
    
    for(int i=1;i<=3;i++){
        if(maxv==sum[i])
            answer.push_back(i);
    }
    
    return answer;
}