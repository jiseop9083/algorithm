//���� 11724�� ���� ����� ����
//���� ���� DFS�� ���͸� �̿��� ���غ���!

#include <iostream>
#include <vector>
using namespace std;
vector<int>ve[1005];
bool visit[1005];

void dfs(int x) {
	visit[x] = true;
	for (int i = 0; i < ve[x].size(); i++) {
		if (!visit[ve[x][i]]) {
			dfs(ve[x][i]);
		}
	}
}


int main() {
	
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		ve[u].push_back(v);
		ve[v].push_back(u);
	}
	int count = 0;
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			dfs(i);
			count++;
		}
	}
	cout << count;
	return 0;
}