 #include<bits/stdc++.h>
 using namespace std;
int main() 
{   short t;
    cin>>t;
    while(t--)
    {
        int n,k,i;
        cin>>n>>k;
        int a[n+1],sum=0;
        for(i=1;i<=n;)
          {  if(k==0||k==n)
              { if(k==n)
                  {a[i]=i;i++;}
                else
                 break;
              }
             else
              {
               if(sum+i<=i+1&&k>0)
                 {
                   a[i]=i;
                   sum+=i;i++;
                   k--;
                   continue;
                 }
                if(sum>i)
                 {
                   a[i]=-i;
                   sum-=i;i++;
                   if(sum>0)
                     k--;
                   continue; 
                 }
                if(sum+i>i+1&&k==1)
                 {
                   a[i]=-i;
                   i++;
                   if(sum-i>0)
                    break;
                   else
                    {sum-=i;
                     continue;   
                     }
                  }
                if(sum+i>i+1&&k>1)
                 {
                   a[i]=i;
                   if(sum>0)
                    k--;
                   sum+=i;
                   i++; 
                 }
              }     
           }
            if(i<=n)
            {
             for(;i<=n;i++)
              {a[i]=-i;}
            }
    
        
        for(int i=1;i<=n;i++)
         {cout<<a[i]<<" ";}
        cout<<endl;
    }
	return 0;
}
