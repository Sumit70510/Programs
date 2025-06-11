#include<bits/stdc++.h>

using namespace std;

bool isnum(string s)
 {return (s[0]>='0'&&s[0]<='9');}

bool isalph(string s)
 {return (s[0]=='a'||s[0]=='s'||s[0]=='m'||s[0]=='d');} 

int evaluate(string expr) {
	// Write your code here
	int ans=0,curr=0;
	stack<string> s;
	string action="";
	for(int i=0;i<expr.length();i++)
	 { action="";
	   if(isalph(expr[i]))
	   {
	   s.push(expr.substr(i,1));
	   int temp=i;
       while(temp<expr.length() && !(isnum(expr.substr(temp,1))))
        {temp++;}
        // cout<<temp;
	   while(temp<expr.length()&&(expr[temp]!=','&&expr[temp]!=')'))
	    {
          action+=expr[temp];
		  temp++;
		} 
        // cout<<"^^^"<<action<<endl;
		i=temp;
		while(!s.empty()&&isnum((s.top()).substr(0,1)))
		 { 
			int a=stoi(s.top());
			int b=stoi(action);
			int c;
			s.pop();
			string test=s.top();
			switch(test[0])
			 {
				 case 'a': c=a+b;  break;
				 case 's': c=a-b;  break;
				 case 'm': c=a*b; break;
				 case 'd': c=a/b;  break;
			 } 
			s.pop();
			action=to_string(c);
		 }
        //  cout<<"i:"<<i<<" a: "<<action<<endl;
		 s.push(action);
		//  action="";
	   }
	  else
	   {
		 if(isnum(expr.substr(i,1)))
		  { 
            //  cout<<"##{"<<expr[i]<<endl;
            //  cout<<s.top()<<"  }"<<endl; 
         int temp=i;
		 while(temp<expr.length()&&(expr[temp]!=','||expr[temp]!=')'))
	      {
           action+=expr[temp];
		   temp++;
		  } 
		i=temp; 
             while(!s.empty()&&isnum((s.top()).substr(0,1)))
		     {
			  int a=stoi(s.top());
			  int b=stoi(action);
			  int c;
		      s.pop();
			  string test=s.top();
			  switch(test[0])
			 {
				 case 'a': c=a+b;  break;
				 case 's': c=a-b;  break;
				 case 'm': c=a*b; break;
				 case 'd': c=a/b;  break;
			 } 
			s.pop();
			// cout<<"FIRST OPERSTION : "<<c<<endl;
            action=to_string(c);

		   } 
		 s.push(action);
		 action="";
		  }
	   } 
	 }
	ans=stoi(s.top()); 
    return ans;
}

int main()
{
string str;
cin>>str;
cout<<str<<endl;
cout<<evaluate(str);
return 0;
}