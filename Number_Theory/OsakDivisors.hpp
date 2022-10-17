#pragma once

#include "Prime_Sieve.hpp"

template <class T>
vector<T> OsakDivisors(T x) {
    auto primes = prime_sieve(sqrt(x) + 10);

    vector<pair<T, int>> lt;
    for (auto p : primes) {
        if (1LL * p * p > x) break;
        int cnt = 0;
        while (x % p == 0) {
            x /= p;
            cnt++;
        }
        lt.emplace_back(p, cnt);
    }
    if (x > 1) lt.emplace_back(x, 1);
    vector<T> div;
    auto dfs = [&](auto rec, int i, T c) {
        if (i == int(lt.size())) {
            div.push_back(c);
            return;
        }
        for (int j = 0; j <= lt[i].second; j++) {
            rec(rec, i + 1, c);
            c *= lt[i].first;
        }
    };
    dfs(dfs, 0, 1);
    return div;
}