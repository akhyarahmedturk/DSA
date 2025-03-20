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
        long long n, k, sum = 0;
        cin >> n >> k;
        vector<long long> arr(n + 1);
        for (int i = 1;i <= n;i++){
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        for (int i = 1;i <= n;i++){
            arr[i] += arr[i - 1];
        }
        long long res = 0, start = 0;
        while (k >= 0){
            res = max(res, arr[n - k] - arr[start]);
            start += 2;
            k--;
        }
        cout << res << endl;
    }
    return 0;
}