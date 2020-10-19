//백준 12865번 평범한 배낭

#include <iostream>
#include <algorithm>
using namespace std;

int knapsack[105][100005];
pair<int, int> item[101];
int n, k;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        item[i] = { a, b };
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            knapsack[i][j] = max(knapsack[i][j], knapsack[i - 1][j]);
            if (j - item[i].first >= 0) {
                knapsack[i][j] = max(knapsack[i][j], knapsack[i - 1][j - item[i].first] + item[i].second);
            }
        }
    }

    cout << knapsack[n][k];
	return 0;
}
