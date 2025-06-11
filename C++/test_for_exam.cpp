#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector <int> v;
    for(int i=0;i<10;i++)
    {
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    for(auto a:v)
    { 
        cout<<a<<endl;
    }
    return 0;    
}