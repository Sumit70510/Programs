#include<bits/stdc++.h>
using namespace std;

int main()
 { 
    int t;
    cin>>t;
    while(t--)
     {
     int n;
     cin >> n;
      vector<int> p(n + 1);
      for (int i = 1; i <= n; ++i) {
         if (i % 2 == 0) {
              p[i] = i / 2;
            } else {
                p[i] = n / 2 + 1 + i / 2;
            }
        }
        for(int i = 1; i <= n; ++i) {
            cout << p[i] << " ";
         }
        cout<<endl;
       } 
    return 0;
 }