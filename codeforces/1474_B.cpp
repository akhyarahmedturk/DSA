#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

bool isPrime(int n) {
    if(n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if(n % i == 0)
            return false;
    return true;
}
 
int main(){ // Not my code...
    int t;
    cin >> t;
    while(t--){
        int d;
        cin >> d;
        int p = d + 1;
        while(!isPrime(p)) p++;
        int q = p + d;
        while(!isPrime(q)) q++;
        cout << (long long)p * q << "\n";
    }
    return 0;
}