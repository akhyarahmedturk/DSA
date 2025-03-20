#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;
using p=pair<long long, int>;
using pp=pair<pair<long long, long long>, bool>;

long long dijkstra(int src,int dst,unordered_map<int,p> &main_cities,unordered_map<int,p> &cities) { // not solved yet
    int n=cities.size();
    vector<long long> dist(n,LLONG_MAX);
    priority_queue<p,vector<p>, greater<p>> pq;
    pq.push({0LL,src});
    dist[src]=0LL;
    while(pq.size()){
        long long d=pq.top().first;
        int vertex=pq.top().second;
        cout<<" vertex "<<vertex<<" d "<<d<<endl;
        bool is_main=false;
        long long x,y;
        if(main_cities.find(vertex)!=main_cities.end()){
            is_main=true;
            x=main_cities[vertex].first; 
            y=main_cities[vertex].second;
            main_cities.erase(vertex);
        }
        else{
            x=cities[vertex].first; 
            y=cities[vertex].second;
            cities.erase(vertex);
        }
        cout<<"is_main: "<<is_main<<endl;
        pq.pop();
        if(d>dist[vertex]) continue;
        if(is_main){
            for(auto it:main_cities){
                if(d<dist[it.first]){
                    dist[it.first]=d;
                    pq.push({d,it.first});
                }
            }
        }
        else{
            for(auto it:main_cities){
                long long cost=d + abs(it.second.first-x) + abs(it.second.second-y);
                if(d<dist[it.first]){
                    dist[it.first]=d;
                    pq.push({d,it.first});
                }
            }
        }
        for(auto it:cities){
            long long cost=d + abs(it.second.first-x) + abs(it.second.second-y);
            if(d<dist[it.first]){
                dist[it.first]=d;
                pq.push({d,it.first});
            }
        }
    }
    return dist[dst];
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,k,a,b;
        cin>>n>>k>>a>>b;
        unordered_map<int,p> main_cities,cities;
        for(long long i=0;i<k;i++){
            long long x,y;
            cin>>x>>y;
            main_cities[i]={x,y};
        }
        for(long long i=k;i<n;i++){
            long long x,y;
            cin>>x>>y;
            cities[i]={x,y};
        }
        cout<<dijkstra(a-1,b-1,main_cities,cities)<<endl;
    }
    return 0;
}