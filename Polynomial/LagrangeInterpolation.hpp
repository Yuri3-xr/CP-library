#pragma once

#include "../Template/Template.hpp"
template <typename T>
T LagrangeInterpolation(const vector<T> &y, long long x) {
    //(0,y[0]),(1,y[1]),...,(N,y[N])
    int N = (int)y.size() - 1;
    if (x <= N) return y[x];
    T ret = 0;
    vector<T> dp(N + 1, 1), pd(N + 1, 1), finv(N + 1, 0);
    T a = x, one = 1;
    finv[N] = T(1);
    for (int i = 1; i <= N; i++) finv[N] *= T(i);
    finv[N] = finv[N].inverse();
    for (int i = N - 1; i >= 0; i--) finv[i] = finv[i + 1] * T(i + 1);
    for (int i = 0; i < N; i++) dp[i + 1] = dp[i] * a, a -= one;
    for (int i = N; i > 0; i--) pd[i - 1] = pd[i] * a, a += one;
    for (int i = 0; i <= N; i++) {
        T tmp = y[i] * dp[i] * pd[i] * finv[i] * finv[N - i];
        ret += ((N - i) & 1) ? -tmp : tmp;
    }
    return ret;
}