#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<unordered_set>
#include<algorithm>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        bool check=false;
        vector<int> res(n);
        for(int i=0;i<n;i++){
            vector<int> vec(m);
            for(int j=0;j<m;j++){
                cin>>vec[j];
            }
            if(check) continue;
            sort(vec.begin(), vec.end());
            for(int j=0;j<m-1;j++){
                if(vec[j+1]-vec[j]!=n){
                    check=true;
                    break;
                }
            }
            res[vec[0]]=i+1;
        }
        if(check) cout<<-1<<endl;
        else{
            for(int i=0;i<n;i++) cout<<res[i]<<" ";
            cout<<endl;
        }
    }
    return 0;
}