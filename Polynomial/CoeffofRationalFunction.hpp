#pragma once

#include "../Template/Template.hpp"
#include "Poly.hpp"

template <class Z, int rt>
Z CoeffofRationalFunction(Poly<Z, rt> P, Poly<Z, rt> Q, i64 k) {
    Z ret = 0;
    if (P.size() >= Q.size()) {
        auto R = P / Q;
        P -= R * Q;
        while (P.size() && P.a.back() == Z(0)) P.a.pop_back();
        if (k < int(R.size())) ret += R[k];
    }
    if (P.a.empty()) return ret;
    P.a.resize(int(Q.size()) - 1);

    while (k > 0) {
        Poly<Z, rt> Q2(Q.a);
        for (int i = 1; i < int(Q2.size()); i += 2) Q2[i] = -Q2[i];
        auto sub = [&](const Poly<Z, rt> &as, bool odd) {
            Poly<Z, rt> bs((as.size() + !odd) / 2, 0);
            for (int i = odd; i < (int)as.size(); i += 2) bs[i >> 1] = as[i];
            return bs;
        };
        P = sub(P * Q2, k & 1);
        Q = sub(Q * Q2, 0);
        k /= 2;
    }

    return ret + P[0];
}
