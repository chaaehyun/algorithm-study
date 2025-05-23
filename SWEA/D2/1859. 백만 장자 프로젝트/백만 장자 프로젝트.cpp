#include<iostream>
#include <vector>
#include <queue>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
    queue<int> q;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        vector<int> v = { 0 };
		long sum = 0;
		int maxv = 0;
		int x = 0;
        int n = 0;
        
		cin >> n;

		for (int j = n; j >= 1; j--) {
			cin >> x;
			v.push_back(x);
		}

		for (int j = n; j >= 1; j--) {
			x = v[j];
			if (maxv < x)
				maxv = x;


			if (maxv > x)
				sum += (maxv - x);
		}

		cout <<"#"<<test_case <<" "<< sum << endl;
	}
	return 0;
}