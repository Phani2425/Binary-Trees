//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  void helperFun(int arr[],int &N,int upper,int lower, int& index){
      if(index>=N || arr[index] > upper || arr[index] < lower){
          return;
      }
      
      int curr = arr[index];
      index++;
      
      helperFun(arr,N,curr,lower,index);
      helperFun(arr,N,upper,curr,index);
      
  }
    int canRepresentBST(int arr[], int N) {
        int upper = INT_MAX;
        int lower = INT_MIN;
        int index = 0;
        helperFun(arr,N,upper,lower,index);
        if(index < N){
            return 0;
        }
        return 1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        Solution ob;
        cout << ob.canRepresentBST(arr, N) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends