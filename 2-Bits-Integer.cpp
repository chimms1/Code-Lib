#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int setBits(int N) {
        // Write Your Code here
        
        int count = 0;
        int n = N;
        
        while(n)
        {
            // Checks and counts if units place has 1 in binary
            count += n & 1;
            
            // remove the unit digit and check again when next digit comes to units place
            n = n>>1;
        }
        
        return count;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        Solution ob;
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}

// } Driver Code Ends
