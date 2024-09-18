//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
          unordered_map<char, int> symbols { {'(', -1}, {'{', -2}, {'[', -3}, {')', 1}, {'}', 2}, {']', 3}};
        
        stack<char> st;
        
        for(char bracket : x) {
            if(symbols[bracket] < 0){ //it means opening bracket
                st.push(bracket);
            } else { //closing bracket
                if(st.empty())return false;
                
                char topElement = st.top();
                st.pop();
                if(symbols[topElement] + symbols[bracket] != 0){
                    return false;
                }
            }
        }
        if(st.empty())return true;
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends