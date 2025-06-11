#include<iostream>
using namespace std;
int main()
{
    int arr[5]={4,0,2,1,3};
    int n=5;
    for(int i=0;i<n;i++)
    {
      arr[i]+=(arr[arr[i]]%n)*n;
    }
    for(int i=0;i<n;i++)
     cout<<arr[i]/n<<" ";
    cin>>n;
 return 0;
}
