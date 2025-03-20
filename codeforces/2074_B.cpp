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
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        for(int i=0;i<n;i++){
            long long temp;
            cin>>temp;
            pq.push(temp);
        }
        while(pq.size()>1){
            long long a=pq.top();
            pq.pop();
            long long b=pq.top();
            pq.pop();
            pq.push(a+b-1);
        }
        cout<<pq.top()<<endl;
    }
    return 0;
}