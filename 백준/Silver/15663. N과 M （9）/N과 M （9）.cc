#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int n, m;
int first[9];
int arr[9];
int visited[9];
set<vector<int>> s;

void dfs(int k) { 
    if (k == m) {
        vector<int> v;
        for (auto i = 0; i < m; i++)
            v.push_back(arr[i]);
        s.insert(v); 
        v.clear();
    }
    else {
        for (auto i = 0; i < n; i++) {
            if (!visited[i]) { 
                visited[i] = 1; 
                arr[k] = first[i]; 
                dfs(k + 1); 
                visited[i] = 0;
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> first[i];

    sort(first, first + n);

    dfs(0);

    for (auto vector : s) {
        for (auto temp : vector)
            cout << temp << " ";
        cout << "\n";
    }
}