#pragma once

#include "../Template/Template.hpp"

template <typename T>
std::pair<int, T> GaussElimination(vector<vector<T>> &a, int pivot_end = -1,
                                   bool diagonalize = false) {
    int H = a.size(), W = a[0].size();
    int rank = 0, je = pivot_end;
    if (je == -1) je = W;
    T det = 1;
    for (int j = 0; j < je; j++) {
        int idx = -1;
        for (int i = rank; i < H; i++) {
            if (a[i][j] != T(0)) {
                idx = i;
                break;
            }
        }
        if (idx == -1) {
            det = 0;
            continue;
        }
        if (rank != idx) {
            det = -det;
            swap(a[rank], a[idx]);
        }
        det *= a[rank][j];
        if (diagonalize && a[rank][j] != T(1)) {
            T coeff = a[rank][j].inverse();
            for (int k = j; k < W; k++) a[rank][k] *= coeff;
        }
        int is = diagonalize ? 0 : rank + 1;
        for (int i = is; i < H; i++) {
            if (i == rank) continue;
            if (a[i][j] != T(0)) {
                T coeff = a[i][j] / a[rank][j];
                for (int k = j; k < W; k++) a[i][k] -= a[rank][k] * coeff;
            }
        }
        rank++;
    }
    return make_pair(rank, det);
}