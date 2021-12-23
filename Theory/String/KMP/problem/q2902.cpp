//백준 2902번 KMP는 왜 KMP일까?

#include <iostream>
#include <string>
using namespace std;

char an[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string arr; 
	cin >> arr;
	an[0] = arr[0];
	int cnt = 1;
	for (int i = 1; i < arr.size(); i++) {
		if (arr[i] == '-') {
			an[cnt] = arr[i + 1];
			cnt++;
		}
	}
	for (int i = 0; i < cnt; i++) {
		cout << an[i];
	}
	return 0;
}