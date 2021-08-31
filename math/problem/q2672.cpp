//백준 2672번 여러 직사각형의 전체 면적 구하기
// 스위핑 기법(Sweeping Algorithm)
//한 번에 겹치는 영역 찾기
//기본적으로 오름차순 정렬 필수!!
//추가하고자하는 영역이 붙어 있으면 끝점연장
//떨어져있으면 기존것을 결과값에 추가함

#include <iostream>
#include <cstring>]
#include <algorithm>
using namespace std;

pair<int, int> table[20005];//x축 기준으로 y축 스위핑
int n;
int an = 0;
pair<pair<int, int>, pair<int, int>> ract[35];//사각형 특징


bool par(pair<pair<int, int>, pair<int, int>> a, pair<pair<int, int>, pair<int, int>> b) {
	return a.second.first < b.second.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(table, 0, sizeof(table));
	cin >> n;
	for (int i = 0; i < n; i++) {
		float a, b, c, d;
		cin >> a >> b >> c >> d;
		int aa = (int)(a * 10);
		int bb = (int)(b * 10);
		int cc = (int)(c * 10);
		int dd = (int)(d * 10);
		ract[i] = { {aa, aa + cc}, {bb, bb + dd} };
		
	}
	sort(ract, ract + n, par);

	for (int i = 0; i < n; i++) {
		for (int j = ract[i].first.first; j < ract[i].first.second; j++) {
			if (table[j].second < ract[i].second.first) {
				an += table[j].second - table[j].first;
				table[j] = { ract[i].second.first, ract[i].second.second };
			}
			else if (table[j].second >= ract[i].second.first) {
				table[j].second = max(ract[i].second.second, table[j].second);
			}
		}
	}
	for (int i = 1; i <= 20001; i++) {
		an += table[i].second - table[i].first;
	}



	if (an % 100 == 0) {
		cout << (an / 100) << "\n";
	}
	else {
		cout << fixed;
		cout.precision(2);
		cout << ((double)(an)) / 100 << "\n";
		cout.unsetf(ios::fixed);
	}
	return 0;
}