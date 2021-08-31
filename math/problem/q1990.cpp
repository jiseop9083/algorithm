//���� 1990�� �Ҽ����Ӹ����
//�Ӹ������ ã�� �Ҽ��� ���� ã��

#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> pelin;
int a, b;
int sosu[10005];
int cnt = 1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> a >> b;
	for (int i = 1; i < 10000; i++) {
		string num = to_string(i);
		string copy = num;
		reverse(copy.begin(), copy.end());
		pelin.push_back(stoi(num + copy));
		num.pop_back();
		pelin.push_back(stoi(num + copy));
	}
	sort(pelin.begin(), pelin.end());
	sosu[0] = 2;
	for (int i = 3; i < 10000; i++) {
		int check = 0;
		for (int j = 0; j < cnt; j++) {
			if (i % sosu[j] == 0) {
				check = 1;
				break;
			}
		}
		if (check == 0) {
			sosu[cnt] = i;
			cnt++;
		}
	}
	for (int i : pelin) {
		if (i < a) {
			continue;
		}
		if (i > b) {
			break;
		}
		int check = 0;
		for (int j = 0; sosu[j] <= (int)sqrt(i); j++) {
			//cout << (int)sqrt(i) << "ddd" << sosu[j] << "\n";
			if (i % sosu[j] == 0) {
				check = 1;
				break;
			}
		}
		if (check == 0) {
			cout << i << "\n";
		}
	}
	cout << -1;
	return 0;
}