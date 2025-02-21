#include <iostream>
#include <vector>

using namespace std;


int main(){
    int n,k,res=0;
    cin>>n>>k;
    vector<vector<int>> mp(k,vector<int>(3,0));
    for(int i=0;i<n/k;i++){
        for(int j=0;j<k;j++){
            int temp;
            cin>>temp;
            mp[j][temp]++;
        }
    }
    for(int i=0;i<k;i++) res+=min(mp[i][1],mp[i][2]);
    cout<<res;
    return 0;
}