#include<bits/stdc++.h>
using namespace std;
class BookMyShow {
public:
    vector<int> seats;
    long leftover;
    int prev,m,start;
    BookMyShow(int n,int mm) {
        seats=vector<int>(n,mm);
         m=mm;start=0;
         leftover=0;
         prev=-1;
    }

    
    vector<int> gather(long k,int maxRow) {
        vector<int>ans;
        if(k>m||prev==-2)
         {return ans;}
        for(int i=start;i<=maxRow;i++)
          { //cout<<start<<endl;
            if(seats[i]>=k)
             { ans.push_back(i); 
               ans.push_back(m-seats[i]);
               if(prev>=i)
               {
                 leftover=leftover-seats[i];
                 if(leftover<0)
                  {leftover=0;}
               }
               else
               {prev=i;}
               seats[i]-=k;
               leftover+=seats[i];
               if(!seats[i]&&!leftover){start++;}
               break;
             }
          } 
        return ans;
    }
    
    bool scatter(int k,long maxRow) {
        if(prev==-2){return 0;}
       if(maxRow>=prev)
        {if(k>((maxRow-prev)*m +leftover))
          {return 0;}
         if(k>=leftover)
          {start=++prev;
           k-=leftover;
           leftover=0;
           if(k!=0)
            {
              start+=k/m;
              if(start<seats.size())
               {seats[start]-=k%m;}
              else 
               {prev=-2;
                return 1;}
              leftover+=seats[start];
              prev=start;
             }
            return 1;     
          }   
        }
        else
         {
           if(leftover<k)
            {return 0;}
         } 
        for(int i=start;i<=maxRow;i++)
          { if(!seats[i]&&!leftover)
             {start++;continue;} 
            if(prev>=i)
             {leftover=leftover-seats[i];
                 if(leftover<0)
                  {leftover=0;}
             }
            if(seats[i]>=k)
            { seats[i]-=k;
              leftover+=seats[i];
              k=0;
              start=i;
              break;
            }
            else
            {k-=seats[i];
                seats[i]=0;}  
          }
          return !k;
        } 
};