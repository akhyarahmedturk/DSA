#include <iostream>
#include<vector>
using namespace std;


bool backtrack(long long bef , long long aft , long long cur , vector<long long> &arr){
    if(cur == aft){   
        arr.push_back(cur);
        return true;
    }
    if(cur > aft){
        return false;
    }
    arr.push_back(cur);
    if(backtrack(bef , aft, cur*2, arr )) return true;
    if(backtrack(bef,aft,(cur*10)+1,arr)) return true;
    arr.pop_back();
    return false;
}


int main(){
    long long bef  = 0 ;  long long  aft = 0;
    cin >> bef >> aft;
    // bool found = false;
    // bool *p = &found;
    vector<long long> arr;
    if(!backtrack( bef, aft, bef , arr)){ cout<<"NO"<<endl;}
    else {        
        cout << "YES" <<endl;
        cout << arr.size() << endl;
        for(auto i : arr){
            cout << i << " ";
        }
        // *found = true;
    }
  return 0;
}