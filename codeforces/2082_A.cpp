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
        int n,m;
        cin>>n>>m;
        vector<int> cols(m,0),rows(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char ch;
                cin>>ch;
                if(ch=='1'){
                    cols[j]++;
                    rows[i]++;
                }
            }
        }
        if(rows.size()==1){
            cout<<rows[0]<<endl;
            continue;
        }
        if(cols.size()==1){
            cout<<cols[0]<<endl;
            continue;
        }
        int res=0;
        for(int i=0;i<n;i++){
            if(rows[i]%2==0) continue;
            for(int j=0;j<m;j++){
                if(cols[j]%2==1){
                    cols[j]++;
                    break;
                }
            }
            res++;
        }
        for(int i=0;i<m;i++){
            if(cols[i]%2==1) res++;
        }
        cout<<res<<endl;
    }
    return 0;
}