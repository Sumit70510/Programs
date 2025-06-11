#include <bits/stdc++.h>
using namespace std;

int main() {
	string s,least;
	int len,init=0,ch=0,fnl=INT_MAX,found=0;
	getline(cin,s);
	for(long i=0;i<s.length();i++)
    {  init =i;
       len=s.find(' ');
       if(len!=-1&&len<s.length())
        {
          s[len]='*';
          ch=len-init;
          if(ch<fnl)
          { fnl=ch;
            found=init; }
          i=len;
        }
        else
        {
            if((s.length()-init)<fnl)
            {
                fnl=s.length()-init;
                found=init;
            }
            break;
        }
    } string word,temp;
    for(int i=found;i<found+fnl;i++)
     {word+=s[i];}
     temp=word;
    word+=' ';
    for(int i=0;i<s.length();i++)
    { cout<<word;
      while(s[i]!='*'&&i<s.length())
      {cout<<s[i++];}
      if(i<s.length())
       cout<<' ';
    }
    cout<<' '<<temp;
	return 0;
}
