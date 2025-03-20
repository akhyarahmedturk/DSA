#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        long long n, x;
        cin >> n >> x;
        vector<long long> arr(n);
        for (int i = 0;i < n;i++){
            long long temp;
            cin >> temp;
            arr[i] = temp;
        }
        sort(arr.begin(), arr.end());
        long long start = arr[0] + 1, end = x+arr[0], ans = arr[0];
        while (start <= end){
            long long mid = (start + end) / 2;
            long long cnt = x, i = 0;
            while (cnt >= 0 && i < arr.size()){
                cnt -= (mid - arr[i]);
                i++;
            }
            if (cnt >= 0){
                ans = mid;
                start = mid + 1;
            }
            else end = mid - 1;
        }
        cout << ans << endl;
    }
    return 0;
}