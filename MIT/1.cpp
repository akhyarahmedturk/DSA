#//include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, len;
    cin >> n;
    string s;
    while (n--){
        cin >> len;
        cin >> s;
        if (s[0] != 'M'){
            cout << "NO" << endl;
            continue;
        }
        int i = 1;
        bool check = true;
        while (i < len){
            if (s[i - 1] == 'M'){
                if (s[i] != 'I'){
                    check = false;
                    break;
                }
            }
            else if (s[i - 1] == 'I'){
                if (s[i] != 'T'){
                    check = false;
                    break;
                }
            }
            else if (s[i - 1] == 'T'){
                if (s[i] != 'I' || s[i] != 'M'){
                    check = false;
                    break;
                }
            }
            else{
                check = false;
                break;
            }
            i++;
        }
        if (check && s.back() == 'T') cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}