#include<iostream>
#include<queue>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        string s;
        queue<char> q;
        cin>>s;
        
        for(int i=0;i<s.length();i++){
            if(s[i]!='a'&&s[i]!='e'&&s[i]!='i'&&s[i]!='o'&&s[i]!='u')
                q.push(s[i]);
        }
           
         cout<<"#"<<test_case<<" ";
         while(!q.empty()){
             cout<<q.front();
             q.pop();
         }
        cout<<endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}