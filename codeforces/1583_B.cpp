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
        long long n,m,a,b,c;
        cin>>n>>m;
        vector<bool> visited(n+1,false);
        while(m--){
            cin>>a>>b>>c;
            visited[b]=true;
        }
        for(int i=1;i<=n;i++){
            if(!visited[i]) {
                for(int j=1;j<=n;j++){
                    if(i!=j){
                        cout<<i<<" "<<j<<endl;
                    }
                }
                break;
            }
        }
    }
    return 0;
}