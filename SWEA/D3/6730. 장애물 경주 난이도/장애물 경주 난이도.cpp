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
        int x;
        int up = 0;
        int down = 0;
        vector<int> v;
        cin>>n;
        
        for(int i=0;i<n;i++){
            cin>>x;
            v.push_back(x);
        }
        
        
        for(int i=0;i<v.size()-1;i++){
            
            if(v[i]<v[i+1] && v[i+1]-v[i] > up){
                up=v[i+1]-v[i];
            }
            else if(v[i]>v[i+1] && v[i]-v[i+1] > down){
                down = v[i] - v[i+1];
            }
        }

        cout<<"#"<<test_case<<" "<<up<<" "<<down<<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}