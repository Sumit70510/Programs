#include<bits/stdc++.h>
using namespace std;

struct Node
{
  Node *links[26];
  bool flag=false;

  Node * get(char ch)
   {
    return links[ch-'a'];
   }

  bool containKey(char ch)
   {
    return (links[ch-'a']!=NULL);
   }

  void put(char ch,Node *node)
   {
    links[ch-'a']=node;
   }

  void setEnd()
   {
    flag=true;
   }

  bool isEnd()
   {
    return flag;
   }

};

class Trie
{
  private:
   Node *root;
  public :
   Trie()
    { root = new Node(); }
   
  void insert(string word)
   {
     Node *node=root;
     for(int i=0;i<word.length();i++)
      {
        if(!node->containKey(word[i]))
         {
           node->put(word[i],new Node());
         }
        node->get(word[i]); 
      }
     node->setEnd();
   }
 
  bool search(string word)
   {
     Node *node=root;
     for(int i=0;i<word.length();i++)
      {
        if(!node->containKey(word[i]))
         {
           return false;
         }
        node=node->get(word[i]); 
      }
     return node->isEnd(); 
   }
   
  bool startWith(string word)
   {
     Node *node=root;
     for(int i=0;i<word.length();i++)
      {
        if(!node->containKey(word[i]))
         {return false;}
        node=node->get(word[i]); 
      }
     return true; 
   } 
   
};

int main()
{
   string s;
   char ch;
   Trie reference;
   do 
    {
     cout<<"Enter The Word You Want To Insert : ";
     cin>>s;
     reference.insert(s); 
     cout<<"Want To Insert More (Y/N) : ";
     cin>>ch; 
    }while(ch=='y'||ch=='Y');

   do 
    {
     cout<<"Enter the Elements You want To Search For : ";
     cin>>s;
     if(reference.search(s))
      {cout<<"The Element Exists"<<endl;}
     else
      {
       cout<<"Such Element Doesn't Exist"<<endl; 
      }  
     if(reference.startWith(s))
      {
        cout<<"There Are Elements That Starts with : "<<s<<endl;
      } 
     else 
      {
        cout<<"No Elements Starts With : "<<s<<endl;
      } 
     cout<<"Want To Search More (Y/N) : ";
     cin>>ch; 
    }while(ch=='y'||ch=='Y');
   
    return 0; 
}