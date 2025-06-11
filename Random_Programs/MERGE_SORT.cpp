#include<bits/stdc++.h>
using namespace std;
void merge_s(int arr[],int r,int mid,int l)
{
  int n1=mid-l+1,n2=r-mid;
  int a[n1],b[n2];
  for(int i=0;i<n1;i++)
   { a[i]=arr[i+l]; }
  for(int i=0;i<n2;i++)
   { b[i]=arr[i+mid+1]; }

  int i=0,j=0,k=l;
  while(i<n1&&j<n2)
  {
    if(a[i]<b[j])
    {arr[k]=a[i];i++;k++;}
    else
    {arr[k]=b[j];j++;k++;}
  }
  while(i<n1)
   {arr[k]=a[i];i++;k++;}

  while(j<n2)
   { arr[k]=b[j];j++;k++; }

}
void Sort(int arr[],int l,int r)
{
    if(r>l)
    { 
        int mid=(r+l)/2;
        Sort(arr,l,mid);
        Sort(arr,mid+1,r);
        merge_s(arr,r,mid,l);
    }
}
int main()
{
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter array :- \n";
    for(int i=0;i<n;i++)
    {cin>>arr[i];}
   
    Sort(arr,0,n);
   
    for(int i=0;i<n;i++)
    {cout<<arr[i]<<" ";}
    cout<<endl;
    return 0;
}
