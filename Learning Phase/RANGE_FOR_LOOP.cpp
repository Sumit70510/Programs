#include<iostream>
#include<vector>
int main()
{ int arr[]={1,2,4,554,2,3,223,442};
  for (int i: arr)
   {std::cout<<&i<<" ";}
  std::cout<<"\n"; 
  int k=0;
  for (char i: arr)
   {std::cout<<i<<" ";k++;}
  std::cout<<"\n"; 
   std::cout<<k; 
  std::cout<<"\n"; 
  std::vector<int> v(8,5);
  v.pop_back();
  for(auto i :v )
   {std::cout<<i<<" ";}
  std::cout<<"\n"; 
  v.pop_back();
  for(int i:v )
   {std::cout<<i<<" ";}
std::cout<<"\n";
for(std::vector<int>::iterator i= v.begin();i!=v.end();i++)
  {std::cout<<*i<<" ";}
 return 0;
}