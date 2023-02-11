#pragma once

#include "Prime_Sieve.hpp"

template <class T>
std::vector<T> mf_sieve(int n, std::function<T(i64, i64, i64)> f) {
    /*
        ##pragma f is a multiplicative-function
        f(n,p,c) <-> n=p^c
    */
    std::vector<T> ans(n + 1, T());
    std::vector<int> ps = prime_sieve(n);
    int p(ps.size());

    std::function<void(int, i64, T)> dfs = [&](int i, i64 x, T y) {
        ans[x] = y;
        if (y == T()) return;
        for (int j = i + 1; j < p; j++) {
            i64 nx = x * ps[j];
            i64 dx = ps[j];
            if (nx > n) break;
            for (int c = 1; nx <= n; nx *= ps[j], dx *= ps[j], ++c)
                dfs(j, nx, y * f(dx, ps[j], c));
        }
    };
    ans[1] = 1;
    dfs(-1, 1, 1);
    return ans;
};