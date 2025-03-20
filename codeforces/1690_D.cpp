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
        long long n,k,res=INT_MAX,w=0;
        cin>>n>>k;
        string str;
        cin>>str;
        for(int i=0;i<k-1;i++) if(str[i]=='W') w++;
        for(int i=k-1;i<n;i++){
            if(str[i]=='W') w++;
            res=min(res,w);
            if(str[i-k+1]=='W') w--;
        }
        cout<<res<<endl;
    }
    return 0;
}