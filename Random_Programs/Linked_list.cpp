#include<bits/stdc++.h>
using namespace std;
class node
{
 public:
 int n;
 node *next;
 node()
 { next=NULL;}
}*head,*start;
 void insert(int item)
 {
      node *input;
      input= new node;
      input->n=item;
      input->next=NULL;
      if(head==NULL)
       {start=head=input;
         return;}
      head->next=input;
      head=input;
      // delete temp;
      //delete input;
 }
 void display()
 {
     while(head!=NULL)
     {
         cout<<head->n<<" -> ";
         head=head->next;
      }
     cout<<"!!!\n";
 }
int main()
{
  int item;
  char ch;
  head=NULL;
  do
  {cout<<"ENTER THE ELEMENT : ";
   cin>>item;
   insert(item);
   cout<<"DO YOU WANT TO ENTER MORE ELEMENTS (Y/N) : ";
   cin>>ch;
  }while(ch=='Y'||ch=='y');
   head=start;
   cout<<"\nELEMENTS PRESENT IN THE LINKED LISTS ARE :-\n";
   display();
  return 0;
}
