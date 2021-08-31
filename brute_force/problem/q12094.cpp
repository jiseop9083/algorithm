//백준 12094번 2048(Hard)
//전에 위로 움직였으면 다시 위로 움직일 필요없다 > 3^10
//위 아래를 하면 다음에는 좌우중 하나
//최댓값을 인자로 넘겨주자

#include <iostream>
#include <cstring>
using namespace std;

int n;
int an = 0;
 


void back(int deep, int pre, int ma, bool check, int table[][22]) {
	if (deep == 10) {
		if (an < ma) {
			an = ma;
		}
		return;
	}
	int cop[22][22];
	for (int k = 0; k < 4; k++) {//상하좌우
		if (k == pre && check == true) {
			continue;
		}
		int m = ma;
		bool che = true;
		for (int p = 0; p < n; p++) {
			for (int q = 0; q < n; q++) {
				cop[p][q] = table[p][q];
			}
		}
		switch (k) {
		case 0:
			for (int j = 0; j < n; j++) {
				int mem = -1;
				int pos;
				for (int i = 0; i < n; i++) {
					if (cop[i][j] == mem) {
						cop[i][j] *= 2;
						cop[pos][j] = 0;
						che = false;
						if (m < cop[i][j]) {
							m = cop[i][j];
						}
						mem = -1;
					}
					else if (cop[i][j] != 0) {
						mem = cop[i][j];
						pos = i;
					}
				}
				int i = 1;
				while (i < n) {
					if (i > 0 && cop[i][j] != 0 && cop[i - 1][j] == 0) {
						cop[i - 1][j] = cop[i][j];
						cop[i][j] = 0;
						if (i > 1)
							i--;
					}
					else i++;
				}
			}
			break;
		case 1:
			for (int j = 0; j < n; j++) {
				int mem = -1;
				int pos;
				for (int i = n - 1; i >= 0; i--) {
					if (cop[i][j] == mem) {
						cop[i][j] *= 2;
						che = false;
						if (m < cop[i][j]) {
							m = cop[i][j];
						}
						cop[pos][j] = 0;
						mem = -1;
					}
					else if (cop[i][j] != 0) {
						mem = cop[i][j];
						pos = i;
					}
				}
				int i = n - 2;
				while (i >= 0) {
					if (i < n - 1 && cop[i][j] != 0 && cop[i + 1][j] == 0) {
						cop[i + 1][j] = cop[i][j];
						cop[i][j] = 0;
						if (i < n - 2) {
							i++;
						}
					}
					else i--;
				}
			}
			break;
		case 2:
			for (int i = 0; i < n; i++) {
				int mem = -1;
				int pos;
				for (int j = 0; j < n; j++) {
					if (cop[i][j] == mem) {
						cop[i][j] *= 2;
						cop[i][pos] = 0;
						che = false;
						if (m < cop[i][j]) {
							m = cop[i][j];
						}
						mem = -1;
					}
					else if (cop[i][j] != 0) {
						mem = cop[i][j];
						pos = j;
					}
				}
				int j = 1;
				while (j < n) {
					if (j > 0 && cop[i][j] != 0 && cop[i][j - 1] == 0) {
						cop[i][j - 1] = cop[i][j];
						cop[i][j] = 0;
						if (j > 1) {
							j--;
						}
					}
					else j++;
				}
			}
			break;
		case 3:
			for (int i = 0; i < n; i++) {
				int mem = -1;
				int pos;
				for (int j = n - 1; j >= 0; j--) {
					if (cop[i][j] == mem) {
						cop[i][j] *= 2;
						che = false;
						if (m < cop[i][j]) {
							m = cop[i][j];
						}
						cop[i][pos] = 0;
						mem = -1;
					}
					else if (cop[i][j] != 0) {
						mem = cop[i][j];
						pos = j;
					}
				}
				int j = n - 2;
				while (j >= 0) {
					if (j < n - 1 && cop[i][j] != 0 && cop[i][j + 1] == 0) {
						cop[i][j + 1] = cop[i][j];
						cop[i][j] = 0;
						if (j < n - 2) {
							j++;
						}
					}
					else j--;

				}
			}
			break;
		}
		back(deep + 1, k, m, che, cop);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//memset(cop, -1, sizeof(cop));
	int board[22][22];
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (an < board[i][j]) {
				an = board[i][j];
			}
		}
	}
	back(0, -1, an , false, board);
	cout << an;
	return 0;
}