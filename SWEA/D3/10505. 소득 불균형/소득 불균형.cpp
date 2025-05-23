#include<iostream>
#include<vector>

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
        int sum = 0;
        int cnt = 0;
        vector<int> v={0};
        
        cin>>n;
        
        for(int i=0; i<n; i++){
            cin>>x;
            v.push_back(x);
            sum+=x;
        }
        
        sum /=n;
        
        for(int i=1;i<v.size();i++){
            if(v[i]<=sum)
                cnt++;
        }

        cout<<"#"<<test_case<<" "<<cnt<<endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}