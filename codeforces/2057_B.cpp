#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<unordered_set>
#include<algorithm>
using namespace std;
int main(){
    long long t;
    cin >> t;
    while (t--){
        long long n, temp, k;
        cin >> n >> k;
        map<long long, int> freq;
        for (int i = 0;i < n;i++){
            cin >> temp;
            freq[temp]++;
        }
        if (k >= n - 1){
            cout << 1 << endl;
            continue;
        }
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (auto it = freq.begin();it != freq.end();it++){
            pq.push(it->second);
        }
        int size = pq.size();
        while (pq.top() <= k){
            k -= pq.top();
            pq.pop();
            size--;
        }
        cout << size << endl;
    }
    return 0;
}