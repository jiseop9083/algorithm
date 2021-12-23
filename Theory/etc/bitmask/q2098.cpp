//백준 2098번 외판원 순회

#include <iostream>
#include <cstring>
#include <algorithm>
#define INF 1000000000
using namespace std;

int city[65600][17];
int cost[20][20];
int n;

int dp(int visit, int pos) {
	int& ret = city[visit][pos];
	if (ret != -1) {
		return ret;
	}
	ret = INF;
	for (int i = 0; i < n; i++) {
		if (cost[i][pos] == 0 || !(visit & (1 << i))) {
			continue;
		}
		ret = min(ret, cost[i][pos] + dp(visit&(~(1 << pos)), i));
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(city, -1, sizeof(city));
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> cost[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		if (cost[0][i] == 0) {
			continue;
		}
		//0번째에서 i번째로 
		city[1 << i][i] = cost[0][i];
	}
	cout << dp(((1 << n) - 1), 0);
	return 0;
}
