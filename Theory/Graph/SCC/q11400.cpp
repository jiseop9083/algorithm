// 백준 11400 단절선
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int id[100005];
int cnt = 1;
vector<int> ve[100005];
vector<pair<int, int>> an;

int dfs(int x, int par) {
    id[x] = cnt++;
    int ret = id[x];
    for (int i : ve[x]) {
        if (i == par) // 다음에 갈 노드가 부모인 경우 스킵
            continue;
        if (id[i] == 0) {
            int df = dfs(i, x);
            if (df > id[x]) // 우회로가 없을 경우
                an.push_back({min(x, i), max(x, i)}); //정답에 해당 간선을 추가
            ret = min(ret, df);
        }
        else
            ret = min(ret, id[i]);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        ve[a].push_back(b);
        ve[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
        if (id[i] == 0)
            dfs(i, 0);
    sort(an.begin(), an.end());
    cout << an.size() << "\n";
    for (pair<int, int> i : an)
        cout << i.first << " " << i.second << "\n";
    return 0;
}
