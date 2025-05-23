#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
    int current = 0;
    int future = 0;
    int answer = 0;
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
            cin >> current >> future;
            answer = current + future;
            answer %= 24;

            cout << "#" << test_case << " " << answer << endl;
        }

        return 0;
}