//���� 1946�� ���� ���
//�� �о��� �ϵ��� ���� Ż������ �ʴ´�!!



#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool he(pair<int, int> a, pair <int, int> b) { //���� �������� ��������
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else return a.first < b.first;
}



int main() {
	vector<pair<int, int>> ve;
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		ve.clear();
		for (int j = 0; j < n; j++) {
			int a, b;
			cin >> a >> b;
			ve.push_back({ a, b });
		}
		sort(ve.begin(), ve.end(), he);
		int sum = n;
		int bound = ve[0].second;
		for (int j = 1; j < ve.size(); j++) {
			//cout << ve[j].first << ve[j].second << "\n";
			if (bound < ve[j].second) {
				sum--;
			}
			else {
				bound = ve[j].second;
			}
			

		}

		cout << sum << "\n";
	}
	return 0;
}