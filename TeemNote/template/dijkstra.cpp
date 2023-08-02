//���ͽ�Ʈ��
//�ִܰ�α��ϱ�
//�ִ��� �����ϴ� �켱���� ť�� �̿��Ͽ� �����Ѵ�


//�⺻ ����
//���� 1753�� �ִܰ��
//���� 1238�� ��Ƽ

#include <iostream>
#include <vector>
#include <queue>
#define INF 2000000000
using namespace std;

int node[1005];
//���� ����
vector<pair<int, int>> ve[1005];
//����ġ, ���� ���
priority_queue<pair<int, int>> pq;
//���� ����
int n;

void dij() {
	while (!pq.empty()) {
		int dis = -pq.top().first;
		int con = pq.top().second;
		pq.pop();
		for (pair<int, int> i : ve[con]) {
			int cost = i.first + dis;
			int next = i.second;
			if (cost < node[next]) {
				node[next] = cost;
				pq.push({ -cost, next });
			}
		}
	}
}

int main() {
	//�������� �Է� �ޱ�

	for (int i = 1; i <= n; i++) {
		int a, b,c;
		cin >> a >>b >> c;
		ve[a].push_back({ c, b });
		//���� �ʱ�ȭ
		node[i] = INF;
	}
	//������ �Է�
	pq.push({ 0,1 });
	return 0;
}

int edge[105][105];

int floyd_warshall() {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			edge[i][j] = INF;
			if (i == j) edge[i][j] = 0;
		}
	}
	//�Է¹ޱ�
	int a, b, c; cin >> a >> b >> c;
	if (edge[a][b] > c) {
		edge[a][b] = c;
	}
	for (int mid = 1; mid <= n; mid++) {
		for (int start = 1; start <= n; start++) {
			for (int end = 1; end <= n; end++) {
				if (start == end || mid == start || mid == end) {
					continue;
				}
				if (edge[start][end] > edge[start][mid] + edge[mid][end]) {
					edge[start][end] = edge[start][mid] + edge[mid][end];
				}
			}
		}
	}
}