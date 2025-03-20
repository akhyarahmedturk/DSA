#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,m;
        cin>>n>>m;
        vector<vector<long long>> vec(n,vector<long long>(m));
        vector<pair<long long,long long>> score(n);
        for(int i=0;i<n;i++){
            int curr_score=0;
            for(int j=0;j<m;j++){
                cin>>vec[i][j];
                curr_score+=vec[i][j];
            }
            score[i]={curr_score,i};
        }
        sort(score.rbegin(),score.rend());
        long long ans=0,size=m*n;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans+=vec[score[i].second][j]*(size--);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}