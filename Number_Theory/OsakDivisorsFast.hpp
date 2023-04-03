#pragma once

#include "Factorization.hpp"

template <class T>
std::vector<T> OsakDivisorsFast(T x) {
    auto lt = Factor::factorSortedList<T>(x);

    std::vector<T> div;
    auto dfs = [&](auto&& rec, int i, T c) {
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