#include <bits/stdc++.h>
#define int long long
#define mid(l, u) ((l+u)/2)
#define lchild(i) (i*2 + 1)
#define rchild(i) (i*2 + 2)
using namespace std;
int b[105][105];
int n;
bool valid(int x){
    return ((x>=0) && (x<=9));
}
int change(int x, int y){
    return (valid(y) - valid(x)); //0 if no change, 1 if good change, -1 if bad change
}
signed main() {
    cin>>n;
    int a[n][n];
    for(int i =0 ;i<n;i++) for(int j = 0;j<n;j++) cin>>a[i][j];
    for(int i = n;i>=0;i--) b[i][n] = b[n][i] = 9;
    queue<pair<int, int>> q;
    for(int i = n-1;i>=0;i--) {
        for (int j = n - 1; j >= 0; j--) {
            b[i][j] = a[i][j] - b[i + 1][j] - b[i][j + 1] - b[i + 1][j + 1];
            if(!valid(b[i][j])) q.push({i, j});
        }
    }
    map<pair<pair<int, int>, pair<int, int>>, bool> mp;
    while(!q.empty()){
        pair<int, int> curr = q.front();
        q.pop();
        int i = curr.first, j = curr.second;
        if(valid(b[i][j])) continue;
        bool row = true;
        int optd = (0 - b[i][j]);
        int optch = -(n+100);
        for(int c = 0;c<10;c++) {
            int d = c - b[i][j];
            int tc = 0;
            for (int x = 0; x <= n; x++){
                int nv = b[x][j] + (pow(-1, abs(i - x))*d);
                tc += change(b[x][j], nv);
            }
            if(tc >= optch && !mp[{{i, j}, {c, true}}]){
                optch = tc;
                optd = d;
                row = true;
            }
            here:
            tc = 0;
            for (int x = 0; x <= n; x++){
                int nv = b[i][x] + (pow(-1, abs(j - x))*d);
                tc += change(b[i][x], nv);
            }
            if(tc >= optch && !mp[{{i, j}, {c, false}}]){
                optch = tc;
                optd = d;
                row = false;
            }
        }
        //assert(optch > 0);
        mp[{{i, j}, {b[i][j] + optd, row}}] = true;
        for(int x = 0;x<=n;x++){
            if(row){
                int nv = b[x][j] + (pow(-1, abs(i - x))*optd);
                if(valid(b[x][j]) && !valid(nv)) q.push({x, j});
                b[x][j] = nv;
            }
            else{
                int nv = b[i][x] + (pow(-1, abs(j - x))*optd);
                if(valid(b[i][x]) && !valid(nv)) q.push({i, x});
                b[i][x] = nv;
            }
        }
    }
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=n;j++){
            cout<<b[i][j];
        }
        cout<<endl;
    }
}