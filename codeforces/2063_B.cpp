#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int main(){
    long long t;
    cin >> t;
    while (t--){
        long long n, start, end, sum = 0;
        cin >> n >> start >> end;
        start--;
        end--;
        vector<long long> first(start), second(end - start + 1), third(n - end - 1);
        for (long long i = 0;i < start;i++) cin >> first[i];
        for (long long i = 0;i < end - start + 1;i++){
            cin >> second[i];
            sum += second[i];
        }
        for (long long i = 0;i < n - end - 1;i++) cin >> third[i];
        sort(first.begin(), first.end());
        sort(second.rbegin(), second.rend());
        sort(third.begin(), third.end());
        long long temp1 = sum, temp2 = sum;
        for (long long i = 0;i < first.size() && i < second.size() && first[i] < second[i];i++) temp1 += (first[i] - second[i]);
        for (long long i = 0;i < third.size() && i < second.size() && third[i] < second[i];i++) temp2 += (third[i] - second[i]);
        cout << min(temp1, temp2) << endl;
    }
    return 0;
}