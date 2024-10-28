#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

int main(){
    double t, num, n, ans, carry, goal, result, diff;
    int dhakka;
    pair<int, int> prv;
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> n;
        cin >> goal;
        diff = INT_MAX;
        stack<pair<int, int>> st;
        st.push({ INT_MAX, 0 });
        dhakka = 0;
        for (int i = 0; i < n; i++){
            cin >> num;
            if (num >= st.top().first){
                st.push({ st.top().first, num - st.top().first });
            }
            else{
                st.push({ num, 0 });
            }
        }
        prv = st.top();
        st.pop();
        st.top().second += prv.second;
        prv.second = 0;
        for (int i = 0; i < n; i++){
            if (prv.first > st.top().first){
                cout << " prv.first b1 " << prv.first << " st.top " << st.top().first;
                st.top().second += prv.second;
                st.top().second -= (prv.first - st.top().first + 1);
                st.top().first = prv.first + 1;
            }
            else if (prv.first == st.top().first){
                cout << " prv.first b2 " << prv.first << " st.top " << st.top().first;
                if (prv.second != 0){
                    prv.first += 1;
                    st.top().second += prv.second - 1;
                    if (st.top().second >= 2){
                        st.top().second -= 2;
                        st.top().first += 2;
                    }
                }
                //cout << " prv.first a " << prv.first;
            }
            else if (prv.first + prv.second >= st.top().first){
                cout << " prv.first b3 " << prv.first << " st.top " << st.top().first;
                //cout << " diff " << (prv.second + dhakka - (st.top().first - prv.first));
                prv.first += (prv.second - (st.top().first - prv.first));
                st.top().second += prv.second - (st.top().first - prv.first);
                prv.first = st.top().first;
            }
            else{
                cout << " prv.first b4 " << prv.first << " st.top " << st.top().first;
                prv.first += prv.second;
            }
            if (abs(prv.first - goal) <= diff){
                diff = abs(prv.first - goal);
                result = n - i;
            }
            cout << " prv.first a " << prv.first << " st.top " << st.top().second << endl;
            //cout << " i " << i << " prv " << prv.first << endl;
            if (prv.first < st.top().first){
                prv = st.top();
                st.top().second += prv.second;
                prv.second = 0;
            }
            else{
                prv = st.top();
                st.top().second += prv.second;
            }
        }
        cout << "Case #" << i + 1 << ": " << result << " " << diff << endl;
    }
}