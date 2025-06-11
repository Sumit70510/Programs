// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++
int degrade(int *price,int n,int fix)
{
    int sum=0,maxsum=0;
    int i;
    if(n==fix)
     { n--;sum=maxsum=price[n];}
    i=n-1;
    for(;i>=ceil((float)((n-1)/2));i--)
    {  
        for(int j=0;j<=ceil((float)((n-1)/2));j++)
         {sum = price[i] + price[(n-i-1)];
          maxsum=max(maxsum,sum);}
    }
return maxsum;    
}
int fcheck(int *price,int n,int sum,int fix)
 {  int mark=0,tsum=0,temp=0;
    for(int i=0;i<=(n/(n/(i+1)));i++)
    {   
        temp=price[i]*(n/(i+1));
        tsum+=degrade(price,n%i,fix);
        tsum=max(tsum,temp);
        
        
    }
 }
class Solution{
  public:
    int cutRod(int price[], int n) {
        int sum;
        sum=degrade(price,n,n);
        sum=max(sum,fcheck(price,n,sum,n));
        return sum;
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
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends