#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    rocks.push_back(0);
    rocks.push_back(distance);
    sort(rocks.begin(), rocks.end());
    
    int left = 1;
    int right = distance;
    
    while(left<=right){
        int cnt = 0;
        int prev = 0;
        int mid = (left+right)/2;
        
        for(int i=1; i<rocks.size(); i++)
            if(mid>rocks[i]-prev)
                    cnt++;
            else
                prev=rocks[i];
        
        if(cnt>n)
            right=mid-1;
        else{
            left=mid+1;
            answer = mid;
        }
    }
    
    return answer;
}