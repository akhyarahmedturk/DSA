#include <iostream>
#include <conio.h>
#include <vector>
#include <stack>

using namespace std;

void solve(vector<vector<pair<int, int>>> &res, vector<vector<int>> &maze, int x, int y, vector<pair<int, int>> &current)
{
	if (x == maze.size() - 1 && y == maze[0].size() - 1)
	{
		res.push_back(current);
	}
	else
	{
		if (x - 1 != -1 && maze[x - 1][y] == 0)
		{
			maze[x][y] = 1;
			current.push_back({x - 1, y});
			solve(res, maze, x - 1, y, current);
			current.pop_back();
			maze[x][y] = 0;
		}
		if (y - 1 != -1 && maze[x][y - 1] == 0)
		{
			maze[x][y] = 1;
			current.push_back({x, y - 1});
			solve(res, maze, x, y - 1, current);
			current.pop_back();
			maze[x][y] = -0;
		}
		if (x + 1 != maze.size() && maze[x + 1][y] == 0)
		{
			maze[x][y] = 1;
			current.push_back({x + 1, y});
			solve(res, maze, x + 1, y, current);
			current.pop_back();
			maze[x][y] = 0;
		}
		if (y + 1 != maze[0].size() && maze[x][y + 1] == 0)
		{
			maze[x][y] = 1;
			current.push_back({x, y + 1});
			solve(res, maze, x, y + 1, current);
			current.pop_back();
			maze[x][y] = 0;
		}
	}
}

int main()
{
	vector<vector<int>> maze{{0, 0, 0, 1},
							 {0, 0, 0, 1},
							 {0, 1, 0, 1},
							 {0, 1, 0, 0}};
	vector<vector<pair<int, int>>> res;
	vector<pair<int, int>> current = {{0, 0}};
	solve(res, maze, 0, 0, current);
	for (int i = 0; i < res.size(); i++)
	{
		cout << endl
			 << "Soulution " << i + 1 << endl;
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << "{" << res[i][j].first << "," << res[i][j].second << "}->";
		}
	}
	return 0;
}
