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
        int n,k;
        cin>>n>>k;
        int res=INT_MAX,temp,even_num=0;
        for(int i=0;i<n;i++){
            cin>>temp;
            if(temp%k==0) res=0;
            res=min(res,k-temp%k);
            if(temp%2==0) even_num++;
        }
        if(res==0 || k!=4 || n==1) cout<<res<<endl;
        else if(even_num>=2) cout<<0<<endl;
        else cout<<min(res,2-even_num)<<endl;
    }
    return 0;
}