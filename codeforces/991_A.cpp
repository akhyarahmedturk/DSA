#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>

using namespace std;

int main(){
    int T, n, m;
    string temp;
    cin >> T;
    vector<int> res(T, 0);
    for (int i = 0;i < T;i++){
        cin >> n >> m;
        int j = 0;
        for (;j < n;j++){
            cin >> temp;
            m -= temp.length();
            if (m >= 0){
                res[i]++;
            }
            else{
                j++;
                break;
            }
        }
        for (;j < n;j++){
            cin >> temp;
        }
    }
    for (int i = 0;i < T;i++){
        cout << res[i] << endl;
    }
    return 0;
}