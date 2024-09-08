//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // Your code here
        int n=arr.size();
         int count=0;int i=0;
    while(i<n-1){
        if(arr[i]==0)return -1;
     if(arr[i]==1){
         count++;i++;
         continue;
     } 
     if(arr[i]>=n-1-i){
         return ++count;
     }
     int index=i;int res=INT_MIN;
     
     for(int j=i+1;j<=i+arr[i];j++){
        if((arr[j]-(arr[i]-j+i))>res){
            res=arr[j]-(arr[i]-j+i);
            index=j;
        }
         
     }
     if(res==INT_MIN)return -1;
       i=index;
       count++;
    }
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends