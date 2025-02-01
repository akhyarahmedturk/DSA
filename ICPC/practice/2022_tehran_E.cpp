#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;
int m, n;
int DFS(vector<vector<char>>& grid, int i, int j){
    if (i == -1 || j == -1 || i == m || j == n || grid[i][j] == 'o') return 0;
    grid[i][j] = 'o';
    int res = 1;
    res += DFS(grid, i - 1, j);
    res += DFS(grid, i, j - 1);
    res += DFS(grid, i, j + 1);
    res += DFS(grid, i + 1, j);
    return res;
}

int main(){
    int res = 0;
    cin >> m >> n;
    vector<vector<char>> grid(m, vector<char>(n));
    for (int i = 0;i < m;i++){
        for (int j = 0;j < n;j++){
            cin >> grid[i][j];
        }
    }
    for (int i = 0;i < m;i++){
        res += DFS(grid, 0, i);
        res += DFS(grid, m - 1, i);
    }
    for (int i = 0;i < n;i++){
        res += DFS(grid, i, 0);
        res += DFS(grid, i, n - 1);
    }
    cout << res;
    return 0;
}