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
        long long n,m,k;
        cin>>n>>m>>k;
        k-=2;
        // ((n-1)*(n))/2 gives the maximum number of edges
        // n-1 is the minimum number of edges
        if(n==1LL && m==0 && k>=0LL) cout<<"YES"<<endl; 
        else if(k<1LL) cout<<"NO"<<endl; 
        else if(m<n-1LL || m>((n-1LL)*(n))/2LL) cout<<"NO"<<endl; // has less edges or has excess edges
        else if(m==((n-1)*(n))/2LL) cout<<"YES"<<endl; // fully connected graph (diameter is 1)
        else if(k>=2LL) cout<<"YES"<<endl; // diameter will be 2
        else cout<<"NO"<<endl;
    }
    return 0;
}