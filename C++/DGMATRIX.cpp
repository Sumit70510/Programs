#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<vector<int>> a(n,vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> c(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if ((i + j) % 2 == 0) {
                c[i][j] = a[i - 1][j - 1];
            } else {
                c[i][j] = -a[i - 1][j - 1];
            }
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            c[i][j] += c[i][j - 1];
        }
    }

    for (int j = 1; j <= n; ++j) {
        for (int i = 1; i <= n; ++i) {
            c[i][j] += c[i - 1][j];
        }
    }
    
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            if ((i + j) % 2 == 1) {
                c[i][j] = -c[i][j];
            }
        }
    }
    
    for (int b00 = 0; b00 <= 9; ++b00) {
        const int V = 2 * n + 1;
        vector<vector<int>> dis(V, vector<int>(V, 1e9));
        for (int i = 0; i < V; ++i) {
            dis[i][i] = 0;
        }
        
        for (int i = 1; i <= n; ++i) {
            if (i % 2 == 1) {
                dis[0][i] = 0;
                dis[i][0] = 9;
                dis[0][i + n] = 9;
                dis[i + n][0] = 0;
            } else {
                dis[0][i + n] = 0;
                dis[i + n][0] = 9;
                dis[0][i] = 9;
                dis[i][0] = 0;
            }
        }
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if ((i + j) % 2 == 0) {
                    dis[j + n][i] = 9 + b00 - c[i][j];
                    dis[i][j + n] = c[i][j] - b00;
                } else {
                    dis[j + n][i] = c[i][j] + b00;
                    dis[i][j + n] = 9 - b00 - c[i][j];
                }
            }
        }
      
        for (int k = 0; k < V; ++k) {
            for (int i = 0; i < V; ++i) {
                for (int j = 0; j < V; ++j) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
        bool ok = true;
        for (int i = 0; i < V; ++i) {
            if (dis[i][i] < 0) {
                ok = false;
            }
        }
        if (!ok) {
            continue;
        }
        vector<vector<int>> b(n + 1, vector<int>(n + 1));
        b[0][0] = b00;
        for (int i = 1; i <= n; ++i) {
            if (i % 2 == 1) {
                b[i][0] = -dis[0][i];
                b[0][i] = dis[0][i + n];
            } else {
                b[0][i] = -dis[0][i + n];
                b[i][0] = dis[0][i];
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                b[i][j] = c[i][j];
                if (i % 2 == 0) {
                    b[i][j] += b[0][j];
                } else {
                    b[i][j] -= b[0][j];
                }
                if (j % 2 == 0) {
                    b[i][j] += b[i][0];
                } else {
                    b[i][j] -= b[i][0];
                }
                if ((i + j) % 2 == 0) {
                    b[i][j] -= b00;
                } else {
                    b[i][j] += b00;
                }
            }
        }
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                cout << b[i][j];
            }
            cout << "\n";
        }
        return 0;
    }
    
    assert(false);
}