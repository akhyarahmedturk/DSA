#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int main(){
    int T,n,sum,temp;
    cin>>T;
    vector<int> res(T,0);
    for(int i=0;i<T;i++){
        cin>>n;
        sum=0;
        unordered_set<int> st;
        for(int j=0;j<n;j++){
            cin>>temp;
            if(st.find(temp)!=st.end()){
                st.erase(temp);
                sum++;
            }
            else st.insert(temp);
        }
        res[i]=sum;
    }
    for(int i=0;i<T;i++){
        cout<<res[i]<<endl;
    }
    return 0;
}