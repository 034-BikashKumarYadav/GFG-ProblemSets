//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
      vector<int>computeLPS(string& pat){
       int len=0;
       int n=pat.size();
       vector<int>lps(n,0);
       int i=1;
       while(i<n){
           if(pat[i]==pat[len]){
               len++;
               lps[i]=len;
               i++;
           }
       
       else{
           if(len!=0){
               len=lps[len-1];
           }
           else{
               lps[i]=0;
               i++;
           }
       }
       }
       
       return lps;
       
   }
   
   
   
    vector<int> search(string& pat, string& txt) {
        // code here
        int pat_size=pat.size();
        int txt_size=txt.size();
        vector<int>ans;
        vector<int>lps=computeLPS(pat);
        int i=0,j=0;
        while(i<txt_size){
            if(pat[j]==txt[i]){
                i++;
                j++;
            }
            if(j==pat_size){
                ans.push_back(i-j);
                j=lps[j-1];
            }
            else if(i<txt_size && pat[j]!=txt[i]){
                if(j!=0){
                    j=lps[j-1];
                }
                else{
                    i++;
                }
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
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0)
            cout << "[]" << endl;
        else {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends