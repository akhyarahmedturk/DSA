#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;


// Steps:
// 1) first select the starting vertex
// 2) relax it,s neighbours (except previously selected ones) if we can!
// 3) now, pick the neighbour with min/max value and apply dijkstra on it.
// 4) repeat these steps until you dont have any option left.
class Solution{
public:
    double dijkstra_BFS(int start, int end, vector<vector<pair<int, double>>>& graph){
        vector<bool> visited(graph.size(), false);
        vector<double> max_prob(graph.size(), 0);// store current max prob for each node

        max_prob[start] = 1.00;
        priority_queue<pair<double, int>> pq;
        pq.push({ 1.0, start });

        while (!pq.empty()){
            pair<double, int> top = pq.top();
            pq.pop();
            if (!visited[top.second]){
                // cout<<"top "<<top.second<<" prob "<<top.first<<endl;
                visited[top.second] = true;
                for (auto& it : graph[top.second]){
                    if (max_prob[it.first] < top.first * it.second){
                        max_prob[it.first] = top.first * it.second;
                        pq.push({ max_prob[it.first],it.first });
                    }
                }
            }
        }
        return max_prob[end];
    }
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node){
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0;i < edges.size();i++){
            graph[edges[i][0]].push_back({ edges[i][1],succProb[i] });
            graph[edges[i][1]].push_back({ edges[i][0],succProb[i] });
        }
        return dijkstra_BFS(start_node, end_node, graph);
    }
};

int main(){

    return 0;
}