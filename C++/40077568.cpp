#include <bits/stdc++.h>

constexpr int P = 998244353;

int norm(int x) {
    if (x < P) {
        return x;
    } else {
        return x - P;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::string w;
    std::cin >> w;
    
    std::vector<int> dp[2];
    dp[0] = {1};
    int cur = 0;
    for (int i = 1; i <= n; ++i) {
        cur ^= 1;
        dp[cur].assign(1 << (i / 2), 0);
        for (int s = 0; s < (1 << ((i - 1) / 2)); ++s) {
            int ns = s;
            if (i % 2 == 0) {
                ns |= 1 << ((i / 2) - 1);
            }
            dp[cur][ns] = norm(dp[cur][ns] + dp[!cur][s]);
            for (int j = 1; j <= i / 2; ++j) {
                if (i % j == 0 && w[i / j - 1] == '1' && (ns >> (j - 1) & 1)) {
                    int t = ns & ~(1 << (j - 1));
                    dp[cur][t] = norm(dp[cur][t] + dp[!cur][s]);
                }
            }
        }
    }
    
    std::vector<std::vector<int>> C(n + 1, std::vector<int>(n + 1));
    for (int i = 0; i <= n; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % P;
        }
    }
    std::vector<int> fac(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fac[i] = int64_t(fac[i - 1]) * i % P;
    }
    
    std::vector<int> f(n);
    for (int s = 0; s < (1 << (n / 2)); ++s) {
        int k = n / 2 - __builtin_popcount(s);
        f[k] = (f[k] + int64_t(dp[cur][s]) * fac[n - k]) % P;
    }
    
    for (int i = 0; i < n; ++i) {
        int ans = 0;
        for (int j = i; j < n; ++j) {
            ans = (ans + int64_t(C[j][i]) * ((j - i) % 2 == 0 ? f[j] : P - f[j])) % P;
        }
        std::cout << ans << " \n"[i == n - 1];
    }
    
    return 0;
}