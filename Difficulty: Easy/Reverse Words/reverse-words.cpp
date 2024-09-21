//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
      stack<string> st;
       string ans = "";
       string temp = "";

    for (int i = 0; i < S.length(); i++) {
        if (S[i] != '.') {
            temp += S[i];
        } else {
            st.push('.'+temp);
            temp = "";
        }
    }

    st.push(temp); // Push the last word

    while (!st.empty()) {
        ans+=st.top();
        st.pop();
    }
    
  
  
    return ans;
    } 
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends