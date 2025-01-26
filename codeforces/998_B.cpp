#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>

using namespace std;

int main(){
    int T, k, n, m;
    int temp;
    cin >> T;
    vector<pair<int, int>> res(T);
    for (int i = 0;i < T;i++){
        cin >> k;
        unordered_set<int> st;
        for (int j = 0;j < k;j++){
            cin >> temp;
            if (temp != 0 && (k - 2) % temp == 0 && st.find((k - 2) / temp) != st.end()){
                res[i] = { (k - 2) / temp,temp };
            }
            else st.insert(temp);
        }
    }
    for (int i = 0;i < T;i++){
        cout << res[i].first << " " << res[i].second << endl;
    }
    return 0;
}