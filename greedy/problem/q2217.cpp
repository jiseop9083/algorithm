//���� 2217�� ����
//vector�� �������� ���� ��, �ִ빫�Ը� ������.

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