//Strongly Connected Component
//SCC 기본 
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;


vector<vector<int>> an; // SCC 모은 벡터
stack <int> s;
vector<int> ve[10005]; // 그래프
int id[10005]; // 탐색 순서
int v, e;
int finished[10005]; //SCC에 포함된 여부
int cnt = 1;

int dfs(int x) {
	id[x] = cnt++; //탐색 순서를 저장
	int ret = id[x];
	s.push(x);
	for (int i : ve[x]) {
		if (id[i] == 0) {
			ret = min(ret, dfs(i));
		}
		else if(finished[i] == 0) // SCC에 포함안되면
			ret = min(ret, id[i]);
	}
	if (ret == id[x]) { // 내가 대표
		vector<int> temp;
		while (!s.empty()) {
			int t = s.top();
			s.pop();
			temp.push_back(t);
			finished[t] = 1;
			if (t == x)
				break;
		}
		sort(temp.begin(), temp.end());
		an.push_back(temp);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> v >> e;
	memset(finished, 0, sizeof(finished));
	memset(id, 0, sizeof(id));
	for (int i = 0; i < e; i++) {
		int a, b; cin >> a >> b;
		ve[a].push_back(b);
	}
	for (int i = 1; i <= v; i++) {
		if(id[i] == 0)
			dfs(i);
	}
	sort(an.begin(), an.end());
	cout << an.size() << "\n";
	for (int i = 0; i < an.size(); i++) {
		for (int j : an[i]) {
			cout << j << " ";
		}
		cout << "-1\n";
	}
	return 0;
}
