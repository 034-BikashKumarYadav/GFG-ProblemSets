//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool checkSorted(vector<int> &arr) {
        // code here.
        int count=0;
for(int i=0;i<arr.size();i++){
    if(i+1!=arr[i]){
        if(arr[arr[i]-1]!=i+1){
            return false;
        }
        else{
            count++;
            swap(arr[arr[i]-1], arr[i]);
        }
    }
}
return count==0 || count==2 ? true : false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        bool ans = ob.checkSorted(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}

// } Driver Code Ends