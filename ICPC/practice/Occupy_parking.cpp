#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int main(){
    int N, res = 0;
    cin >> N;
    string A, B;
    cin >> A >> B;
    for (int i = 0;i < A.length();i++){
        if (A[i] == 'C' && B[i] == 'C') res++;
    }
    cout << res;
    return 0;
}