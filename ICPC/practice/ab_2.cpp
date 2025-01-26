#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int main(){
    int T, m, n, k, temp, res, i,Max;
    cin>>T;
    while (T--){
        Max=0;
        cin >> m >> n >> k;
        vector<int> row(m, 0);
        i = 1;
        while (i <= m * n){
            cin >> temp;
            row[(temp-1) / n]++;
            Max=max(Max,row[(temp-1) / n]);
            if (Max == n || (n - Max <= k && i>=n)){
                break;
            }
            i++;
        }
        cout << i << endl;
        i++;
        while (i <= m * n) {
            cin >> temp;
            i++;
        }
    }
    return 0;
}