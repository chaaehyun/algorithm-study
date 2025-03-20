#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> s) {
    int answer = 0;
    int x1 , x2 = 0;
    int maxx = 0;
    int y1, y2 = 0;
    int maxy = 0;
    int sum1, sum2 = 0;
    int maxv = 0;
    
    for(int i=0;i<s.size();i++){
        if(s[i][0] > maxx || s[i][1] > maxy){
            if(s[i][0] > maxx)
                x1=s[i][0];
            else
                x1=maxx;
            
            if(s[i][1] > maxy)
                y1=s[i][1];
            else
                y1=maxy;
            
            sum1=x1*y1;
        }
        else {
            x1=maxx;
            y1=maxy;
            sum1 = maxv;
        }
        
        if(s[i][1] > maxx || s[i][0] > maxy){
            if(s[i][1] > maxx)
                x2=s[i][1];
            else
                x2=maxx;
            
            if(s[i][0] > maxy)
                y2=s[i][0];
            else
                y2=maxy;
            
            sum2=x2*y2;
        }
        else {
            x2=maxx;
            y2=maxy;
            sum2 = maxv;
        }
        
        if(sum1<=sum2){
            maxx=x1;
            maxy=y1;
            maxv=maxx*maxy;
        } else {
            maxx=x2;
            maxy=y2;
            maxv=maxx*maxy;
        }
    }
    answer = maxv;
    return answer;
}