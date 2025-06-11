#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
    vector<int> v;
    string s;
    int data;
    getline(cin,s);
    istringstream iss(s);
    while (iss>>data)
        v.push_back(data);
      int k,num;
      cin>>k>>num;
      sort(v.begin(),v.end());
      if(v[k-1]>num)
        cout<<"True";
      else
        cout<<"False";
    
    
    return 0;
}
