#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int josephus(int n, int N){
    if (n == 1)
        return 1;
    else
        // The position returned by josephus(n - 1, k)
        // is adjusted because the recursive call
        // josephus(n - 1, k) considers the
        // original position k % n + 1 as position 1
        return (josephus(n - 1, N) + (N - n + 1) - 1) % n + 1;
}

int main(){
    int T, n;
    cin >> T;
    while (T){
        cin >> n;
        cout << josephus(n, n) << endl;
        T--;
    }
    return 0;
}