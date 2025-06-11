#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string password;
	    cin>>password;
	    if(password.length()<10)
	    {cout<<"NO";}
	    else
	    {   bool c1=1,c2=1,c3=1,c4=1;
	        int check=0;
	        for(int i=0;i<password.length();i++)
	        {
	            if(password[i]>='a'&&password[i]<='z'&&c1)
	            {c1=0;check++;}
	            if(password[i]>='A'&&password[i]<='Z'&&c2)
	            {c2=0;check++;}
	            if(password[i]>='0'&&password[i]<='9'&&c3)
	            {c3=0;check++;}
	            if((password[i]=='@'||password[i]=='&'||password[i]=='#'||password[i]=='%'||password[i]=='?')&&c4)
	            {c4=0;check++;}
	            if(check>=4)
	            {break;}
	        }
	        if(check>=4)
	        {cout<<"YES";}
	        else
	        {cout<<"NO";}
	    }
	    cout<<endl;
	} cin>>t;
	return 0;
}


