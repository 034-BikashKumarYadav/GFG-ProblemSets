//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *right, *down;

    Node(int x) {
        data = x;
        right = NULL;
        down = NULL;
    }
};


// } Driver Code Ends
/*structure of the node of the linked list is as

struct Node
{
    int data;
    Node* right, *down;

    Node(int x){
        data = x;
        right = NULL;
        down = NULL;
    }
};
*/

// function must return the pointer to the first element of the in linked list i.e. that
// should be the element at arr[0][0]
class Solution {
  public:
      Node* constructLinkedMatrix(vector<vector<int>>& mat) {

    int n = mat.size();
    int m = mat[0].size();
    vector<vector<Node*>> dp(n, vector<Node*>(m, NULL));
    

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (dp[i][j] == NULL) {
                dp[i][j] = new Node(mat[i][j]);
            }

  
            if (i + 1 < n) {
                if (dp[i + 1][j] == NULL) {
                    dp[i + 1][j] = new Node(mat[i + 1][j]);
                }
                dp[i][j]->down = dp[i + 1][j];
            }

           
            if (j + 1 < m) {
                if (dp[i][j + 1] == NULL) {
                    dp[i][j + 1] = new Node(mat[i][j + 1]);
                }
                dp[i][j]->right = dp[i][j + 1];
            }
        }
    }

    // Return the head of the linked matrix (top-left node)
    return dp[0][0];}
};

//{ Driver Code Starts.

void display(Node* head) {
    Node* Rp;
    Node* Dp = head;
    while (Dp) {
        Rp = Dp;
        while (Rp) {
            cout << Rp->data << " ";
            if (Rp->right)
                cout << Rp->right->data << " ";
            else
                cout << "null ";
            if (Rp->down)
                cout << Rp->down->data << " ";
            else
                cout << "null ";
            Rp = Rp->right;
        }
        Dp = Dp->down;
    }
}

// Driver program
int main() {
    int t;
    cin >> t;
    cin.ignore(); // To handle new line after integer input

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;

        // Read the first row of the matrix
        while (ss >> num) {
            nums.push_back(num);
        }

        int n = nums.size();
        vector<vector<int>> mat(n, vector<int>(n));
        mat[0] = nums;

        // Read the remaining rows of the matrix
        for (int i = 1; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);
            vector<int> nums;
            int num;

            // Read the first row of the matrix
            while (ss >> num) {
                nums.push_back(num);
            }

            mat[i] = nums;
        }

        Solution ob;
        Node* head = ob.constructLinkedMatrix(mat);
        if (!head) {
            cout << "-1\n";
        } else {
            display(head);
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends