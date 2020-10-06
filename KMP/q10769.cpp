#include <iostream>
#include <string>
using namespace std;

string happy = ":-)";
string sad = ":-(";
int an = 0;
int main() {
	//가속화
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string arr;
	//이모티콘 포함 체크
	int check = 0;
	//입력받기
	getline(cin, arr);
	if (arr.size() >= 3) {
		for (int i = 0; i <= arr.size() - 3; i++) {
			bool isHappy = true;
			bool isSad = true;
			for (int j = 0; j < 3; j++) {
				if (arr[j + i] != happy[j]) {
					isHappy = false;
				}
				if (arr[j + i] != sad[j]) {
					isSad = false;
				}
			}
			if (isHappy == true) {
				//기쁠때는 +1
				an++;
				check++;
			}
			if (isSad == true) {
				//슬플때는 -1
				an--;
				check++;
			}
		}
	}
	//중립
	if (check == 0) {
		cout << "none";
	}
	else if (an == 0) {
		cout << "unsure";
	}
	else if (an > 0) {
		cout << "happy";
	}
	else {
		cout << "sad";
	}
	return 0;
}
