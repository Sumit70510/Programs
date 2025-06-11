#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{ 
	  int n,k;
	  cin>>n>>k;
	  string s_changed,temp="",aranged="";
	  cin>>s_changed;
	   for(int i=0;i<k;i++)
	   {temp+=s_changed[i];}
	  int count_front=0,count_back=0;
	  count_front=((k%2==0)?k/2:(k/2)+1);
	  count_back=k/2;
	  for(int i=0,j=k-1;i<count_front;i++,j--)
	   { 
	     aranged+=temp[i];
	     if(count_back>0)
	      {
	         aranged+=temp[j];
	         count_back--;
	      }
	   }
	  for(int i=0;i<k/2;i++)
	   {
	     swap(aranged[i],aranged[k-i-1]);    
	   }
	  for(int i=k;i<n;i++)
	  {
	    aranged+=s_changed[i];  
	  }
	 cout<<aranged<<endl; 
	}
	return 0;
}

