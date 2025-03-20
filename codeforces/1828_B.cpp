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
        int n;
        cin >> n;
        int temp;
        vector<int> diff;
        for (int i = 1;i <= n;i++){
            cin >> temp;
            if (temp != i) diff.push_back(abs(temp - i));
        }
        sort(diff.begin(), diff.end());
        int res = 1;
        if (!diff.empty() || diff[0] != 1){
            res = diff[0];
            while (res > 1){
                bool check = true;
                for (int i = 0;i < diff.size();i++){
                    if (diff[i] % res != 0){
                        check = false;
                        break;
                    }
                }
                if (check) break;
                res--;
            }
        }
        cout << res << endl;
    }
    return 0;
}