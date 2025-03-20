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
        int n,res=-1;
        cin>>n;
        vector<bool> last_to_i(n+1,false);
        vector<bool> i_to_last(n+1,false);
        for(int i=1;i<=n;i++){
            int temp;
            cin>>temp;
            if(temp==0) i_to_last[i]=true;
            else last_to_i[i]=true;
        }
        if(last_to_i[1]){
            cout<<n+1<<" ";
            for(int i=1;i<=n;i++) cout<<i<<" ";
            cout<<endl;
        }
        else if(i_to_last[n]){
            for(int i=1;i<=n+1;i++) cout<<i<<" ";
            cout<<endl;
        }
        else{
            int cutoff=-1;
            for(int i=1;i<n;i++){
                if(i_to_last[i] && last_to_i[i+1]){
                    cutoff=i;
                    break;
                }
            }
            if(cutoff==-1) cout<<cutoff<<endl;
            else{
                for(int i=1;i<=cutoff;i++) cout<<i<<" ";
                cout<<n+1<<" ";
                for(int i=cutoff+1;i<=n;i++) cout<<i<<" ";
                cout<<endl;
            }
        }
    }
    return 0;
}