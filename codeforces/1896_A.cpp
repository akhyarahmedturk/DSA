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
        int n,first,temp;
        cin>>n;
        cin>>first;
        for(int i=1;i<n;i++) cin>>temp;
        if(first==1) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}