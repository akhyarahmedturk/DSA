
#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n,k; cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int res=0;
    priority_queue<int,vector<int>,greater<int>> min_h;
    priority_queue<int> max_h;
    for(int i=0;i<n;i++){
        if(i>=k){
            if(k%2==0){
                int first=max_h.top();
                int second=0;
                if(max_h.size()>min_h.size()){
                    max_h.pop();
                    second=max_h.top();
                    max_h.push(first);
                }
                else second=min_h.top();
                if(arr[i]>=first+second) res++;
                cout<<first+second<<endl;
            }
            else{
                int first=max_h.top();
                if(arr[i]>=first*2) res++;
                cout<<first<<endl;
            }
        }
        max_h.push(arr[i]);
        if(min_h.size() && max_h.top()>min_h.top()){
            min_h.push(max_h.top());
            max_h.pop();
        }
        if(max_h.size()-1>min_h.size()){
            min_h.push(max_h.top());
            max_h.pop();
        }
        if(min_h.size()>max_h.size()){
            max_h.push(min_h.top());
            min_h.pop();
        }
        // if(max_h.size() && min_h.size()) cout<<min_h.top()<<" "<<max_h.top()<<endl;
        // else if(max_h.size()) cout<<" nil"<<" "<<max_h.top()<<endl;
        // else if(min_h.size()) cout<<min_h.top()<<" nil"<<endl;
    }
    cout<<res<<endl;
}

int main(){
    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}