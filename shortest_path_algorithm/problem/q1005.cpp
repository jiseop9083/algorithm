//���� 1005�� ACM Craft
//�ּ� �ð��� ���ϴ� �������� ���ͽ�Ʈ�� �˰���
//�Ǽ� ������ �ð� �������� 

#include <iostream>
#include <vector>
#include <queue>
using namespace std;// t�׽�Ʈ����, n�ǹ� ����, k �Ǽ����� ��Ģ ����
int t;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, k;
		int dist[1005];//�̵��Ÿ�
		vector<int> edge[1005];//��������, ��������
		vector<int> r_edge[1005];//��������, ��������
		priority_queue<pair<int, int>> pq;//�Ÿ�, ����

		cin >> n >> k;
		for (int j = 1; j <= n; j++) {
			int a;
			cin >> a;
			dist[j] = a;
		}
		for (int j = 0; j < k; j++) {
			int a, b;
			cin >> a >> b;
			r_edge[b].push_back(a);
			edge[a].push_back(b);
		}
		int a;
		cin >> a;
		int min = 100000000000;
		for (int i = 1; i <= n; i++) {
			if (r_edge[i].empty()) {
				if (a == i) {
					min = dist[i];
					break;
				}
				pq.push({ dist[i], i });

				while (!pq.empty()) {
					int now, nowdist;
					nowdist = pq.top().first;
					now = pq.top().second;
					if (now == a) { //&& min < pq.top().first) {
						if(min > nowdist) min = nowdist;
						//cout << nowdist << "\n";
						while (!pq.empty()) pq.pop();
						break;
					}
					pq.pop();
					for (auto e : edge[now]) {
						pq.push({ (nowdist + dist[e]), e });
					}
				}
			}
				
		}
		cout << min << "\n";
		
	}
	return 0;
}
