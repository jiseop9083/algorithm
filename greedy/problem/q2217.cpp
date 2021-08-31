//백준 2217번 로프
//vector를 오름차순 정렬 후, 최대무게를 구하자.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	vector<int> ve;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		ve.push_back(a);
	}
	sort(ve.begin(), ve.end());
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (max < ((n - i) * ve[i])) {
			max = ((n - i) * ve[i]);
		}
	}
	cout << max << "\n";
	return 0;
}