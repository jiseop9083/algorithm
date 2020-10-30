//백준 1931번 회의실 배정
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int an = 0;
pair<int, int> num[100005];

bool com(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		num[i] = { a,b };
	}
	sort(num, num + n, com);
	int start = 0;
	for (int i = 0; i < n; i++) {
		if (start <= num[i].first) {
			an++;
			start = num[i].second;
		}
	}
	cout << an;
	return 0;
}
