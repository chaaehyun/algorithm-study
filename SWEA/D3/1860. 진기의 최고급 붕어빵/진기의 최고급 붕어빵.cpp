#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n;
        int m;
        int k;
        int x;
        string s ="Possible";
        int sum = 0;
        int time = 0;
        int arrive = 0;
        int past = 0;
        vector<int> v;
        
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++){
            cin>>x;
            v.push_back(x);
        }
        
        sort(v.begin(), v.end());
        
        for(int i=0; i<n;i++){
            if(i==0)
                past = 0;
            else
                past = v[i-1];
            
            arrive=v[i];
            if(arrive!=0)
           	 sum+=((arrive/m)*k - (past/m)*k);
            
            //cout<<arrive<<" 도착했구요 "<<sum<<" 남았어요"<<endl;
            if(sum==0){
                s="Impossible";
                break;
            }else
                sum--;
        }
   
        cout<<"#"<<test_case<<" "<<s<<endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}