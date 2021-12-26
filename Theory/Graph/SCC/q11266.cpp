#백준 11266번 단절점
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int v, e;
vector<int> ve[10005];
int id[10005];
int finished[10005];
int cnt = 1;


int dfs(int x, bool isRoot) {
    id[x] = cnt++; 
    int ret = id[x];
    int child = 0;
 
    for (int i:  ve[x]){
        if (id[i]){
            ret = min(ret, id[i]);
            continue;
        }
        child++;
        int prev = dfs(i, false);

        if (isRoot == false && prev >= id[x])
            finished[x] = 1;
        ret = min(ret, prev);
    }
    if (isRoot == true)
        finished[x] = (child >= 2);
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> v >> e;
    for(int i = 0; i < e; i++){
        int a, b; cin >> a >> b;
        ve[a].push_back(b);
        ve[b].push_back(a);
    }
    
    for (int i = 1; i <= v; i++)
        if (id[i] == 0)
            dfs(i, true);
 
    int an = 0;
    for (int i = 1; i <= v; i++)
        if (finished[i])
            an++;
 
    cout << an << "\n";
    for (int i = 1; i <= v; i++)
        if (finished[i])
            cout << i << " ";

    return 0;
}
