#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int main(){
    long long t;
    cin >> t;
    while (t--){
        long long n, sub = -1, min_diff = 1e9 + 7;
        cin >> n;
        vector<long long> a(n), b(n);
        for (long long i = 0;i < n;i++) cin >> a[i];
        for (long long i = 0;i < n;i++) cin >> b[i];
        bool check = false;
        for (long long i = 0;i < n;i++){
            if (a[i] >= b[i]){
                min_diff = min(min_diff, a[i] - b[i]);
                if (sub > min_diff){
                    check = true;
                    break;
                }
            }
            else if (sub != -1){
                check = true;
                break;
            }
            else{
                sub = b[i] - a[i];
            }
        }
        if (check || sub > min_diff) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}