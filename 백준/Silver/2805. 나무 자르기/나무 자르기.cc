#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
long long m;
vector <int> v;
long long l, r;
long long total;
long long mid;
long long answer;

int main() {
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		int a = 0;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	l = 0;
	r = v.back();

	while (l <= r) {
		total = 0;
		mid = (l + r) / 2;

		for (int i = 0; i < n; i++) {
			if (mid < v[i])
				total += (v[i] - mid);
		}
		
		if (total >= m) {
			l = mid + 1;
			answer = mid;
		}
		else
			r = mid - 1;
	}

	cout << answer;
	return 0;
}