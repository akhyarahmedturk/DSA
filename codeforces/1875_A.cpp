#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        long long a, b, n;
        cin >> a >> b >> n;
        long long res = b - 1;
        for (int i = 0;i < n;i++){
            cin >> b;
            res += min(a - 1, b);
        }
        cout << res + 1 << endl;
    }
    return 0;
}