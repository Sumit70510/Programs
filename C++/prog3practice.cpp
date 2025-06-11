int maxSubarraySum(int a[], int n){

    long long maxh = 0, maxf = INT_MIN;

    for(int i=0;i<n;i++) //iterating over array
        {
            maxh+=a[i];
            maxf=max(maxh,maxf); //Seeing if adding current element increases the sum of not

            // check at any index, if maxh is negative
            // if it becomes negative, then make it 0 again
            if(maxh<0)
                maxh=0;

        }
        return maxf;

}
