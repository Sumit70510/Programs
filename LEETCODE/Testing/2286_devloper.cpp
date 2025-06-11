#include<bits/stdc++.h>
using namespace std;
class BookMyShow {
public:
    vector<int> seats,lc;
    int m,start,leftover;
    long capacity,prev;
    BookMyShow(long n,long mm) {
        seats=vector<int>(n,mm);
         m=mm;start=0;
         leftover=0;
         prev=-1;
         lc=vector<int>(n,0);
    }

    vector<int> gather(int k, int maxRow) {
        vector<int>ans;
      //*====================TESTING PHASE===========================
       cout<<"G:["<<setw(3)<<k<<","<<setw(3)<<maxRow<<"] St: ";
       cout<<setw(3)<<start<<", P: "<<setw(3)<<prev<<", L: "<<setw(3)<<leftover<<" [";
       int i=start;
       string s=",";
       if(start==prev)
        s="]";
        if(start>prev)
         cout<<"]";
       while(i<=prev)
        {cout<<setw(3)<<lc[i]<<s;
         if(i==prev-1)
          {s="]";}
        i++;}

       
       cout<<setw(24-(prev-start)*4);
      // cout<<endl;
      //*///=================END OF TEST===============================
        if(k>m||prev==-2)
         { 
      //*=======================TEST================================== 
       cout<<"ANS : []"<<endl;
      //*///====================END=================================== 
           return ans;
         }
        for(int i=start;i<=maxRow;i++)
          { //if(i==4)
            // {cout<<"ROW 4 ACCESSED LETS GRIND"<<endl;
            //  cout<<seats[i]<<endl;}
            if(seats[i]>=k)
             { ans.push_back(i); 
               ans.push_back(m-seats[i]);
               if(prev>=i)
               {leftover=max(leftover-seats[i],0);}
               else
               {prev=i;}
               seats[i]-=k;
               lc[i]=seats[i];
               leftover=leftover+seats[i];
               if(!seats[i]&&!leftover){start++;}
               break;
             }
          }
        //*========================TEST============================    
        cout<<"ANS :[ ";
        for(auto i:ans)
         {cout<<i<<" ";}
        cout<<"]"<<endl;
        //*///======================END============================ 
        return ans;
    }
    
    bool scatter(int k,long maxRow) {
      
      //*=========================TEEST============================= 
       long tk=k,tl=leftover;
       cout<<"S:["<<setw(3)<<k<<","<<setw(3)<<maxRow;
       cout<<"] St: "<<setw(3)<<start<<", P: "<<setw(3)<<prev<<", L: "<<setw(3)<<leftover<<" [";
       int i=start;
       string s=",";
       if(start==prev)
        s="]";
        if(start>prev)
         cout<<"]";
       while(i<=prev)
        {cout<<setw(3)<<lc[i]<<s;
         if(i==prev-1)
          {s="]";}
        i++;}
        cout<<setw(24-(prev-start)*4);
      // cout<<endl; 
      //*///========================END============================
       if(prev==-2)
        {
      //=========================TEST==============================  
          cout<<" 0 FALSE "<<endl;
          return 0;
        }
       if(maxRow>=prev)
        {if(k>((maxRow-prev)*m +leftover))
          {
       //========================TEST==============================    
            cout<<" 1 FALSE "<<endl;  
            return 0;
          }
         if(k>=leftover)
          {
           int i=start;
           start=++prev;
           k-=leftover;
          //*==========================TEST============================= 
           while(i<=prev)
            {lc[i]=0;i++;}
          //*///========================================================  
           leftover=0;
          if(k!=0)
            {
             start+=k/m;
             if(start>=seats.size())
              {prev=-2;
          //=============================TEST============================
             cout<<" 0 TRUE "<<endl;    
              return 1;
              }
        /*============================TEST================================      
             if(start==4)
             {cout<<"ROW 4 ACCESSED LETS GRIND in Scatter finction"<<endl;
              cout<<seats[start]<<endl;
              cout<<"maxRow   : "<<maxRow<<endl;
              cout<<"Seats(k) : "<<tk<<endl;
              cout<<"present k: "<<k<<endl;
              cout<<"Leftover : "<<tl<<endl;
              cout<<"k%m here : "<<k%m<<endl;
              cout<<"previous : "<<prev<<endl;
             } 
        //*///=============================END================================     
             seats[start]-=k%m;
             lc[start]=seats[start];
             leftover+=seats[start];
             prev=start;
             }
        //*/===============================TEST================================     
            cout<<" 1 TRUE "<<endl; 
            return 1;     
          }   
        } 
      else
       {
         if(leftover<k)
          {
       cout<<" TESTES CASE FOR FALSE "<<endl;
       return 0;     
          }
       }   
   /*==================================TEST=================================== 
      //reset every thing 
    vector<int> copy=seats;
    long cp=prev;    
   //*///================================END=====================================
        for(int i=start;i<=maxRow;i++)
          { if(!seats[i]&&!leftover)
             {start++;continue;} 
      /*===============================TEST===================================    
            if(start==4)
             {cout<<"ROW 4 ACCESSED LETS GRIND in Scatter function loop "<<endl;
              cout<<seats[start]<<endl;
              cout<<"WHAT ARE YOU DOING "<<endl;
             } 
      //*///============================END===================================       
            if(prev>=i)
             {leftover=max(leftover-seats[i],0);}
            if(seats[i]>=k)
            { seats[i]-=k;
              leftover+=seats[i];
              lc[i]=seats[i];
              k=0;
              start=i;
              break;
            }
            else
            {k-=seats[i];
             lc[i]=seats[i];
                seats[i]=0;}  
          }
    //*================================TEST==========================
          if(k)
            {cout<<" 2 FALSE "<<endl;
            /*
              leftover=tl;
              prev=cp;
              seats=copy;//*/
            }
          else
            {cout<<" 2 TRUE "<<endl;}  
    //*///============================END=============================        
          return !k;
        } 
};
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
            {cout<<i<<": ["<<cordinates[j-1][0]<<","<<cordinates[j-1][1]<<"]"<<" :  Null"<<endl;
            }
         if(i=="gather")
           {ans=obj.gather(cordinates[j][0],cordinates[j][1]);j++;
            /*cout<<i<<"    : ["<<cordinates[j-1][0]<<","<<cordinates[j-1][1]<<"] : [";
            string s=",";
            for(auto i:ans)
             {cout<<i<<s;s="";}
             cout<<"]"<<endl;*/
           }         
         if(i=="scatter")
           {r=obj.scatter(cordinates[j][0],cordinates[j++][1]);
            /*string s;
            if(r==1){s="TRUE";}
            else
             {s="FALSE";}
            cout<<i<<"   : ["<<cordinates[j-1][0]<<","<<cordinates[j-1][1]<<"] : ["<<s<<"]"<<endl;        
           */
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