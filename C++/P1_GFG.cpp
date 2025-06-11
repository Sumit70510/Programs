// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 // } Driver Code Ends

class Solution
{
  public: void SieveOfEratosthenes(int largest, vector<int> &prime)
    {
    	bool isPrime[largest+1];
    	memset(isPrime, true, sizeof(isPrime));
       for (int p=2; p*p<=largest; p++)
    	{
    		if (isPrime[p] == true)
    		{
    			for (int i=p*2; i<=largest; i += p)
    				isPrime[i] = false;
    		}
    	}
    	for (int p=2; p<=largest; p++)
    		if (isPrime[p])
    			prime.push_back(p);
    }
	                 
    long long int countDivisorsMult(int arr[], int n)
    {
    	int largest = *max_element(arr, arr+n);
    	vector<int> prime;
    	SieveOfEratosthenes(largest, prime);
    	unordered_map<int, int> mp;
    	for (int i=0; i<n; i++)
    	{
    		for (int j=0; j<prime.size(); j++)
    		{
    			while(arr[i] > 1 && arr[i]%prime[j] ==0 )
    			{
    				arr[i] /= prime[j];
    				mp[prime[j]]++;
    			}
    		}
    		if (arr[i] != 1)
    			mp[arr[i]]++;
    	}
    	long long int res = 1;
    	for (auto it : mp)
    	res *= (it.second + 1L);
    
    	return res;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	  int n,i;
	  cin>>n; int arr[n];
	  for(i=0;i<n;i++)
	  cin>>arr[i];
	  Solution obj;
	  cout <<obj.countDivisorsMult(arr, n)<<"\n";
	}
	return 0;
}
// } Driver Code Ends