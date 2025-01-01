//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
              int n=arr.size();
        vector<vector<string>>ans; 
        for(int i=0;i<n;i++)
        {
            int flag=0;
            for(int j=0;j<ans.size();j++)
            {
                string tp1=ans[j][0];
                string tp2=arr[i];
                sort(tp1.begin(),tp1.end());
                sort(tp2.begin(),tp2.end());
                
                if(tp1==tp2)
                {
                 ans[j].push_back(arr[i]);
                 flag=1;
                 break; 
                }
            }
            if(flag!=1)
            ans.push_back({arr[i]});
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<string> arr;
        string input_line;
        getline(cin, input_line);
        stringstream ss(input_line);
        string word;
        while (ss >> word) {
            arr.push_back(word);
        }

        Solution ob;
        vector<vector<string> > result = ob.anagrams(arr);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends