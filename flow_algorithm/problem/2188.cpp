//백준 2188번 축사 배정
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

class Flow {
public:
	struct Edge {
		int from, to, capa, flow;
		Edge* reverse;
		Edge(int from, int to, int capa)
			: from(from), to(to), capa(capa), flow(0), reverse(nullptr) {}
		Edge(const Edge& edge) :
			from(edge.from), to(edge.to), capa(edge.capa), flow(edge.flow), reverse(edge.reverse) {}
	
	};

	vector<vector<Edge*>> graph;
	vector<bool>visit;
	int n,  source, sink;
	Flow(int t) : n(t), source(0), sink(t-1), graph(t), visit(t) { }

	void add(int from, int to) {
		Edge* e = new Edge(from, to, 1);
		Edge* e_reverse = new Edge(to, from, 0);
		graph[from].push_back(e);
		graph[to].push_back(e_reverse);
		e->reverse = e_reverse;
		e_reverse->reverse = e;
	}

	int dfs(int con, int maxflow) {
		if (con == sink) {
			return maxflow;
		}
		if (visit[con])
			return 0;
		visit[con] = true;

		for (auto e : graph[con]) {
			if (e->capa > e->flow) {
				int flow = dfs(e->to, min(maxflow, e->capa - e->flow));
				if (flow > 0) {
					e->flow += flow;
					e->reverse->flow -= flow;
					return flow;
				}
			}
		}
		return 0;
	}

	int answer() {
		int ret = 0;
		while (1) {
			int flow = dfs(source, INF);
			fill(visit.begin(), visit.end(), false);
			if (flow == 0) {
				break;
			}
			ret += flow;
		}
		return ret;
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int n, m;
	
	cin >> n >> m;
	Flow flow(n + m + 3);
	for (int i = 1; i <= n; i++) {
		flow.add(0, i);
	}
	for (int i = 1; i <= m; i++) {
		flow.add(n + i, n + m + 2);
	}
	for (int i = 1; i <= n; i++) {
		int cnt; 
		cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			int a; cin >> a;
			flow.add(i, n + a);
		}
	}
	cout << flow.answer();
	return 0;
}