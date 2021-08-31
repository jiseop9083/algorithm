//백준 3392번 화성지도
//y기준으로 정렬 > 합 구하기
//세그먼트 트리가 필요한가?

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
pair <pair<int, int >, pair<int, int>> ract[10005];
pair<int, int> num[30005];
int an = 0;


bool com(pair <pair<int, int >, pair<int, int>> a, pair <pair<int, int >, pair<int, int>> b) {
	return a.second.first < b.second.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(num, 0, sizeof(num));
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		ract[i] = { {a,c}, {b,d} };
	}
	sort(ract, ract + n, com);
	for (int i = 0; i < n; i++) {
		int start = ract[i].second.first;
		int end = ract[i].second.second;
		for (int j = ract[i].first.first; j < ract[i].first.second; j++) {
			if (num[j].second < start) {
				an += num[j].second - num[j].first;
				num[j].first = start;
				num[j].second = end;
			}
			else if (num[j].second < end) {
				num[j].second = end;
			}
		}
	}
	for (int i = 0; i <= 30000; i++) {
		an += num[i].second - num[i].first;
	}
	cout << an << "\n";
	return 0;
}