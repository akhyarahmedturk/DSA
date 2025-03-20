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
        long long n,sum=0,min1=INT_MAX,min2=INT_MAX;
        cin>>n;
        for(int i=0;i<n;i++){
            int m,temp;
            cin>>m;
            priority_queue<long long> pq;
            for(int i=0;i<m;i++){
                cin>>temp;
                pq.push(temp);
                if(pq.size()>2) pq.pop();
            }
            min1=min(min1,pq.top());
            sum+=pq.top();
            pq.pop();
            min2=min(min2,pq.top());
        }
        cout<<sum-min1+min(min1,min2)<<endl;
    }
    return 0;
}