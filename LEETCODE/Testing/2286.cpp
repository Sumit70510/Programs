#include<bits/stdc++.h>
using namespace std;
class BookMyShow {
public:
    vector<int> seats;
    int m,start,leftover;
    long capacity;
    long prev;
    BookMyShow(long n,long mm) {
        seats=vector<int>(n,mm);
         m=mm;start=0;
         leftover=0;
         prev=-1;
    }

    
    vector<int> gather(int k, int maxRow) {
        vector<int>ans;
        if(k>m)
         {return ans;}
        for(int i=start;i<=maxRow;i++)
          { //cout<<start<<endl;
            if(seats[i]>=k)
             { ans.push_back(i); 
               ans.push_back(m-seats[i]);
               if(prev>=i)
               {leftover=max(leftover-seats[i],0);}
               seats[i]-=k;
               leftover+=seats[i];
               if(!seats[i]&&!leftover){start++;}
               prev=i;
               break;
             }
          } 
        return ans;
    }
    
    bool scatter(int k,long maxRow) {
       if(maxRow>=prev)
        {if(k>((maxRow-prev)*m +leftover))
          {return 0;}
         if(k>=leftover&&leftover)
          {start=++prev;
           k-=leftover;
           leftover=0;
           if(k!=0)
            {
             start+=k/m;
             prev=start;
             seats[start]-=k%m; 
             }
            return 1;     
          }   
        }  
        for(int i=start;i<=maxRow;i++)
          { if(!seats[i]&&!leftover)
             {start++;continue;}
            if(prev>=i)
              {leftover=max(leftover-seats[i],0);}
            if(seats[i]>=k)
            { seats[i]-=k;
              leftover+=seats[i];
              k=0;
              prev=i;
              break;
             }
             else
              { {k-=seats[i];
                 seats[i]=0;
                }
              } 
          }
          return !k;
        } 
};
/*
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */
class Test
{
    public:
     void Fname(vector<string> s,vector<vector<int>>cordinates)
       { int j=0;
        BookMyShow obj(cordinates[j][0],cordinates[j++][1]);
        vector<int>ans(2);
        string z=".  ";
        bool r;
        for(auto i:s)
         {  if(j>=10)
             {z=". ";}
            cout<<j<<z;
            if(i=="BookMyShow")
            {cout<<i<<": ["<<cordinates[j-1][0]<<","<<cordinates[j-1][1]<<"]"<<" :  Null"<<endl;}
         if(i=="gather")
           {ans=obj.gather(cordinates[j][0],cordinates[j][1]);j++;
            cout<<i<<"    : ["<<cordinates[j-1][0]<<","<<cordinates[j-1][1]<<"] : [";
            string s=",";
            for(auto i:ans)
             {cout<<i<<s;s="";}
             cout<<"]"<<endl;
           }         
         if(i=="scatter")
           {r=obj.scatter(cordinates[j][0],cordinates[j++][1]);
            string s;
            if(r==1){s="TRUE";}
            else
             {s="FALSE";}
            cout<<i<<"   : ["<<cordinates[j-1][0]<<","<<cordinates[j-1][1]<<"] : ["<<s<<"]"<<endl;        
           }         
         
         }
      }
};

int main()
{
vector<vector<int>> cordinates={{46,698},{628,41},{321,34},{171,1},{771,5},{742,11},{637,20},{478,43},{349,25},{490,11},{98,44},{516,36},{927,12},{681,25},{371,24},{650,1},{790,3},{507,0},{280,4},{113,42},{16,38},{395,33},{121,15},{893,25},{665,37},{490,26},{777,11},{673,23},{544,8},{729,18},{339,21},{387,26},{742,30},{765,18},{253,26},{549,14},{671,9},{629,37},{964,3},{657,8},{236,36},{120,8},{44,6},{671,12}};
vector<string> s={"BookMyShow","gather","gather","scatter","scatter","gather","gather","gather","scatter","scatter","gather","gather","gather","scatter","gather","gather","gather","scatter","gather","gather","gather","gather","scatter","gather","scatter","scatter","gather","scatter","scatter","scatter","scatter","gather","gather","gather","scatter","gather","scatter","scatter","gather","gather","gather","scatter","scatter","gather"};
  Test t;
  t.Fname(s,cordinates);
  return 0;
}