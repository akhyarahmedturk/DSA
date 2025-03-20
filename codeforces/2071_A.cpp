#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_set>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
    long long t;
    cin>>t;
    while (t--){
        long long n,min_diff=1e9+7,prv,curr;
        cin>>n;
        cin>>prv;
        for (int i=1;i<n;i++){
            cin>>curr;
            min_diff=min(min_diff,curr-prv);
            prv=curr;
        }
        if(min_diff<0) cout<<0<<endl;
        else cout<<min_diff/2+1<<endl;
    }
    return 0;
}