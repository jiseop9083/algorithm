#include <iostream>
#include <cmath>
using namespace std;

int t;
int a, b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		int dis = b - a;
		int num = (int)sqrt(dis);
		int pos = num * num;
		int an = (num * 2) - 1;
		if (dis != pos) {
			an++;
		}
		if (dis > pos + num) {
			an++;
			pos += num;
			num++;
		}
		cout << an << "\n";

	}

	return 0;
}