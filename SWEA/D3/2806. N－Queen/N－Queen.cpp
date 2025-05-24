#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

 int answer;
int n;

bool isSafe(int y, int x,vector<int>& v){
    for(int i=0; i<y; i++){
        if(v[i] == x || abs(v[i]-x) == y-i)
            return false;
    }
    return true;
}

void dfs(int y, vector<int>& v){
    if(y==n){
        answer++;
        return;
    }
    for(int x=0; x<n;x++){
        if(isSafe(y,x,v)){
            v[y] = x;
            dfs(y+1, v);
        }
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        answer = 0;
        cin>>n;
        vector<int> v(n);
        
		dfs(0, v);
        cout<<"#"<<test_case<<" "<<answer<<endl;
	}
	return 0;
}