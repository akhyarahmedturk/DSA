#include<iostream>
#include<vector>
#include<stack>
#include<limits>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int main(){
    int t,n,m;
    cin >> t;
    while (t--){
        cin>>n>>m;
        vector<long long> vec(n+1);
        vector<long long> vec2(m);
        vec[0]=LLONG_MIN;
        for(int i=1;i<=n;i++){
            cin>>vec[i];
        }
        for(int i=0;i<m;i++){
            cin>>vec2[i];
        }
        sort(vec2.begin(),vec2.end());
        int i=1;
        // cout<<"                      t "<<t<<endl;
        while(i<=n){
            int start=0,end=m-1,mid;
            while(start<end){
                mid=(start+end)/2;
                if(vec2[mid]-vec[i]>=vec[i-1]){
                    if(vec[2]-vec[i]<vec[i]) vec[i]=vec2[mid]-vec[i];
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
            // cout<<vec[i]<<" i "<<i<<endl;
            if(vec[i]>=vec[i-1]){
                long long temp=min(vec[i],vec2[start]-vec[i]);
                if(temp>=vec[i-1]) vec[i]=temp;
            }
            else if(vec[i-1]<=vec2[start]-vec[i]) vec[i]=vec2[start]-vec[i];
            else break;
            i++;
        }
        if(i>=n+1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}