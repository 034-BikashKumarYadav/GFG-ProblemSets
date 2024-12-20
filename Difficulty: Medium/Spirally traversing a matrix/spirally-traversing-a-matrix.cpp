//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   vector<int> spirallyTraverse(vector<vector<int> > &v) {
        vector<int> ans; 
        int i1 = 0; 
        int i2 = v.size()-1; 
        int j1 = 0;
        int j2 = v[0].size()-1;
    
        
        while(i1<=i2 && j1<=j2){
            for(int p = j1;p <= j2;p++){
                ans.push_back(v[i1][p]) ;
            }
            i1++; 
            for(int q = i1;q <= i2;q++){
                ans.push_back(v[q][j2]); 
            }
            j2--; 
            if(i1<=i2){
                for(int r = j2;r >= j1;r--){
                ans.push_back(v[i2][r]);
                }
                i2--;
            }
            
            if(j1<=j2){
                for(int s = i2;s >= i1;s--){
                    ans.push_back(v[s][j1]); 
                }
                j1++; 
            }
        }  
        
        return ans; 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends