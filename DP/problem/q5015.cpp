#include <iostream>
#include <string>
using namespace std;

int n;
string file[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string arr;
	cin >> arr;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> file[i];
	}
	for (int i = 0; i < n; i++) {
		char check = '*';
		int cnt = 0;
		for (int j = 0; j < arr.size(); j++) {
			if (arr[j] == '*') {
				continue;
			}
			else {
				check = arr[j + 1];
				while (cnt < file[i].size()) {
					if (check == file[i][cnt]) {
						cnt++;
						break;
					}
					cnt++;
				}
			}
			if (cnt >= file[i].size()) {

			}
		}
	}
	return 0;
}