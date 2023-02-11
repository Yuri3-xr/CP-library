#pragma once
#include "../Template/Template.hpp"

template <class T, class Cmp = std::less<T>>
struct RMQ {
    const int n;
    const Cmp cmp;
    std::vector<std::vector<T>> a;
    RMQ(const std::vector<T> &init) : n(init.size()), cmp(Cmp()) {
        int lg = std::__lg(n);
        a.assign(lg + 1, std::vector<T>(n));
        for (int j = 0; j <= lg; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                a[j][i] =
                    (j == 0 ? init[i]
                            : std::min(a[j - 1][i],
                                       a[j - 1][i + (1 << (j - 1))], cmp));
            }
        }
    }
    T rangeMin(int l, int r) {
        int k = std::__lg(r - l);
        return std::min(a[k][l], a[k][r - (1 << k)], cmp);
    }
};