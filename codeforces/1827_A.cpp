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
        vector<int> a(n);
        vector<int> b(n);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());  
        int start=n,filled=0;
        long long res=1,mod=1e9+7;
        for(int i=n-1;i>=0;i--){
            while(start>0 && a[start-1]>b[i]) start--;
            res=(res*(n-start-filled))%mod;
            filled++; 
        }
        cout<<res<<endl;
    }
    return 0;
}