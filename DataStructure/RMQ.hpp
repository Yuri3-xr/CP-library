#pragma once
#include "../Template/Template.hpp"

template <class T, class Cmp = less<T>>
struct RMQ {
    const int n;
    const Cmp cmp;
    vector<vector<T>> a;
    RMQ(const vector<T> &init) : n(init.size()), cmp(Cmp()) {
        int lg = __lg(n);
        a.assign(lg + 1, vector<T>(n));
        for (int j = 0; j <= lg; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                a[j][i] = (j == 0 ? init[i]
                                  : min(a[j - 1][i],
                                        a[j - 1][i + (1 << (j - 1))], cmp));
            }
        }
    }
    T rangeMin(int l, int r) {
        int k = __lg(r - l);
        return min(a[k][l], a[k][r - (1 << k)], cmp);
    }
};