//disjoint set (������Ʈ ��)
//���� �ߺ����� �ʴ� �κ� ���յ�� ������ ���Ҹ� �����ϴ� �ڷᱸ��


//�⺻����

//���� 1197�� �ּ� ���д� Ʈ��

#include <iostream>
#include <queue>
using namespace std;

class Disjoint{
public:
	int ele[10000];
	
	Disjoint(int t) {
		for (int i = 0; i < t; i++) {
			//�ڱ��ڽ����� �ʱ�ȭ
			ele[i] = i;
		}
	}

	int find(int node) {
		//���� root�� ���
		if (node == ele[node]) {
			return node;
		}
		//�θ��� ��带 ã�� ����
		return node = find(ele[node]);
	}

	int sum(int node_a, int node_b) {
		int root_a = find(node_a);
		int root_b = find(node_b);

		//a���տ� b������ �߰�
		ele[root_b] = root_a;
	}
};

//MST �ּ� ���д� Ʈ��
//����ġ ������ �����Ѵ�
//������ �� �� ������ ���� ������ ã��
//���� �����̸� �� ������ ��ġ��
//�ٸ� �����̶�� �Ѿ��

typedef pair<int, pair<int, int>> Edge;
priority_queue<Edge, vector<Edge>, greater<Edge>> edge;
int an;
int n;

int main() {
	//������ ���� �ޱ�
	cin >> n;
	Disjoint disjoint(n);
	
	//���� �Է¹ޱ�


	while (!edge.empty()) {
		Edge e = edge.top();
		edge.pop();
		//�� ������ �ٸ���
		if (disjoint.find(e.second.first) != disjoint.find(e.second.second)) {
			disjoint.sum(e.second.first, e.second.second);
			//�Ÿ� �߰�
			an += e.first;
		}
	}
	return 0;
}