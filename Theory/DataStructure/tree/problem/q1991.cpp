//백준 1991번 트리 순회
//부모 노드를 참고할 필요가 없다

#include <iostream>
using namespace std;

struct tree {
	int value;
	tree* laft;
	tree* right;
};

int n;

tree arr[28];

void front(int i) {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cout << char(i + 'A');
	if (arr[i].laft != nullptr) {
		front(arr[i].laft->value);
	}
	
	if (arr[i].right != nullptr) {
		front(arr[i].right->value);
	}
}


void mid(int i) {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	if (arr[i].laft != nullptr) {
		mid(arr[i].laft->value);
	}
	cout << char(i + 'A');
	if (arr[i].right != nullptr) {
		mid(arr[i].right->value);
	}
}

void back(int i) {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	if (arr[i].laft != nullptr) {
		back(arr[i].laft->value);
	}
	if (arr[i].right != nullptr) {
		back(arr[i].right->value);
	}
	cout << char(i + 'A');
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		int num = (int)(a - 'A');
		arr[num].value = num;
		if (b != '.') {
			arr[num].laft = &arr[(int)(b - 'A')];
		}
		else {
			arr[num].laft = nullptr;
		}
		if (c != '.') {
			arr[num].right = &arr[(int)(c - 'A')];
		}
		else {
			arr[num].right = nullptr;
		}
	}
	front(0);
	cout << "\n";
	mid(0);
	cout << "\n";
	back(0);
	return 0;
}