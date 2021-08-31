//백준 2602번 돌다리 건너기
//위치, 위치, 마법번호 >> 방법 수

#include <iostream>
#include <string>
using namespace std;

int n;
int cnt;
int num[25];
int stone[105][2];
int table[105][2][25];
char trans[5] = { 'R', 'I', 'N', 'G', 'S' };



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string arr;
	cin >> arr;
	cnt = arr.size();
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < 5; j++) {
			if (trans[j] == arr[i]) {
				num[i] = j;
				break;
			}
		}
	}
	cin >> arr;
	n = arr.size();
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < 5; j++) {
			if (trans[j] == arr[i]) {
				stone[i][0] = j;
				break;
			}
		}
	}
	cin >> arr;
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < 5; j++) {
			if (trans[j] == arr[i]) {
				stone[i][1] = j;
				break;
			}
		}
	}
	for (int j = 0; j < n; j++) {
		for (int k = 0; k < 2; k++) {
			if (stone[j][k] == num[0]) {
				table[j][k][0]++;
			}
		}
	}

	for (int i = 1; i < cnt; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 2; k++) {
				if (stone[j][k] == num[i]) {
					for (int p = 0; p < j; p++) {
						table[j][k][i] += table[p][(k + 1) % 2][i - 1];
					}
				}
			}
		}	
	}
	int an = 0;
	for (int j = 0; j < n; j++) {
		for (int k = 0; k < 2; k++) {
			an += table[j][k][cnt - 1];
		}
	}
	cout << an;
	return 0;
}