//백준 11054번 가장 긴 바이토닉 부분 수열
//최장 증가 수열 2번 사용 > 2 * n * log n

#include <iostream>
#include <cstring>
using namespace std;

int n;
int num[1005];
int uprange[1005];
int downrange[1005];
int number[1005];//임시증가 수열
int cnt;
int pos;

void bs(int nu, int start, int end) {//인덱스를 리턴
	if (start > end) {
		return;
	}
	int mid = (start + end) / 2;
	if (nu > number[mid]) {
		bs(nu, mid +1, end);
	}
	else if (nu <= number[mid]) {
		pos = mid;
		bs(nu, start, mid - 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	cnt = 0;
	memset(number, 0, sizeof(number));
	for (int i = 0; i < n; i++) {
		pos = -1;
		bs(num[i], 0, cnt - 1);
		if (pos == -1) {
			number[cnt] = num[i];
			uprange[i] = cnt;
			cnt++;
		}
		else {
			number[pos] = num[i];
			uprange[i] = pos;
		}
	}
	memset(number, 0, sizeof(number));
	cnt = 0;
	for (int i = n - 1; i >=0; i--) {
		pos = -1;
		bs(num[i], 0, cnt - 1);
		if (pos == -1) {
			number[cnt] = num[i];
			downrange[i] = cnt;
			cnt++;
			
		}
		else {
			number[pos] = num[i];
			downrange[i] = pos;
		}
	}
	int ma = 0;
	for (int i = 0; i < n; i++) {
		if (ma < uprange[i] + downrange[i] + 1) {
			ma = uprange[i] + downrange[i] + 1;
		}
	}
	cout << ma;
	return 0;
}