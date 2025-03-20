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
    cin >> t;
    while (t--){
        long long n, k;
        cin >> n >> k;
        vector<long long> a(n,k);
        for(int i=2;i<n;i++){
            int prv=a[0];
            for(int j=1;j<i;j++){
                if(prv==a[j]){
                    a[j]=0;
                }
                else{
                    prv=a[j];
                    a[j]=k;
                }
            }
        }
        for(int i=0;i<n;i++) cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}