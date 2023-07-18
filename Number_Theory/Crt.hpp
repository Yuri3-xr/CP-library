#pragma once

#include "../Template/Template.hpp"

template <typename T>
T inv_mod(T x, T m) {
    assert(1 <= m);

    T b = m - 2;
    T res = 1;
    for (; b; b /= 2, x = 1LL * x * x % m) {
        if (b % 2) {
            res = 1LL * res * x % m;
        }
    }
    return res;
}

std::pair<long long, long long> inv_gcd(i64 a, i64 b) {
    a = a % b;
    if (a == 0) return std::make_pair(b, 0LL);

    i64 s = b, t = a;
    i64 m0 = 0, m1 = 1;
    while (t) {
        i64 u = s / t;
        s -= t * u;
        m0 -= m1 * u;
        std::swap(s, t);
        std::swap(m0, m1);
    }

    if (m0 < 0) m0 += b / s;
    return std::make_pair(s, m0);
}
// (rem, mod)
std::pair<i64, i64> crt(const std::vector<i64>& r, const std::vector<i64>& m) {
    assert(r.size() == m.size());
    const int n = r.size();
    i64 r0 = 0, m0 = 1;
    for (int i = 0; i < n; ++i) {
        assert(1 <= m[i]);
        i64 r1 = r[i] % m[i], m1 = m[i];
        if (m0 < m1) {
            std::swap(r0, r1);
            std::swap(m0, m1);
        }
        if (m0 % m1 == 0) {
            if (r0 % m1 != r1) return std::make_pair(0LL, 0LL);
            continue;
        }

        i64 g, im;
        std::tie(g, im) = inv_gcd(m0, m1);
        i64 u1 = m1 / g;
        if ((r1 - r0) % g) return std::make_pair(0LL, 0LL);
        i64 x = (r1 - r0) / g % u1 * im % u1;

        r0 += x * m0;
        m0 *= u1;
        if (r0 < 0) r0 += m0;
    }
    return std::make_pair(r0, m0);
}
