//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        // Your code here
            priority_queue <int, vector<int>, greater<int> > pq; 
            
            for(auto i:arr){
                if(pq.size()==k and pq.top() < i){
                    pq.pop();
                } 
                if(pq.size() < k){
                    pq.push(i);
                }
                
            }
            
            vector<int>ans;
            
            while(!pq.empty()){
                ans.push_back(pq.top());
                pq.pop();
            }
            
            reverse(ans.begin(),ans.end());
            
            return ans;
            
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.kLargest(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends