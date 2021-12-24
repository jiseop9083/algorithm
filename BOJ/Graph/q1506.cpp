//q1506.cpp
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

vector<vector<int>> scc;
vector<int> ve[105];
stack<int> s;
int finished[105];
int id[105];
int n;
int cost[105];
int cnt = 1;


bool com(int a, int b) {
	return cost[a] < cost[b];
}

int dfs(int x) {
	id[x] = cnt++;
	s.push(x);
	int ret = id[x];
	for (int i : ve[x]) {
		if (id[i] == 0) {
			ret = min(ret, dfs(i));
		}
		else if (finished[i] == 0) {
			ret = min(ret, id[i]);
		}
	}
	if (ret == id[x]) {
		vector<int> temp;
		while (!s.empty()) {
			int t = s.top();
			s.pop();
			finished[t] = 1;
			temp.push_back(t);
			if (t == x)
				break;
		}
		sort(temp.begin(), temp.end(), com);
		scc.push_back(temp);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(id, 0, sizeof(id));
	memset(finished, 0, sizeof(finished));
	cin >> n; 
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
	}
	for (int i = 1; i <= n; i++) {
	    string arr; cin >> arr;
		for (int j = 0; j < n; j++) {
			if (arr[j] == '1')
				ve[i].push_back(j + 1);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (id[i] == 0)
			dfs(i);
	}
	int an = 0;
	for (int i = 0; i < scc.size(); i++) {
		an += cost[scc[i][0]];
	}
	cout << an;
	return 0;
}
