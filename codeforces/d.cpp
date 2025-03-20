#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

int main(){
    // unordered_set<int> st;
    // st.insert(2);
    // st.insert(3);
    // st.insert(1);
    // for(auto it: st){
    //     cout<<it<<" ";
    // }
    // cour<<arr[4]
    // map<int,int> mp;
    // {2,7,2,5,3,1}  target=7 res=0;
    // i=0 {{2,1}}
    // i=1 {{2,1},{7,1}}
    // i=2 {{2,2},{7,1}}
    // res+=mp[2];
    string str = "abcbcaa";
    map<char, int> mp;
    for (char ch : str){
        mp[ch]++;
    }
    for (auto it : mp){
        cout << it.first << endl;
    }
    return 0;
}