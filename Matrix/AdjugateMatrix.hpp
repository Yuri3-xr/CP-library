#pragma once
#include "GaussElimination.hpp"
#include "LinearEquation.hpp"

template <class T>
vector<vector<T>> Adjugate_Matrix(vector<vector<T>> x) {
    int N = x.size();
    assert(N > 0);
    assert(N == (int)x[0].size());

    vector<vector<T>> m(N, vector<T>(2 * N));
    for (int i = 0; i < N; i++) {
        copy(begin(x[i]), end(x[i]), begin(m[i]));
        m[i][N + i] = 1;
    }
    int rank;
    auto GE = GaussElimination(m, N, true);
    rank = GE.first;
    if (rank <= N - 2) {
        return vector<vector<T>>(N, vector<T>(N, 0));
    }
    if (rank == N) {
        T det = GaussElimination(x).second;
        vector<vector<T>> b(N);
        for (int i = 0; i < N; i++) {
            copy(begin(m[i]) + N, end(m[i]), back_inserter(b[i]));
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                b[i][j] *= det;
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) swap(b[i][j], b[j][i]);
        }
        return b;
    }
    auto xt = x;
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++) swap(xt[i][j], xt[j][i]);

    auto ps = LinearEquation<T>(xt, vector<T>(N, 0));
    auto qs = LinearEquation<T>(x, vector<T>(N, 0));
    vector<T> p, q;
    int r(0), c(0);
    for (int i = 0; i < ps.size(); i++) {
        for (int j = 0; j < N; j++) {
            if (ps[i][j].get() != 0) {
                p = ps[i];
                r = j;
            }
        }
    }
    for (int i = 0; i < qs.size(); i++) {
        for (int j = 0; j < N; j++) {
            if (qs[i][j].get() != 0) {
                q = qs[i];
                c = j;
            }
        }
    }

    assert(p[r].get() != 0 && q[c].get() != 0);

    vector<vector<T>> b(N, vector<T>(N));
    vector<vector<T>> t;
    for (int i = 0; i < N; i++) {
        if (i == r) continue;
        vector<T> res;
        for (int j = 0; j < N; j++)
            if (j != c) res.push_back(x[i][j]);
        t.push_back(res);
    }

    auto tdet = GaussElimination(t).second;

    b[r][c] = ((r + c) & 1) ? -tdet : tdet;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            b[i][j] = p[i] * q[j] / (p[r] * q[c]) * b[r][c];
        }

    return b;
}