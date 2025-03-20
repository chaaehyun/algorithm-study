#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    answer = n-lost.size();
    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    for(int i=0; i<lost.size(); i++){
        for(int j=0;j<reserve.size();j++){
            if(lost[i]==reserve[j]){
                reserve[j]=-1;
                lost[i]=-1;
                answer++;
                break;
            }
        }
    }
    
    int minv = 0;
    
    for(int i=0; i<lost.size(); i++){
        for(int j=minv;j<reserve.size();j++){
            if(lost[i]==reserve[j]-1 || lost[i]==reserve[j]+1){
                answer++;
                reserve[j]=-1;
                minv=j;
                break;
            }
        }
    }
    return answer;
}