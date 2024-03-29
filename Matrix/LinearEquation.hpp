#pragma once
#include "../Template/Template.hpp"

template <typename T>
std::vector<std::vector<T>> LinearEquation(std::vector<std::vector<T>> a,
                                           std::vector<T> b) {
    int H = a.size(), W = a[0].size();
    for (int i = 0; i < H; i++) a[i].push_back(b[i]);
    auto p = GaussElimination(a, W, true);
    int rank = p.first;

    for (int i = rank; i < H; ++i) {
        if (a[i][W] != 0) return std::vector<std::vector<T>>{};
    }

    std::vector<std::vector<T>> res(1, std::vector<T>(W));
    std::vector<int> pivot(W, -1);
    for (int i = 0, j = 0; i < rank; ++i) {
        while (a[i][j] == 0) ++j;
        res[0][j] = a[i][W], pivot[j] = i;
    }
    for (int j = 0; j < W; ++j) {
        if (pivot[j] == -1) {
            std::vector<T> x(W);
            x[j] = 1;
            for (int k = 0; k < j; ++k) {
                if (pivot[k] != -1) x[k] = -a[pivot[k]][j];
            }
            res.push_back(x);
        }
    }
    return res;
}