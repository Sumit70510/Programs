#include <bits/stdc++.h>

constexpr int P = 998244353;

std::vector<int> inv;

int power(int a, int b) {
    int res = 1;
    for (; b > 0; b /= 2, a = int64_t(a) * a % P) {
        if (b % 2 == 1) {
            res = int64_t(res) * a % P;
        }
    }
    return res;
}

int norm(int x) {
    if (x < P) {
        return x;
    } else {
        return x - P;
    }
}

void fmt(std::vector<std::vector<int>> &a) {
    int n = std::__lg(a.size());
    for (int i = 1; i < (1 << n); i *= 2) {
        for (int j = 0; j < (1 << n); j += 2 * i) {
            for (int k = 0; k < i; ++k) {
                for (int l = 0; l <= n; ++l) {
                    a[i + j + k][l] = norm(a[i + j + k][l] + a[j + k][l]);
                }
            }
        }
    }
}

int getExp(const std::vector<int> &f) {
    int n = std::__lg(f.size());
    std::vector<std::vector<int>> a(1 << n, std::vector<int>(n + 1));
    for (int s = 0; s < (1 << n); ++s) {
        a[s][__builtin_popcount(s)] = f[s];
    }
    fmt(a);
    int ans = 0;
    for (int s = 0; s < (1 << n); ++s) {
        std::vector<int> g(n + 1);
        g[0] = 1;
        for (int i = 0; i < n; ++i) {
            int res = 0;
            for (int j = 0; j <= i; ++j) {
                res = (res + int64_t(a[s][j + 1]) * (j + 1) % P * g[i - j]) % P;
            }
            g[i + 1] = int64_t(res) * inv[i + 1] % P;
        }
        ans = norm(ans + (__builtin_parity(((1 << n) - 1) ^ s) ? P - g[n] : g[n]));
    }
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    inv.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        inv[i] = power(i, P - 2);
    }
    
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    
    std::vector<int> coef(n + 1);
    coef[1] = 1;
    for (int i = 2; i <= n; ++i) {
        coef[i] = int64_t(P - coef[i - 1]) * (i - 1) % P;
    }
    
    std::vector<int> f(1 << n), g(1 << n);
    for (int s = 1; s < (1 << n); ++s) {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (s >> i & 1) {
                sum += a[i];
            }
        }
        f[s] = int64_t(coef[__builtin_popcount(s)]) * 239 % P;
        g[s] = int64_t(coef[__builtin_popcount(s)]) * (sum % 239 == 0 ? 239 : 0) % P;
    }
    int ans = getExp(f), x = getExp(g);
    
    ans = (int64_t(ans - x + P) * power(239, P - 2) + x) % P;
    std::cout << ans << "\n";
    
    return 0;
}