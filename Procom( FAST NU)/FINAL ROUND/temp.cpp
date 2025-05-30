// #include<iostream>
// #include<vector>
// #include<unordered_map>
// #include<unordered_set>
// #include<map>
// #include<set>
// #include<cstring>
// #include<cmath>
// #include<climits>
// #include<algorithm>
// #include<iomanip>
// #include<queue>
// #include<stack>
#include<bits/stdc++.h>
using namespace std;

using pp = pair<int, int>;

vector<int> Dijk( vector<vector<pp>>& adj , int src ) {
    int n = adj.size();
    vector<int> dist( n + 1 , INT_MAX ) ;
    dist[src] = 0;
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    pq.push( {0, src} ) ;
    while( !pq.empty() ) {
        int node = pq.top().second , w = pq.top().first ;
        pq.pop() ;
        
        if( w > dist[node] )
            continue;

        for( auto& [v, wt] : adj[node] ) {
            if( dist[node] + wt < dist[v] ) {
                dist[v] = dist[node] + wt ;
                pq.push( { dist[v], v } ) ;
            }
        }
    }
    return dist;
}

pp BFS( vector<vector<int>>& adj , int src ) {
    int n = adj.size();
    vector<bool> visited( n + 1 , false ) ;
    visited[src] = true ;

    int farthest = src , dia = -1 ;
    queue<int> q ;
    q.push( src ) ;
    while( !q.empty() ) {
        int size = q.size() ;
        while( size-- ) {
            int node = q.front() ;
            q.pop() ;

            for( int& ngbr : adj[node] ) {
                if( !visited[ngbr] ) {
                    visited[ngbr] = true ;
                    q.push( ngbr ) ;
                    farthest = node ;
                }
            }
        }
        dia++ ;
    }

    return {farthest, dia} ;
}

vector<int> primeNums( int n ) {
    vector<bool> isPrime( n + 1 , true ) ;
    isPrime[0] = isPrime[1] = false;
    for( int i = 2 ; i * i <= n ; i++ ) {
        if( isPrime[i] ) {
            for( int j = i * i ; j <= n ; j += i )
                isPrime[j] = false ;
        }
    }

    vector<int> primes;
    for( int i = 2 ; i <= n ; i++ )
        if( isPrime[i] ) {
            cout << i << " " ;
            primes.push_back( i ) ;
        }
        
    return primes ;
}

vector<int> bellman_ford( int V, vector<vector<int>>& edges, int src ) {
    vector<int> dist( V + 1, 1e8 ) ;
    dist[src] = 0 ;
    for (int i = 0; i < V - 1; i++) {
        for ( vector<int>& it : edges ) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if ( dist[u] != 1e8 && dist[u] + wt < dist[v] )
                dist[v] = dist[u] + wt;
        }
    }

    for ( vector<int>& it : edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if ( dist[u] != 1e8 && dist[u] + wt < dist[v] )
            return { -1 } ;
    }
    return dist;
}