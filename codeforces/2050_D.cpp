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
        string str;
        cin >> str;
        int n = str.length();
        for (int i = 0;i < n-1;i++){
            int max_idx = i;
            int upper = 9 - (str[i] - '0') - 1;
            // cout << upper << endl;
            for (int j = 1;j <= upper && i + j < n;j++){
                if (str[i + j]-str[max_idx]-(i+j-max_idx)>0) max_idx = i + j;
            }
            int temp = str[max_idx];
            for(int j=max_idx;j > i;j--) str[j] = str[j - 1];
            str[i] = temp-(max_idx-i);
            // cout<<str<<endl;
        }
        cout << str << endl;
    }
    return 0;
}