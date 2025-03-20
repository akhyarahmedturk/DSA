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
        string str;
        cin>>str;
        int n=str.length();
        vector<int> arr(n),zeros,ones;
        for(int i=0;i<n;i++){
            if(str[i]=='1'){
                arr[i]=1;
                ones.push_back(i);
            }
            else{
                arr[i]=0;
                zeros.push_back(i);
            }
        }
        int x=0,y=0,res=0;
        while(x<zeros.size() && y<ones.size()){
            if(arr[res]==2){
                res++;
                continue;
            }
            if(arr[res]==1) arr[zeros[x]]=2;
            else arr[ones[y]]=2;
            res++;
            x++;
            y++;
        }
        while(res<n && arr[res]==2) res++;
        cout<<n-res<<endl;
    }
    return 0;
}