//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
           //Your code here
           int n=arr.size();
       map<int,int> m;
       multimap<int,int> nm;
       vector<int> ans;
       
       
       for(int i=0;i<n;i++){
           m[arr[i]]++;
       }
       
       for(auto it=m.rbegin();it!=m.rend();it++){
           nm.insert({it->second,it->first});
       }
       
       for(auto it=nm.rbegin();it!=nm.rend();it++){
           
           for(int j=0;j<it->first;j++){
               ans.push_back(it->second);
           }
           
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

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends