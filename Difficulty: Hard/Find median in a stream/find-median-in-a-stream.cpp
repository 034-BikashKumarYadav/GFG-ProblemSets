//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   vector<double> getMedian(vector<int> &arr) {
        vector<int> sortedList;
        vector<double> medians;
    
        for (int num : arr) {
            // Insert the number into the correct position in the sorted list
            auto it = lower_bound(sortedList.begin(), sortedList.end(), num);
            sortedList.insert(it, num);
    
            // Calculate the median
            int n = sortedList.size();
            if (n % 2 == 1) {
                // Odd number of elements: median is the middle element
                medians.push_back(sortedList[n / 2]);
            } else {
                // Even number of elements: median is the average of the two middle elements
                medians.push_back((sortedList[n / 2 - 1] + sortedList[n / 2]) / 2.0);
            }
        }
    
        return medians;
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
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends