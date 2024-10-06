//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    vector<vector<int>> dirs = { {-1, 0}, {1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<int>>& vis) {
    vis[i][j] = true;
    for(auto dir: dirs) {
        int x = i + dir[0];
        int y = j + dir[1];
        
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || vis[x][y] || grid[x][y] == '0')
            continue;
            
        dfs(grid, x, y, vis);
    }
}
int numIslands(vector<vector<char>>& grid) {
    int ans = 0;
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> vis(n, vector<int> (m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == '1' && vis[i][j] == false) {
                ans++;
                dfs(grid, i, j, vis);
            }
        }
    }
    return ans;
}
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends