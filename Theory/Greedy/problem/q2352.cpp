//백준 2352번 반도체 설계
// 간선을 이을 때 최대로 선을 연결할 수 있는 것 중 무작위로 고르자!

#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int>> ve[40001];//시작, 도착, 연결 개수

int main() {
	
	int n;
	int count = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		ve[0].push_back({ i, a });
	}
	vector<pair<int ,int>>::iterator iter;
	int i = 0;
	while (!ve[i].empty()) {
		int max = 0;
		int start;
		for (int j = 0; j < ve[i].size(); j++) {
			int con = 0;
			for (iter = ve[i].begin(); iter != ve[i].end(); iter++) {
				if ((ve[i])[j].first < iter->first && (ve[i])[j].second < iter->second ||
					(ve[i])[j].first > iter->first && (ve[i])[j].second > iter->second) {
					con++;
				}

			}
			if (con > max) {
				max = con;
				start = j;
			}
		}
		if (max == 0) {
			cout << i+1;
			break;
		}
		//cout << max << start << "\n";
		for (iter = ve[i].begin(); iter != ve[i].end(); iter++) {
			if ((ve[i])[start].first < iter->first && (ve[i])[start].second < iter->second ||
				(ve[i])[start].first > iter->first && (ve[i])[start].second > iter->second) {
				ve[i+1].push_back({ iter->first, iter->second });
			}
		}
		i++;
	}
			
	return 0;
}