//���� 1167�� Ʈ���� ����
//���Ƿ� 1���� ��Ʈ��� �ص� ��

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector<pair<int, int>> ve[100005];
bool visit[100005];
int n;
int an = 0;

int dfs(int num) {
	visit[num] = true;
	//������ ���� ���Ѱ�
	//������ 2���̻��� ��� ���� üũ
	int deep = 0;
	int secon = 0;
	int check = 0;
	for (pair<int, int> i : ve[num]) {
		if (visit[i.first] == false) {
			check++;
			int a = i.second + dfs(i.first);
			if (a > deep) {
				secon = deep;
				deep = a;
			}
			else if (a > secon) {
				secon = a;
			}
		}
	}
	if (deep > an) {
		an = deep;
	}
	if (check > 1 && deep + secon > an) {
		an = deep + secon;
	}
	visit[num] = false;
	return deep;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	memset(visit, false, sizeof(visit));
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		while (1) {
			int b, c;
			cin >> b;
			if (b == -1)
				break;
			cin >> c;
			ve[a].push_back({ b, c });
		}

	}
	dfs(1);
	cout << an;
	return 0;
}