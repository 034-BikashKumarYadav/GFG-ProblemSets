//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    bool checker(int t, int r, int c, vector<vector<int>>& mat, int n) {
        // Check current row
        for (int j = 0; j < n; j++) {
            if (mat[r][j] == t) return false;
        }
        // Check current column
        for (int i = 0; i < n; i++) {
            if (mat[i][c] == t) return false;
        }
        // Check in 3x3 subgrid
        int temp1 = r - (r % 3);
        int temp2 = c - (c % 3);
        for (int i = temp1; i < temp1 + 3; i++) {
            for (int j = temp2; j < temp2 + 3; j++) {
                if (mat[i][j] == t) return false;
            }
        }
        return true;
    }

    bool helper(int row, int col, vector<vector<int>>& mat, int n) {
        if (row == n) return true; // If we reach row beyond the last, solution is found
        if (col == n) return helper(row + 1, 0, mat, n); // Move to the next row
        if (mat[row][col] != 0) return helper(row, col + 1, mat, n); // Skip filled cells

        for (int k = 1; k <= 9; k++) {
            if (checker(k, row, col, mat, n)) {
                mat[row][col] = k;
                if (helper(row, col + 1, mat, n)) return true; // Recurse to the next cell
                mat[row][col] = 0; // Backtrack if the solution doesn't work
            }
        }
        return false; // If no number fits, return false
    }

    void solveSudoku(vector<vector<int>>& mat) {
        helper(0, 0, mat, mat.size());
    }
};


//{ Driver Code Starts.

vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<vector<int>> grid;
        for (int i = 0; i < 9; i++) {
            vector<int> v = inputLine();
            grid.push_back(v);
        }

        Solution ob;

        ob.solveSudoku(grid);

        for (auto v : grid) {
            for (auto elem : v) {
                cout << elem << " ";
            }
            cout << endl;
        }

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends