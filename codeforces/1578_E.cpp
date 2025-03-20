#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,p,res=0,level=1;
        cin>>n>>p;
        n=pow(2,n)-1;
        while(pow(2,level-1)<p && n){
            res++;
            n-=(pow(2,level-1));
            level++;
        }
        if(n>0) res+=ceil((n*1.0)/p);
        cout<<res<<endl;
    }
    return 0;
}