#pragma once

#include "Prime_Sieve.hpp"

template <class T>
T PNSieve(i64 n, const std::function<T(i64)> G,
          const std::function<T(i64, i64, i64)> f,
          const std::function<T(i64, i64, i64)> g) {
    /*
        \sum_{i=1}^n f(i)
        Find g: g(x) = f(x) when x is prime ,and g is multiplicative
        G(x) is the prifix sum of g.
        Time Complexity: O (max(sqrt(n),n^t
       (\zeta(2*t)*\zeta(3*t))/\zeta(6*t))) n^t for call G(x) ,\zeta is Riemann
       zeta function
    */
    const int sq = sqrt(n) + 10;
    auto prime = prime_sieve(sq);
    std::vector<std::vector<T>> h(prime.size(),
                                  std::vector<T>(std::__lg(n) + 2));
    for (int i = 0; i < int(prime.size()); i++) h[i][0] = T(1);
    T ans = 0;

    auto dfs = [&](auto&& self, i64 x, T y, i64 pos) -> void {
        ans = ans + y * G(n / x);
        if (pos >= int(prime.size())) return;
        if (x > n / prime[pos] / prime[pos]) return;
        for (int w = pos; w < int(prime.size()); w++) {
            if (x > n / prime[w] / prime[w]) return;
            i64 bet = x * prime[w];
            for (i64 j = 1; bet <= n; j++, bet *= prime[w]) {
                if (h[w][j] == T()) {
                    T nowf = f(bet / x, prime[w], j);
                    i64 G = prime[w];
                    for (i64 i = 1; i <= j; i++)
                        nowf = nowf - g(G, prime[w], i) * h[w][j - i],
                        G *= prime[w];
                    h[w][j] = nowf;
                }
                if (h[w][j] != T()) {
                    self(self, bet, h[w][j] * y, w + 1);
                }
            }
        }
    };
    dfs(dfs, 1, 1, 0);
    return ans;
}