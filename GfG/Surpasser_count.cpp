// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
void merge(int arr[],vector<int>&count,int l,int mid,int r)
{
    int n1=mid-l+1;
    int n2=r-l;
    int a[n1],b[n2];
    
    for(int i=0;i<n1;i++)
     {a[i]=arr[i+l];}
    for(int i=0;i<n2;i++)
     {b[i]=arr[i+mid+1];}
    
    int i=0,j=0,k=l;
    
    while(i<n1&&j<n2)
    {
      if(a[i]<b[j])   
      {arr[k]=a[i];
       i++;k++;
       count[k]+=n2-j;
      }
      else
      { arr[k]=b[j];
        j++;k++;
      }
    } 
    while(i<n1)
    {
      arr[k]=a[i];
      i++;k++;
    } 
    while(j<n2)
    { arr[k]=b[j];
        j++;k++;  }
}
void merge_sort(int arr[],vector<int>&count,int l,int r)
{
  if(l<r)
  { int mid=(r+l)/2;
    merge_sort(arr,count,l,mid);
    merge_sort(arr,count,mid+1,r);
    merge(arr,count,l,mid,r);
  }
}
class Solution{
public:

    vector<int> findSurpasser(int arr[], int n) {
        vector<int> spass(n,0);
        merge_sort(arr,spass,0,n);
        return spass;
    }
};

// { Driver Code Starts.aaa
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findSurpasser(arr, n);
        for (auto i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

  // } Driver Code Ends