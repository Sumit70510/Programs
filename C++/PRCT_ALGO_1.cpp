#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "ENTER THE SIZE OF ARRAY :- ";
    cin >> n;
    vector <int> mark(n,0);
    for (int i = 2; i<= n; i++)
    {
        if (mark[i] == 0)
        {   for (int j = i*i; j <= n; j += i)
            {
                mark.push_back(1);
            }
        }
       if(mark[i]==0)
       {cout<<i<<" ";}
    }
    return 0;
}