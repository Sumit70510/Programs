// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int getGray(int n) {
       int countbit=0,number=n;
       vector<int> bits;
       while(number)
        { countbit++;
          number>>=1; }
///////////////////////////////
  cout<<"\nBITS : "<<countbit<<endl;
       for(int i=0;i<countbit;i++)
        {bits.push_back((n&(1<<i))!=0);}
     cout<<endl;
     for(auto i: bits)
      {cout<<i<<" ";}
      cout<<endl;   
       if(n>0)
       { number=(bits[countbit-1]<<(countbit-1));}
       for(int i=countbit-2;i>=0;i--)
        { if(bits[i+1]^bits[i]==1)
            number|=(1<<i);
         }
/////////////////other number///////////////////////////
   cout<<endl;
      for(int i=0;i<countbit;i++)
       {cout<<((number&(1<<i))!=0)<<" ";}
       cout<<endl;
     return number;       
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.getGray(n) << endl;
    }
    return 0;
}  // } Driver Code Ends