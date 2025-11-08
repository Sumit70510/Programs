#include<bits/stdc++.h>
using namespace std;

int main()
{
   int t;
   cin>>t;
   while(t--)
    {
      int n;
      cin>>n;
      vector<int>freq(102,0);
      for(int i=0;i<n;i++)
       {
        int temp;
        cin>>temp;
        freq[temp]++;
       } 
      for(int i=0;i<freq.size();i++)
       {
         if(freq[i]==0)
          {
            cout<<i<<endl;
            break;
          }
       } 
    } 
   return 0; 
}