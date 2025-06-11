#include<bits/stdc++.h>
using namespace std;

int main()
{
  vector <pair<int,int>> arr(10);
  for(int i=0;i<10;i++)
    { arr[i].first=(i+1)*2 ;
      arr[i].second=i+1;  
    } 
  sort(arr.begin(),arr.end(),greater<>());
  cout<<"FIRST : ";
  for(int i=0;i<10;i++)
   { cout<<arr[i].first<<" ";}  
  cout<<"\nSECOND : ";
  for(int i=0;i<10;i++)
   { cout<<arr[i].second<<" ";}
   cout<<endl;  
  return 0;  
}