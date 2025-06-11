#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	//cin>>t;
    t=1;
	while(t--)
	{ 
	 
	 long int n;
	 cin>>n;
	 long int arr[n];
     int min;
     for(long int i=0;i<n;i++)
     {cin>>arr[i];}
     sort(arr,arr+n);
    // find the max frequency using linear traversal
    int max_count = 1, curr_count = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1])
            curr_count++;
        else {
            if (curr_count > max_count) {
                max_count = curr_count;
               }
            curr_count = 1;
        }
    }
 
    // If last element is most frequent
    if (curr_count > max_count)
    {max_count = curr_count;}
 
    min=max_count;
    
    if(n>1) 
     {  if(n==min)
         {min=0;}
        else
        {
         if(min-1==0)
          {min=-1;}
         else
          {min= n-min+1;}
        }     
     }  
    else
      {min=0;}
    // Print the result
    cout<<min<<endl;
	}
	return 0;
}

