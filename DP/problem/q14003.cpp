#include <iostream>
using namespace std;

int n;
int num[1000005];
int len[1000005];
int table[1000005];
int an = 1;
int pos;
int pri[1000005];

void bs(int start, int end, int nu) {
	if (start > end) {
		return;
	}
	int mid = (start + end) / 2;
	if (num[mid] >= nu) {
		pos = mid;
		bs(start, mid - 1, nu);
	}
	else if (num[mid] < nu) {
		bs(mid + 1, end, nu);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> table[i];
	}
	num[0] = table[0];
	len[0] = 1;
	for (int i = 1; i < n; i++) {
		pos = -1;
		bs(0, an, table[i]);
		if (pos == -1) {
			num[an] = table[i];
			pos = an;
			an++;
		}
		else {
			num[pos] = table[i];
		}
		len[i] = pos + 1;
	}
	int cnt = an;
	cout << an << "\n";
	for (int i = n-1; i >=0; i--) {
		if (len[i] == cnt) {
			pri[cnt] = table[i];
			cnt--;
		}
		if (cnt == -1) {
			break;
		}
	}
	for (int i = 1; i <= an; i++) {
		cout << pri[i] <<" "; 
	}
	return 0;
}