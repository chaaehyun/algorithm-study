#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int k, n;
vector<long long> v;
long long l, r;
long long total;
long long mid;
long long answer;

int main() {
	cin >> k >> n;
	
	for (int i = 0; i < k; i++) {
		long long a = 0;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	l = 1;
	r = v.back();

	while (l <= r) {
		total = 0;
		mid = (l + r) / 2;

		for (int i = 0; i < k; i++) {
			total += (v[i] / mid);
		}
		
		if (total >= n) {
			l = mid + 1;
			answer = mid;
		}
		else
			r = mid - 1;
	}

	cout << answer;
	return 0;
}