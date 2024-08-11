//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        vector<int> ans;
        deque<int> dq;
        int i = 0,j = 0;
        int count = 1;
        while(count < k){
            while(dq.size()>0 && arr[dq.back()]<=arr[j]){
                dq.pop_back();
            }
            dq.push_back(j);
            j++;
            count++;
        }
        j--;
        
        while(j<n-1){
            j++;
            while(dq.size()>0 && arr[dq.back()]<=arr[j]){
               dq.pop_back();
            }
           dq.push_back(j);
            
            if(dq.front()< i){
                dq.pop_front();
            }
            
           
            ans.push_back(arr[dq.front()]);
            i++;
            
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends