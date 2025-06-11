#include<bits/stdc++.h>
using namespace std;
int partition(int arr[],int lb,int ub)
 {  int start=lb,end=ub;
    int pivot=arr[lb];
    while(start<end)
     {
       while(arr[start]<=pivot)
        {start++;}
       while(arr[end]>pivot)
        {end--;}
       if(start<end)
        {swap(arr[start],arr[end]);}  
     }
    swap(arr[lb],arr[end]); 
    return end; 
 }
void quick(int arr[],int lb,int ub)
{
  if(lb<ub)
   { int part=partition(arr,lb,ub);
     quick(arr,lb,part-1);
     quick(arr,part+1,ub);
   }
} 
int main()
{
   int arr[]={10,9,8,7,6,5,4,3,2,1};
   quick(arr,0,10);
   for(int i=0;i<10;i++)
    {cout<<arr[i]<<" ";}
   cout<<endl; 
   return 0; 
}