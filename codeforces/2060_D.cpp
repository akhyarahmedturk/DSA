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
        long long n;
        cin >> n;
        vector<long long> arr(n);
        for (int i = 0;i < n;i++) cin >> arr[i];
        bool check = false;
        for (int i = 0;i < n - 1;i++){
            if (arr[i] > arr[i + 1]){
                check = true;
                break;
            }
            else arr[i + 1] -= arr[i];
        }
        if (!check) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}