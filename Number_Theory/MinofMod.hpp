#pragma once

#include "../Template/Template.hpp"

template <typename T, typename U>
T ceil(T x, U y) {
    return (x > 0 ? (x + y - 1) / y : x / y);
}
template <class T>
std::pair<std::vector<T>, std::vector<T>> min_of_linear_segments(T a, T b,
                                                                 T mod) {
    assert(0 <= a && a < mod);
    assert(0 <= b && b < mod);
    std::vector<T> X = {0};
    std::vector<T> DX;
    T g = std::gcd(a, mod);
    a /= g, b /= g, mod /= g;
    T p = 0, q = 1, r = 1, s = 1;
    T det_l = mod - a, det_r = a;
    T x = 0, y = b;

    while (y) {
        T k = det_r / det_l;
        det_r %= det_l;
        if (det_r == 0) {
            --k;
            det_r = det_l;
        }
        r += k * p;
        s += k * q;
        while (1) {
            T k = std::max<T>(0, ceil(det_l - y, det_r));
            if (det_l - k * det_r <= 0) break;
            det_l -= k * det_r;
            p += k * r;
            q += k * s;
            k = y / det_l;
            y -= k * det_l;
            x += q * k;
            X.emplace_back(x);
            DX.emplace_back(q);
        }
        k = det_l / det_r;
        det_l -= k * det_r;
        p += k * r;
        q += k * s;
        assert(std::min({p, q, r, s}) >= 0);
    }
    return {X, DX};
}
// min_{x in [L, R)} (ax+b mod MOD)
template <class T>
std::pair<T, T> min_of_linear(T L, T R, T a, T b, T mod) {
    // return [x,fx]
    T n = R - L;
    b = (b + a * L) % mod;
    if (b < 0) b += mod;
    auto [X, DX] = min_of_linear_segments<T>(a, b, mod);
    T x = 0;
    for (T i = 0; i < int(X.size()) - 1; ++i) {
        T xl = X[i], xr = X[i + 1];
        if (xr < n) {
            x = xr;
            continue;
        }
        x = xl + (n - 1 - x) / DX[i] * DX[i];
        break;
    }
    T y = (T(a) * x + b) % mod;
    return {L + x, y};
}