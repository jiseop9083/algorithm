//���� 16917�� ��� �� �Ķ��̵� ��
//�ݹ��� �����ϸ� ���̵�

#include <iostream>
#include <algorithm>
using namespace std;
int an = 0;

int main() {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	if (a + b >= 2 * c) {
		if (x > y) {
			an += y * 2 * c;
			x -= y;
			an += min(a, 2 * c) * x;
		}
		else {
			an += x * 2 * c;
			y -= x;
			an += min(b, 2 * c) * y;
		}
	}
	else {
		an += (a * x) + (b * y);
	}
	cout << an;
	return 0;
}