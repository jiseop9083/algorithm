// root 밑에서 사이클이 있으면 해당x
// 이전 정점에서 그 위의 정점으로 갈 수 있는 우회로가 2개 이상이면 해당x
// 해당 정점 외에서 사이클이 존재하면 해당x

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n ,m;
vector<int> ve[300005];
int id[300005];
int pe[300005]; // i를 서브스패닝트리 루트로 하는 부모 벡에지 개수
int we[300005]; // i를 서브스패닝트리 루트로 하는 조금이라도 포함된 벡에지 개수
int se[300005]; // i를 서브스패닝트리 루트로 하는 완전한 벡에지의 개수
			
			
int cnt = 1;
long long an = 0;


void dfs(int x, int pre){
    id[x] = cnt++;
    for(int i : ve[x]){
        if(i == pre)
            continue;
        if(id[i] == 0){
            int temp = se[x];
			dfs(i, x);
			pe[i] = se[x] - temp;
			se[x] += se[i];
			we[x] += we[i];
		}
		else if (id[x]>id[i]) {
			we[x]++;
			se[i]++;
		}
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m; 
    for(int i =0; i < m; i++){
        int a, b; cin >> a >> b;
        ve[a].push_back(b);
        ve[b].push_back(a);
    }
    for(int i= 1; i <= n; i++){
        if(id[i] == 0)
            dfs(i, 0);
    }
    return 0;
}
