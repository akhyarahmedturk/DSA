#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<set>
#include<algorithm>
using namespace std;

int main(){
    int T, size, Max = 0, check;
    cin >> T;
    while (T--){
        cin >> size;
        vector<int> vec(size);
        set<int> inc;
        for (int i = 0;i < size;i++){
            cin >> vec[i];
            Max = max(Max, vec[i]);
        }
        for (int i = 1;i < size;i++){
            inc.insert(vec[i-1] - vec[i ]);
        }
        if (size == 1 || inc.size() == 1) cout << 0 << endl;
        else if (inc.size() == 2){
            if (*inc.begin() < 0 && *inc.rbegin() > 0 && *inc.rbegin() - *inc.begin() > Max) cout << *inc.rbegin() - *inc.begin() << " " << -(*inc.begin()) << endl;
            else cout << -1 << endl;
        }
        else cout << -1 << endl;
    }
    return 0;
}