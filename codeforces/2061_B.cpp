#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

struct comp{
    bool operator()(const pair<pair<long long, long long>, pair<long long, long long>>& a, const pair<pair<long long, long long>, pair<long long, long long>>& b){
        if (a.first.first == b.first.first) return a.first.second < b.first.second;
        else return a.first.first < b.first.first;
    }
};

int main(){
    long long t;
    cin >> t;
    while (t--){
        long long n;
        cin >> n;
        long long same_1 = -1, same_2 = -1;
        unordered_set<long long> s;
        for (long long i = 0;i < n;i++){
            long long a;
            cin >> a;
            if (s.find(a) != s.end()){
                if (same_1 == -1) same_1 = a;
                else same_2 = a;
                s.erase(a);
            }
            else s.insert(a);
        }
        if (same_1 == -1) cout << -1 << endl;
        else if (same_2 != -1) cout << same_1 << " " << same_1 << " " << same_2 << " " << same_2 << endl;
        else{
            vector<long long> arr(n - 2);
            long long i = 0;
            for (auto it = s.begin();it != s.end();it++){
                arr[i++] = *it;
            }
            sort(arr.begin(), arr.end());
            i = n - 3;
            for (;i > 0;i--){
                if (arr[i - 1] + same_1 * 2 > arr[i]){
                    break;
                }
            }
            if (i != 0) cout << same_1 << " " << same_1 << " " << arr[i] << " " << arr[i - 1] << endl;
            else cout << -1 << endl;
        }
    }
    return 0;
}