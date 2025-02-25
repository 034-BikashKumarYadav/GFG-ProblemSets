//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // Your code here
        int n=arr.size();
          vector<long long>l(n),r(n);
        stack<int>st;
        //Find left closest smaller element
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
            st.pop();
            
            if(st.empty())
             l[i]=-1;
             else
              l[i]=st.top();
              
              st.push(i);
        }
       
       
       while(!st.empty())
       st.pop();
      //Find right closest smallest element
       for(int i=n-1;i>=0;i--)
       {
           while(!st.empty() && arr[st.top()]>=arr[i])
           st.pop();
           
           if(st.empty())
            r[i]=n;
            else
             r[i]=st.top();
             
             st.push(i);
       }
       long long res=0;
       for(int i=0;i<n;i++)
       {
           res=max(res,arr[i]*(r[i]-l[i]-1));
       }
       return res;
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
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends