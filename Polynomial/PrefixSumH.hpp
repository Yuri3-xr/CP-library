#pragma once

#include "../Template/Template.hpp"
#include "Poly.hpp"
template <class T>
T PrefixSumH(i64 n) {
    /*
        \sum_{i=0}^n frac{1}{i}
        Time Complexity: O(\sqrt(n)\log n)
    */
    assert(n != 0);
    if (n == 1) return 1;
    using poly = Poly<T, 3>;
    i64 v = 1;
    while (v * v < n) v *= 2;
    T iv = T(v).inverse();
    std::array<poly, 3> G = {poly({1, v + 1}), poly({1, 1}), poly({1, v + 1})};
    for (i64 d = 1; d != v; d <<= 1ll) {
        std::array<poly, 3> G1, G2, G3;
        for (int i = 0; i < 3; i++) {
            G1[i] = G[i].shift(T(d) * iv);
            G2[i] = G[i].shift(T(d * v + v) * iv);
            G3[i] = G[i].shift(T(d * v + d + v) * iv);
        }

        for (int t = 0; t <= d; t++) {
            G[1][t] = G1[1][t] * G[0][t] + G[1][t] * G1[2][t];
            G2[1][t] = G2[1][t] * G3[2][t] + G3[1][t] * G2[0][t];
            G[0][t] *= G1[0][t];
            G[2][t] *= G1[2][t];
            G2[0][t] *= G3[0][t];
            G2[2][t] *= G3[2][t];
        }
        for (int i = 0; i < 3; i++) {
            copy(begin(G2[i].a), end(G2[i].a) - 1, back_inserter(G[i].a));
        }
    }
    using M = std::array<std::array<T, 2>, 2>;

    M res = {std::array<T, 2>({1, 0}), std::array<T, 2>({0, 1})};
    auto M_multiply = [&](const M &a, const M &b) -> M {
        M res;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++) res[i][j] += a[i][k] * b[k][j];
        return res;
    };
    i64 i = 0;
    while (i + v <= n) {
        M now = {std::array<T, 2>({G[0][i / v], 0}),
                 std::array<T, 2>({G[1][i / v], G[2][i / v]})};
        res = M_multiply(now, res);
        i += v;
    }
    while (i < n) {
        M now = {std::array<T, 2>({i + 1, 0}), std::array<T, 2>({1, i + 1})};
        i++;
        res = M_multiply(now, res);
    }
    return res[1][0] / res[0][0];
}
