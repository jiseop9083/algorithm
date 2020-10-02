#include <iostream> 
using namespace std;

int n;
int num[1005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i = 0; i< n; i++){
		cin >> num[i];
	}
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - i - 1; j++){
			if(num[j] > num[j + 1]){
				int swap = num[j];
				num[j] = num[j + 1];
				num[j + 1] = swap;
			}
		}	
	}
	for(int i = 0; i < n; i++){
		cout << num[i] << "\n";
	}
	return 0;
}
