#pragma once

#include "../Template/Template.hpp"

inline i64 binary_gcd(i64 a, i64 b) {
    if (a == 0 || b == 0) return a + b;
    char n = __builtin_ctzll(a);
    char m = __builtin_ctzll(b);
    a >>= n;
    b >>= m;
    n = std::min(n, m);
    while (a != b) {
        i64 d = a - b;
        char s = __builtin_ctzll(d);
        bool f = a > b;
        b = f ? b : a;
        a = (f ? d : -d) >> s;
    }
    return a << n;
}