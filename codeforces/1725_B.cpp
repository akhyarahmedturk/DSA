#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
    int t=1;
    // cin>>t;
    while(t--){
        double n,d;
        cin>>n>>d;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        sort(arr.rbegin(),arr.rend());
        int res=0;
        for(int i=0;i<n;i++){
            if(arr[i]>d) res++;
            else{
                int team_size=ceil((d+1)/arr[i]);
                if(n-i-1>=team_size-1){
                    n-=team_size-1;
                    res++;
                } 
                else break;
            }
            // cout<<"n "<<n<<endl;
        }
        cout<<res<<endl;
    }
    return 0;
}