// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        set<int>s;
        int a,b;
         int z[] = new int[2];
        for(int i=0;i<n;i++)
         {
            if(s.count(arr[i]))
             {z[0]=arr[i];}
             s.insert(arr[i]);
         }
         int k=1;
        for(auto i:s)
         { if((i)!=k)
            {z[1]=k;break;} 
           k++;     
         }
        return z; 
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends