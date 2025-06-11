#include <bits/stdc++.h>

constexpr int P = 998244353;

std::mt19937 gen(std::chrono::steady_clock::now().time_since_epoch().count());

int power(int a, int b, int mod) {
    int res = 1;
    for (; b > 0; b /= 2, a = int64_t(a) * a % mod) {
        if (b % 2 == 1) {
            res = int64_t(res) * a % mod;
        }
    }
    return res;
}

int w, _mod;
struct F { int x, y; };
F operator*(const F &u, const F &v) {
    return { int((int64_t(u.x) * v.x + int64_t(u.y) * v.y % _mod * w) % _mod),
        int((int64_t(u.x) * v.y + int64_t(u.y) * v.x) % _mod) };
}
F power(F a, int b) {
    F res{1, 0};
    for (; b > 0; b /= 2, a = a * a) {
        if (b % 2 == 1) {
            res = res * a;
        }
    }
    return res;
}

int sqrt(int n, int mod) {
    _mod = mod;
    int a = gen() % mod;
    while (power((int64_t(a) * a - n + mod) % mod, (mod - 1) / 2, mod) == 1) {
        a = gen() % mod;
    }
    w = (int64_t(a) * a - n + mod) % mod;
    return power(F{a, 1}, (mod + 1) / 2).x;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n, mod;
        std::cin >> n >> mod;
        std::vector<int> p(n, -1);
        for (int i = 1; i < n; ++i) {
            std::cin >> p[i];
            --p[i];
        }
        std::vector<int> c(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> c[i];
        }
        for (int i = n - 1; i > 0; --i) {
            c[p[i]] = (c[p[i]] + c[i]) % mod;
        }
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            if (c[i] == 0) {
                continue;
            }
            if (power(c[i], (mod - 1) / 2, mod) != 1) {
                ans = 0;
                break;
            }
            c[i] = sqrt(c[i], mod);
            ans = 2 * ans % P;
        }
        if (ans == 0) {
            std::cout << 0 << "\n";
            std::cout << -1 << "\n";
            continue;
        }
        std::cout << ans << "\n";
        for (int i = 1; i < n; ++i) {
            c[p[i]] = (c[p[i]] - c[i] + mod) % mod;
        }
        for (int i = 0; i < n; ++i) {
            std::cout << c[i] << " \n"[i == n - 1];
        }
    }
    
    return 0;
}