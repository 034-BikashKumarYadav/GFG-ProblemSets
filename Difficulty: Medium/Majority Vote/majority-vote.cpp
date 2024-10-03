//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        // Your code goes here.
         int candidate1=0,candidate2=1,count1=0,count2=0;
        for(int i : nums){
            if(i==candidate1) count1++;
            else if(i==candidate2) count2++;
            else if(count1==0){ candidate1=i; count1++; }
            else if(count2==0){ candidate2=i; count2++; }
            else{ count1--; count2--; }
        }
        vector<int> majority;
        count1=count2=0;
        for(int i : nums){ 
            if(i==candidate1) count1++;
            if(i==candidate2) count2++;
        }
        if(count1>nums.size()/3) majority.push_back(candidate1);
        if(count2>nums.size()/3) majority.push_back(candidate2);
        if(majority.empty()) return {-1};
        if(majority.size()==2&&majority[0]>majority[1]) swap(majority[0],majority[1]);
        return majority;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends