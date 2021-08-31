//백준 15686번 치킨 배달
//조합, 브루트포스

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, m;
pair<int, int> house[105];
pair<int, int> shop[55];
vector<int> shop_num;
int shop_cnt = 0;
int house_cnt = 0;
int an = 100000000;

void search(int deep) {
	if (shop_num.size() == m) {
		int sum = 0;
		for (int j = 0; j < house_cnt; j++) {
			int chicken = 100000;
			for (int i = 0; i < m; i++) {
				int a = abs(house[j].first - shop[shop_num[i]].first) + abs(house[j].second - shop[shop_num[i]].second);
				if (chicken > a) {
					chicken = a;
				}
			}
			sum += chicken;
		}
		if (an > sum) {
			an = sum;
		}
	}
	if (deep < shop_cnt) {
		shop_num.push_back(deep);
		search(deep + 1);
		shop_num.pop_back();
		search(deep + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			if (a == 1) {
				house[house_cnt] = { i,j };
				house_cnt++;
			}
			else if (a == 2) {
				shop[shop_cnt] = { i,j };
				shop_cnt++;
			}
		}
	}
	search(0);
	cout << an;
	return 0;
}