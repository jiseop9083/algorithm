#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int num[55];
int suso[2005];
int visit[55];
vector<int> ve[55];
vector<int> an;

pair<int, int> dfs(int x) {//답, 가능여부
	visit[x] = 1;
	for (int i : ve[x]) {

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(suso, 0, sizeof(suso));
	suso[0] = 1;
	suso[1] = 1;
	for (int i = 2; i * i <= 2000; i++) {
		if (suso[i] == 0) {
			for (int j = i; j <= 2000; j += i) {
				suso[j] = 1;
			}
		}
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)
				continue;
			if (suso[num[i] + num[j]] == 0) {
				ve[i + 1].push_back(j + 1);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		memset(visit, 0, sizeof(visit));
		dfs(i);
	}
	sort(an.begin(), an.end());
	for (int i : an) {
		cout << i;
	}
	return 0;
}