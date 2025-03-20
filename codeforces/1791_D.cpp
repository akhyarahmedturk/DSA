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
        string s;
        cin>>s;
        vector<vector<int>> arr(n,vector<int>(26,0));
        arr[0][s[0]-'a']=1;
        for(int i=1;i<n;i++){
            arr[i]=arr[i-1];
            arr[i][s[i]-'a']++;
        }
        int res=0;
        for(int i=0;i<n-1;i++){
            int count1=0,count2=0;
            for(int j=0;j<26;j++){
                if(arr[i][j]!=0) count1++;
                if(arr[n-1][j]!=arr[i][j]) count2++;
            }
            res=max(res,count1+count2);
        }
        cout<<res<<endl;
    }
    return 0;
}