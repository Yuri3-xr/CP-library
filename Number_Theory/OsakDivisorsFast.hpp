#pragma once

#include "Factorization.hpp"

template <class T>
vector<T> OsakDivisorsFast(T x) {
    auto fac = factorization<i64>(x);
    sort(fac.begin(), fac.end());
    vector<pair<T, int>> lt;
    for (int i = 0, j; i < int(fac.size()); i = j) {
        j = i;
        while (fac[j] == fac[i] && j < int(fac.size())) j++;
        lt.emplace_back(fac[i], j - i);
    }
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