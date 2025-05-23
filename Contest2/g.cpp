/*
g++ -Wall -Werror -std=c++17 -o bin/out g.cpp && ./bin/out
*/

// CodeForces - 1829E 

#include <iostream>
#include <vector>
#include <algorithm>

#define lli long long int
#define ulli unsigned long long int
#define endl "\n"

using namespace std;

int dfs(vector<vector<int>>& grid, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
        return 0;
    }
    int count = grid[i][j];
    grid[i][j] = 0;
    count += dfs(grid, i + 1, j);
    count += dfs(grid, i - 1, j);
    count += dfs(grid, i, j + 1);
    count += dfs(grid, i, j - 1);
    return count;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; // num of test cases
    cin >> t;
    while (t--){
        int n, m; // number of rows and columns of the grid, respectively.
        cin >> n >> m;

        /*
        * Then n lines follow, each containing m integers a[i][j] (0 ≤ a[i][j] ≤ 1000)
        * representing the depth of the water at each cell
        */

        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        int max_depth = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                max_depth = max(max_depth, dfs(grid, i, j));
            }
        }

        // cout << "------> ";
        cout << max_depth << endl;
    }
}