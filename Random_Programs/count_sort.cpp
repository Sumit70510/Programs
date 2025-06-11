#include<iostream>
using namespace std;
void count_sort(int arr[],int n)
{
 int mx=0;
 for(int i=0;i<n;i++)
  {mx=max(mx,arr[i]);}
 int count[mx+1]={0};
 for(int i=0;i<n;i++)
  {count[arr[i]]++;}
 for(int i=1;i<=mx;i++)
  {count[i]+=count[i-1];}  
 int output[n];
 for(int i=0;i<n;i++)
  {count[arr[i]]--;
   output[count[arr[i]]]=arr[i];}
 for(int i=0;i<n;i++)
  {arr[i]=output[i];}
}
int main()
{
 int n;  
 cout<<"Enter the size of array : ";
 cin>>n;
 int arr[n];
 for(int i=0;i<n;i++)
  {cin>>arr[i];}
 count_sort(arr,n);
 cout<<"Sorted array : ";
 for(int i=0;i<n;i++)
  {cout<<arr[i]<<" ";}
 cout<<endl;
 return 0; 
}