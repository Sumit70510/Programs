 #include<bits/stdc++.h>
 #include<math.h>
using namespace std;
int main()
{   int t;
    long long int n,x,a[10000000],i,p,r,f,track,w,j;
    cin>>t;
    while(t--)
    {
        cin>>n>>x;
        for(i=0;i<n;i++)
         cin>>a[i];
         i=0;
        for(f=x;f>0&&i<n-1;f--)
        {   w=0; 
            p=log(a[i])/log(2);
            r=pow(2,p);
            a[i]=a[i]^r;
            
            for(j=i+1;j<n-1;j++)
             {if(a[j]^r<a[j])
               {a[j]=a[j]^r;
                  w=1;break;
               }
             } 
              if(w==0)
             {a[n-1]^=r;}
            
            while(a[i]<=0)
             i++;
            track=f+1;
         }
          if(track>0)
           {  if(n<3&&(track%2)>0)
               {
                   a[n-2]^=1;
                   a[n-1]^=1;
                }
           }
         for(i=0;i<n;i++)
          {cout<<a[i]<<" ";}
          cout<<endl;
        }
	return 0;
}
