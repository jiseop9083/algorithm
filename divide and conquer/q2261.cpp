#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> ve;//y, x
int an;

//거리 구하는 함수
int dis(pair<int, int> a, pair<int, int> b) {
	return ((a.first - b.first) * (a.first - b.first)) + ((a.second - b.second) * (a.second - b.second));
}

//X좌표 기준 정렬
bool comX(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

//Y좌표 기준 정렬
bool comY(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first < b.first;
}

//start와 end는 점의 번호
int divide_conquer(int start, int end) {
	//점이 두 개일때
	if (start + 1 == end) {
		return dis(ve[start], ve[end]);
	}
	//점이 세 개일때
	else if (start + 2 == end) {
		return min(dis(ve[start], ve[end]),min(dis(ve[start], ve[start + 1]) ,dis(ve[start + 1], ve[end])) );
	}
	int mid = (start + end) / 2;
	int line = (ve[mid].second + ve[mid + 1].second) / 2;
	int ret = min(divide_conquer(start, mid), divide_conquer(mid + 1, end));
	//x좌표 거리의 제곱이가 ret이하인 점들
	vector<pair<int, int>> mid_ve;
	for (int i = start; i <= end; i++) {
		if ((line - ve[i].second) * (line - ve[i].second) < ret) {
			mid_ve.push_back(ve[i]);
		}
	}
	sort(mid_ve.begin(), mid_ve.end(), comY);
	for (int i = 0; i < mid_ve.size(); i++) {
		for (int j = i + 1; j < mid_ve.size() &&
			(mid_ve[j].first - mid_ve[i].first) * (mid_ve[j].first - mid_ve[i].first) < ret; j++) {
			ret = min(ret, dis(mid_ve[i], mid_ve[j]));
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		ve.push_back({ b, a });
	}
	sort(ve.begin(), ve.end(), comX);
	cout << divide_conquer(0, n - 1);
	return 0;
}
