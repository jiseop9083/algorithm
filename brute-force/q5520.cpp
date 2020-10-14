//백준 5520번 The locks 


#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int button[9];
const int table[9][9] = { 
{1,1,0,1,1,0,0,0,0},
{1,1,1,0,0,0,0,0,0}, 
{0,1,1,0,1,1,0,0,0}, 
{1,0,0,1,0,0,1,0,0},
{0,1,0,1,1,1,0,1,0},
{0,0,1,0,0,1,0,0,1},
{0,0,0,1,1,0,1,1,0},
{0,0,0,0,0,0,1,1,1},
{0,0,0,0,1,1,0,1,1}};
int an[50];
int len = 50;
int state[9];

void search(int deep) {
	//조합끝, 정답확인
	if (deep == 9) {
		int check = 0;
		//모두 12시인지 확인
		for (int i = 0; i < 9; i++) {
			if (state[i] != 0) {
				check = 1;
				break;
			}
		}
		if (check == 0) {
			int cnt = 0;
			for (int i = 0; i < 9; i++) {
				cnt += button[i];
			}
			//len은 스위치를 최소한으로 누르는 횟수
			if (len > cnt) {
				len = cnt;
				cnt = 0;
				for (int i = 0; i < 9; i++) {
					for (int j = 0; j < button[i]; j++) {
						an[cnt] = i + 1;
						cnt++;
					}
				}
			}
		}
		return;
	}
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j < 9; j++) {
			//시계 상태 변경
			if (table[deep][j]) {
				state[j] = (state[j] + i) % 4;
			}
		}
		button[deep] += i;
		search(deep + 1);
		//탐색 후 복구 
		button[deep] -= i;
		for (int j = 0; j < 9; j++) {
			if (table[deep][j]) {
				state[j] = (state[j] + 4 - i) % 4;
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(button, 0, sizeof(button));
	for (int i = 0; i < 9; i++) {
		cin >> state[i];

	}
	search(0);
	sort(an, an + len);
	for (int i = 0; i < len; i++) {
		cout << an[i] << " ";
	}
	return 0;
}
