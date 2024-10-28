#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long t, n, k, min, sum, current;
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> n;
        cin >> k;
        min = 100000000000000;
        for (int j = 0; j < n; j++){
            cin >> current;
            if (current < min)
                min = current;
        }
        sum = (2 * n - 3) * min;
        if (n == 1){
            if (min <= k)
                cout << "Case #" << i + 1 << ": YES" << endl;
            else
                cout << "Case #" << i + 1 << ": NO" << endl;
        }
        else if (k >= sum){
            cout << "Case #" << i + 1 << ": YES" << endl;
        }
        else{
            cout << "Case #" << i + 1 << ": NO" << endl;
        }
    }
}