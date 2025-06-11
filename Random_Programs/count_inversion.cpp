#include<bits/stdc++.h>
using namespace std;
int merge(int arr[],int l,int mid,int r)
{ 
  int count=0;
  int n1=mid-l+1;
  int n2=r-mid;
  int a[n1],b[n2];
 
  for(int i=0;i<n1;i++)
   {a[i]=arr[i+l];}
  
  for(int i=0;i<n2;i++)
   {b[i]=arr[i+mid+1];}
  int i=0,j=0,k=l;
  while(i<n1&&j<n2)
  {
    if(a[i]<=b[j])
    {arr[k]=a[i];i++;k++;}
    else
    {arr[k]=b[j];j++;k++; count+=n1-i;  }
  }
  while(i<n1)
   {arr[k]=a[i];i++;k++;}

  while(j<n2)
   { arr[k]=b[j];j++;k++; }
  return count; 
}
int merge_sort(int arr[],int l,int r)
{   int count=0;
    if(l<r)
    {
        int mid=(l+r)/2;
        count+=merge_sort(arr,l,mid);
        count+=merge_sort(arr,mid+1,r);
        count+=merge(arr,l,mid,r);
    }
    return count;
}
int main()
{
  int n;
  cout<<"Enter The Size Of Array : ";
  cin>>n;
  int arr[n],count;
  for(int i=0;i<n;i++)
  {cin>>arr[i];}
  count = merge_sort(arr,0,n);
  for(int i=0;i<n;i++)
  {cout<<arr[i]<<" ";}
  cout<<endl;
  cout<<count<<" ";
  cout<<endl;
  return 0;
}