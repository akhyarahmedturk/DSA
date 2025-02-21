#include<bits/stdc++.h>
using namespace std;
int all=0,k,n;

vector<int> a( n , 0 ) ;
vector<pair<vector<int>,vector<int>>> grid(k); 

void solve(vector<int> &arr,int idx,int mini){
    // cout<<"idx "<<idx<<" min "<<mini<<endl;
    if(idx==k){
        all=max(all, *min_element( a.begin(), a.end() ) ) ;
        // cout << all << endl ;
        return ;
    }
    else{
        for( int i = 0 ; i < grid[idx].first.size() ; i++ ) {
            a[ grid[idx].first[i] ]++ ;
        }
        solve( arr, idx + 1 , mini ) ;
        for( int i = 0 ; i < grid[idx].first.size() ; i++ ) {
            a[ grid[idx].first[i] ]-- ;
        }

        for( int i = 0 ; i < grid[idx].second.size() ; i++ ) {
            a[ grid[idx].second[i] ]++ ;
        }
        solve( arr, idx + 1 , mini ) ;
        for( int i = 0 ; i < grid[idx].second.size() ; i++ ) {
            a[ grid[idx].second[i] ]-- ;
        }
    }
}

int main() {
    cin >> n >> k ;
    grid.resize( k ) ;
    a.resize( n ) ;
    vector<int> arr( k , 0 ) ;
    for( int i = 0 ; i < n ; i++ ) {
        for( int j = 0 ; j < k ; j++ ) {
            char ch ;
            cin >> ch ;
            if( ch == 'T' ){
                grid[j].first.push_back(i) ;
            }
            else {
                grid[j].second.push_back( i ) ;
            }
        }
    }
    
    vector<int> vec(n,0);
    int mini=100000;
    solve(arr,0,mini);
    
    cout << all << '\n' ;
    return 0 ;
}