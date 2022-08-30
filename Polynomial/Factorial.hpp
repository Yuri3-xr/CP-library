#pragma once

#include "../Template/Template.hpp"
#include "Poly.hpp"

template <class T>
T factorial(i64 n) {
    /*
        n!
        Time Complexity: O(\sqrt(n)\log(n))
    */
    using poly = Poly<T, 3>;

    if (n <= 1) return T(1);

    i64 v = 1;
    while (v * v < n) v *= 2;
    T iv = T(v).inverse();

    poly G({1, v + 1});
    for (i64 d = 1; d != v; d <<= 1ll) {
        poly G1 = G.shift(T(d) * iv);
        poly G2 = G.shift(T(d * v + v) * iv);
        poly G3 = G.shift(T(d * v + d + v) * iv);
        for (int i = 0; i <= d; i++) G[i] *= G1[i], G2[i] *= G3[i];
        copy(begin(G2.a), end(G2.a) - 1, back_inserter(G.a));
    }

    T res = 1;
    i64 i = 0;
    while (i + v <= n) res *= G[i / v], i += v;
    while (i < n) res *= ++i;

    return res;
}