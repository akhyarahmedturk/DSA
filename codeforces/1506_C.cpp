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
        string a,b;
        cin>>a>>b;
        if(b.length()>a.length()) swap(a,b);
        int ans=0;
        bool check=false;
        for(int i=b.length();i>=1;i--){
            for(int j=0;j<=b.length()-i;j++){
                for(int k=0;k<=a.length()-i;k++){
                    // cout<<" i "<<i<<"j "<<j<<" k "<<k<<endl;
                    if(b.substr(j,i)==a.substr(k,i)){
                        check=true;
                        ans=i;
                        break;
                    }
                }
                if(check) break;
            }
            if(check) break;
        }
        cout<<(a.length()+b.length() -ans*2)<<endl;
    }
    return 0;
}