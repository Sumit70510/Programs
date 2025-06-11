#include<bits/stdc++.h>
using namespace std;
vector <int > input(vector<int>arr,int size)
{ if(size>0)
  {  arr=input(arr,(size-1)); 
  }
  else
  {int temp;
     cin>>temp; 
     vector<int> temperary;
     temperary.push_back(temp);
     return temperary;}
}
int main()
{   
    vector <int> a;
    int temp,n;
    cout<<"ENTER THE SIZE OF VECTOR : ";
    cin>>n;
    a=input(a,n);
    ///////////vector entered////////////
    cout<<"NOW OUTPUT TURN "<<endl;
    cout<<a.size();    
    /* for (auto b : a)
     cout<<b<<" ";
     */   
    return 0;
}