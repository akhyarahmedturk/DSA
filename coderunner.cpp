#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int main(){
    string s;
    cin >> s;
    int count = 0;
    for (int i = 0;i < s.length();i++){
        if (s[i] == ')'){
            if (count > 0) count--;
            else{
                cout << "Invalid string" << endl;
                exit(1);
            }
        }
        else count++;
    }
    if (count == 0) cout << "Valid string" << endl;
    else cout << "Invalid string" << endl;
    return 0;
}