#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 10000; // fits in 256 KB limit
    int k = 1;
    int val = 1e9-10;

    cout << n << " " << k << "\n";
    for (int i = 0; i < n; i++) {
        cout << val << (i + 1 == n ? '\n' : ' ');
    }
    for (int i = 0; i < n; i++) {
        cout << val << (i + 1 == n ? '\n' : ' ');
    }
    return 0;
}