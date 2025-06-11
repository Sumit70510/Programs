#include<iostream>
using namespace std;
unsigned long long n1=0,n2=1,n3;
void printFibonacci(long double n){
 if(n>0){
 n3 = n1 + n2;
 n1 = n2;
 n2 = n3;
 cout<<n3<<endl;
 printFibonacci(n-1);
 }
}
int main(){
 int n;
 printf("Enter the number of terms: \n");
 scanf("%d",&n);
 printf("Fibonacci Series:\n");
 //printf("%Lf\n%Lf",0.000000,1.000000);
 printf("\n") ;
 printFibonacci(n);
 return 0;
}
