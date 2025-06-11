#include<bits/stdc++.h>
using namespace std;
int main()
{
int m, n, c, d, first[10][10], second[10][10], add[10][10];
 printf("Enter the number of rows and columns of matrix\n");
 scanf("%d%d", &m, &n);
 printf("Enter the elements of first matrix\n");
 for (c = 0; c < m; c++)
 for (d = 0; d < n; d++)
 scanf("%d", &first[c][d]);
 printf("Enter the elements of second matrix\n");
 for (c = 0; c < m; c++)
 for (d = 0 ; d < n; d++)
 scanf("%d", &second[c][d]);

 printf("add of entered matrices:-\n");

 for (c = 0; c < m; c++) {
 for (d = 0 ; d < n; d++) {
 add[c][d] = first[c][d] + second[c][d];
 printf("%d\t", add[c][d]);
 }
 printf("\n");
 }
 return 0;
}
