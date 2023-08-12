#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> getPi(string arr){
    int len = arr.size();
    int start = 1;
    int matched = 0;
    vector<int> ret(len, 0);
    while (start + matched < len){
        if(arr[start + matched] == arr[matched]){
            ret[start + matched] = matched + 1;
            matched++;
        } else{
            if(matched == 0){
                start++;
            }else{
                start += (matched - ret[matched - 1]);
                matched = ret[matched - 1];
            }
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string arr;
    cin >> arr;
    int answer = 0;
    for(int i =0; i < arr.size(); i++){
        vector<int> pi = getPi(arr.substr(i, arr.size() - i));
        
        for(int i : pi){
            answer = max(answer, i);
        }
    }
    
    cout << answer;
    return 0;
}