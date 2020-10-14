//백준 2309번 일곱 난쟁이

#include <iostream>
#include <algorithm>
#define INF 1000
using namespace std;

//배열을 여유롭게
int num[15];
int sum = 0;

int main() {
	//입력
	for (int i = 0; i < 9; i++) {
		cin >> num[i];
		sum += num[i];
	}
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			//7명의 합이 100일때
			if (sum - num[i] - num[j] == 100) {
				//정렬했을때 뒤로 빠지도록 설정
				num[i] = INF;
				num[j] = INF;
				//탐색 종료
				i = 9;
				break;
			}
		}
	}
	sort(num, num + 9);
	for (int i = 0; i < 7; i++) {
		cout << num[i] << "\n";
	}
	return 0;
}
