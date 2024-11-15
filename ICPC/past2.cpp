// #include<iostream>
// #include<vector>
// #include<stack>
// #include<queue>
// #include<unordered_map>
// #include<unordered_set>
// #include<algorithm>
// using namespace std;

// int DFS(vector<vector<int>>& graph, vector<int>& visited, int vertex){
//     int Max = 0;
//     visited[vertex] = false;
//     for (int i = 0;i < graph[vertex].size();i++){
//         if (!visited[graph[vertex][i]])
//             Max = max(Max, DFS(graph, visited, graph[vertex][i]));
//     }
//     return Max + 1;
// }

// int main(){// test cases not passed
//     int cases, n;
//     cin >> cases;
//     vector<int> res(cases, INT_MAX);
//     for (int i = 0;i < cases;i++){
//         cin >> n;
//         vector<vector<int>> graph(n);
//         for (int j = 0;j < n - 1;j++){
//             int x, y;
//             cin >> x >> y;
//             graph[x].push_back(y);
//             graph[y].push_back(x);
//         }
//         for (int j = 0;j < n;j++){
//             vector<int> visited(n);
//             res[i] = min(res[i], DFS(graph, visited, j));
//         }
//     }
//     for (int i = 0;i < res.size();i++){
//         cout << res[i] << endl;
//     }
//     return 0;
// }