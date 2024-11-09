//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string minSum(vector<int> &arr) {
          sort(arr.begin(), arr.end());
        
        string digit1;
        string  digit2;
        int n=arr.size();
        
        for(int i=0;i<n;i++){
            if(i%2==0){
            digit1+=to_string(arr[i]);
            }
            else{
                digit2+=to_string(arr[i]);
            }
        }
        //int sum=0;
        int carry=0;
        
        int i=digit1.size()-1;
        int j=digit2.size()-1;
        
        string res="";
        
        while(i>=0||j>=0 || carry>0){
            
           int sum=carry;
           if(i>=0){
               sum+=digit1[i]-'0';
               i--;
           }
           if(j>=0){
               sum+=digit2[j]-'0';
               j--;
           }
           res+=(sum%10)+'0';
            carry=sum/10;
        }
        reverse(res.begin(), res.end());
        int k=0;
        while(res[k]=='0'){
            k++;
        }
        if(res[0]=='0'){
             return res.substr(k,res.length()-1);
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends