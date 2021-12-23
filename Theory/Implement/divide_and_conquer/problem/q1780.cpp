#include <iostream>
using namespace std;

int n;
int table[2500][2500];
int an[4] = { 0,0,0,0 };

int conquer(int xstart, int xend, int ystart, int yend) {
	int cnt = 0;
	if (xstart == 1 && xend == n) {
		cnt = 1;
	}
	if (xstart == xend && ystart == yend) {
		if (cnt == 1) {
			an[table[xstart][ystart] + 1]++;
		}
		return table[xstart][ystart] + 1;
	}
	int check[4] = { 0,0,0,0 };
	int len = (xend - xstart + 1) / 3;
	for (int i = xstart; i <= xend; i += len) {
		for (int j = ystart; j <= yend; j += len) {
			check[conquer(i, i + len - 1, j, j + len - 1)]++;
		}
	}
	if (check[0] == 9) {
		if (cnt == 1) {
			an[0]++;
		}
		return 0;
	}
	else if(check[1] == 9){
		if (cnt == 1) {
			an[1]++;
		}
		return 1;
	}
	else if (check[2] == 9) {
		if (cnt == 1) {
			an[2]++;
		}
		return 2;
	}
	else {
		an[0] += check[0];
		an[1] += check[1];
		an[2] += check[2];
		return 3;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> table[i][j];
		}
	}
	conquer(1, n, 1, n);
	cout << an[0] << "\n";
	cout << an[1] << "\n";
	cout << an[2];
	return 0;
}