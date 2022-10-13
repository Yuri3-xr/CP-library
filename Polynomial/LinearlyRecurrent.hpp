#pragma once

#include "CoeffofRationalFunction.hpp"

template <class Z, int rt>
Z LinearlyRecurrent(const Poly<Z, rt> &a, Poly<Z, rt> c, i64 k) {
    /*
        a_n=\sum_{d=1^t} c_d * a_{n-d}
        give a_0,a_1,...,a_{t-1}
        c_1,c_2,...,c_t[but store at cp[0,...,t-1]]
        solev a_k
        TC: O(t\logt\logk)
    */
    assert(a.size() == c.size());
    c = Poly<Z, rt>{1} - c.mulxk(1);
    return CoeffofRationalFunction<Z, rt>((a * c).modxk(a.size()), c, k);
}