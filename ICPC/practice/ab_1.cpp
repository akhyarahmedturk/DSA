#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int main(){
    int T;
    string s1, s2, s3;
    cin >> T;
    while (T--){
        cin >> s1 >> s2 >> s3;
        if (s1.length() != s2.length()){
            cout << "NO" << endl;
            continue;
        }
        if (s1.length() == s2.length() && s1.length() != s3.length()){
            cout << "YES" << endl;
            continue;
        }
        unordered_map<char, unordered_set<char>> graph;
        for (int i = 0;i < s1.length();i++){
            graph[s1[i]].insert(s2[i]);
            graph[s2[i]].insert(s1[i]);
        }
        bool flag = false;
        for (int i = 0;i < s1.length();i++){
            if (graph.find(s3[i]) == graph.end()){
                flag=true;
                break;
            }
            if (graph[s3[i]].find(s1[i]) == graph[s3[i]].end() && graph[s3[i]].find(s2[i]) == graph[s3[i]].end()){
                flag = true;
                break;
            }
        }
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}