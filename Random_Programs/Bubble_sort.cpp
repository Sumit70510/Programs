#include<bits/stdc++.h>
using namespace std;
int *input_data(int n)
{
  int *arr;
  arr=new int [n];
  for(int i=0;i<n;i++)
  {cin>>*(arr+i);}
  return arr;
}
void print_data(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {cout<<*(arr+i)<<" ";}
    cout<<endl;
}
void bubble_sort(int *arr,int n)
{
    for(int i=0;i<n-1;i++)
    {
       for(int j=0;j<n-i-1;j++)
       {
          if(*(arr+j)>(*(arr+j+1)))
          {swap(*(arr+j),*(arr+j+1));}
       }
    }
}
int main()
{
    int n;
    cout<<"Enter the Size of Array : ";
    cin>>n;
    int *arr;
    arr=new int [n];
    arr=input_data(n);
    bubble_sort(arr,n);
    cout<<"SORTED  ARRAY  :-\n";
    print_data(arr,n);
    delete arr;
    return 0;
}
