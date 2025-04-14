#include <string>
#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    int maxv = 0;
    int l = dungeons.size();
    
    string orderInfo;
    for(int i=1;i<=l;i++)
        orderInfo += to_string(i); // int를 string으로 바꾸는 방법
    
    do{
        int x = k;
        answer=0;
        //cout<<orderInfo<<endl;
        for(int i=0; i<l; i++){
            //cout<<"흠 "<< (orderInfo[i]-'0')-1<<endl;
            if(x>=dungeons[(orderInfo[i]-'0')-1][0]){ // 한자리 숫자를 int로 바꿀땐 stoi대신 -'0' 하는 것 기억하기~
                //cout<<orderInfo[i]<<" "<<x<<endl;
                answer++;
                x-=dungeons[(orderInfo[i]-'0')-1][1];
                if(x<0){
                    answer--;
                    break;
                }
            }
        }
        if(maxv<answer)
            maxv=answer;
        
        if(maxv==l)
            break;
        
    }while(next_permutation(orderInfo.begin(), orderInfo.end()));

    return maxv;
}