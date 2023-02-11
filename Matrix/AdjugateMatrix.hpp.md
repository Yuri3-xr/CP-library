---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Matrix/GaussElimination.hpp
    title: Matrix/GaussElimination.hpp
  - icon: ':warning:'
    path: Matrix/LinearEquation.hpp
    title: Matrix/LinearEquation.hpp
  - icon: ':question:'
    path: Template/Template.hpp
    title: Template/Template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Matrix/GaussElimination.hpp\"\n\n#line 2 \"Template/Template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\nusing i64 = std::int64_t;\n#line 4 \"Matrix/GaussElimination.hpp\"\
    \n\ntemplate <typename T>\nstd::pair<int, T> GaussElimination(std::vector<std::vector<T>>\
    \ &a,\n                                   int pivot_end = -1,\n              \
    \                     bool diagonalize = false) {\n    int H = a.size(), W = a[0].size();\n\
    \    int rank = 0, je = pivot_end;\n    if (je == -1) je = W;\n    T det = 1;\n\
    \    for (int j = 0; j < je; j++) {\n        int idx = -1;\n        for (int i\
    \ = rank; i < H; i++) {\n            if (a[i][j] != T(0)) {\n                idx\
    \ = i;\n                break;\n            }\n        }\n        if (idx == -1)\
    \ {\n            det = 0;\n            continue;\n        }\n        if (rank\
    \ != idx) {\n            det = -det;\n            std::swap(a[rank], a[idx]);\n\
    \        }\n        det *= a[rank][j];\n        if (diagonalize && a[rank][j]\
    \ != T(1)) {\n            T coeff = a[rank][j].inverse();\n            for (int\
    \ k = j; k < W; k++) a[rank][k] *= coeff;\n        }\n        int is = diagonalize\
    \ ? 0 : rank + 1;\n        for (int i = is; i < H; i++) {\n            if (i ==\
    \ rank) continue;\n            if (a[i][j] != T(0)) {\n                T coeff\
    \ = a[i][j] / a[rank][j];\n                for (int k = j; k < W; k++) a[i][k]\
    \ -= a[rank][k] * coeff;\n            }\n        }\n        rank++;\n    }\n \
    \   return make_pair(rank, det);\n}\n#line 3 \"Matrix/LinearEquation.hpp\"\n\n\
    template <typename T>\nstd::vector<std::vector<T>> LinearEquation(std::vector<std::vector<T>>\
    \ a,\n                                           std::vector<T> b) {\n    int\
    \ H = a.size(), W = a[0].size();\n    for (int i = 0; i < H; i++) a[i].push_back(b[i]);\n\
    \    auto p = GaussElimination(a, W, true);\n    int rank = p.first;\n\n    for\
    \ (int i = rank; i < H; ++i) {\n        if (a[i][W] != 0) return std::vector<std::vector<T>>{};\n\
    \    }\n\n    std::vector<std::vector<T>> res(1, std::vector<T>(W));\n    std::vector<int>\
    \ pivot(W, -1);\n    for (int i = 0, j = 0; i < rank; ++i) {\n        while (a[i][j]\
    \ == 0) ++j;\n        res[0][j] = a[i][W], pivot[j] = i;\n    }\n    for (int\
    \ j = 0; j < W; ++j) {\n        if (pivot[j] == -1) {\n            std::vector<T>\
    \ x(W);\n            x[j] = 1;\n            for (int k = 0; k < j; ++k) {\n  \
    \              if (pivot[k] != -1) x[k] = -a[pivot[k]][j];\n            }\n  \
    \          res.push_back(x);\n        }\n    }\n    return res;\n}\n#line 4 \"\
    Matrix/AdjugateMatrix.hpp\"\n\ntemplate <class T>\nstd::vector<std::vector<T>>\
    \ Adjugate_Matrix(std::vector<std::vector<T>> x) {\n    int N = x.size();\n  \
    \  assert(N > 0);\n    assert(N == (int)x[0].size());\n\n    std::vector<std::vector<T>>\
    \ m(N, std::vector<T>(2 * N));\n    for (int i = 0; i < N; i++) {\n        copy(begin(x[i]),\
    \ end(x[i]), begin(m[i]));\n        m[i][N + i] = 1;\n    }\n    int rank;\n \
    \   auto GE = GaussElimination(m, N, true);\n    rank = GE.first;\n    if (rank\
    \ <= N - 2) {\n        return std::vector<std::vector<T>>(N, std::vector<T>(N,\
    \ 0));\n    }\n    if (rank == N) {\n        T det = GaussElimination(x).second;\n\
    \        std::vector<std::vector<T>> b(N);\n        for (int i = 0; i < N; i++)\
    \ {\n            copy(begin(m[i]) + N, end(m[i]), back_inserter(b[i]));\n    \
    \    }\n        for (int i = 0; i < N; i++) {\n            for (int j = 0; j <\
    \ N; j++) {\n                b[i][j] *= det;\n            }\n        }\n     \
    \   for (int i = 0; i < N; i++) {\n            for (int j = i + 1; j < N; j++)\
    \ std::swap(b[i][j], b[j][i]);\n        }\n        return b;\n    }\n    auto\
    \ xt = x;\n    for (int i = 0; i < N; i++)\n        for (int j = i + 1; j < N;\
    \ j++) std::swap(xt[i][j], xt[j][i]);\n\n    auto ps = LinearEquation<T>(xt, std::vector<T>(N,\
    \ 0));\n    auto qs = LinearEquation<T>(x, std::vector<T>(N, 0));\n    std::vector<T>\
    \ p, q;\n    int r(0), c(0);\n    for (int i = 0; i < ps.size(); i++) {\n    \
    \    for (int j = 0; j < N; j++) {\n            if (ps[i][j].get() != 0) {\n \
    \               p = ps[i];\n                r = j;\n            }\n        }\n\
    \    }\n    for (int i = 0; i < qs.size(); i++) {\n        for (int j = 0; j <\
    \ N; j++) {\n            if (qs[i][j].get() != 0) {\n                q = qs[i];\n\
    \                c = j;\n            }\n        }\n    }\n\n    assert(p[r].get()\
    \ != 0 && q[c].get() != 0);\n\n    std::vector<std::vector<T>> b(N, std::vector<T>(N));\n\
    \    std::vector<std::vector<T>> t;\n    for (int i = 0; i < N; i++) {\n     \
    \   if (i == r) continue;\n        std::vector<T> res;\n        for (int j = 0;\
    \ j < N; j++)\n            if (j != c) res.push_back(x[i][j]);\n        t.push_back(res);\n\
    \    }\n\n    auto tdet = GaussElimination(t).second;\n\n    b[r][c] = ((r + c)\
    \ & 1) ? -tdet : tdet;\n    for (int i = 0; i < N; i++)\n        for (int j =\
    \ 0; j < N; j++) {\n            b[i][j] = p[i] * q[j] / (p[r] * q[c]) * b[r][c];\n\
    \        }\n\n    return b;\n}\n"
  code: "#pragma once\n#include \"GaussElimination.hpp\"\n#include \"LinearEquation.hpp\"\
    \n\ntemplate <class T>\nstd::vector<std::vector<T>> Adjugate_Matrix(std::vector<std::vector<T>>\
    \ x) {\n    int N = x.size();\n    assert(N > 0);\n    assert(N == (int)x[0].size());\n\
    \n    std::vector<std::vector<T>> m(N, std::vector<T>(2 * N));\n    for (int i\
    \ = 0; i < N; i++) {\n        copy(begin(x[i]), end(x[i]), begin(m[i]));\n   \
    \     m[i][N + i] = 1;\n    }\n    int rank;\n    auto GE = GaussElimination(m,\
    \ N, true);\n    rank = GE.first;\n    if (rank <= N - 2) {\n        return std::vector<std::vector<T>>(N,\
    \ std::vector<T>(N, 0));\n    }\n    if (rank == N) {\n        T det = GaussElimination(x).second;\n\
    \        std::vector<std::vector<T>> b(N);\n        for (int i = 0; i < N; i++)\
    \ {\n            copy(begin(m[i]) + N, end(m[i]), back_inserter(b[i]));\n    \
    \    }\n        for (int i = 0; i < N; i++) {\n            for (int j = 0; j <\
    \ N; j++) {\n                b[i][j] *= det;\n            }\n        }\n     \
    \   for (int i = 0; i < N; i++) {\n            for (int j = i + 1; j < N; j++)\
    \ std::swap(b[i][j], b[j][i]);\n        }\n        return b;\n    }\n    auto\
    \ xt = x;\n    for (int i = 0; i < N; i++)\n        for (int j = i + 1; j < N;\
    \ j++) std::swap(xt[i][j], xt[j][i]);\n\n    auto ps = LinearEquation<T>(xt, std::vector<T>(N,\
    \ 0));\n    auto qs = LinearEquation<T>(x, std::vector<T>(N, 0));\n    std::vector<T>\
    \ p, q;\n    int r(0), c(0);\n    for (int i = 0; i < ps.size(); i++) {\n    \
    \    for (int j = 0; j < N; j++) {\n            if (ps[i][j].get() != 0) {\n \
    \               p = ps[i];\n                r = j;\n            }\n        }\n\
    \    }\n    for (int i = 0; i < qs.size(); i++) {\n        for (int j = 0; j <\
    \ N; j++) {\n            if (qs[i][j].get() != 0) {\n                q = qs[i];\n\
    \                c = j;\n            }\n        }\n    }\n\n    assert(p[r].get()\
    \ != 0 && q[c].get() != 0);\n\n    std::vector<std::vector<T>> b(N, std::vector<T>(N));\n\
    \    std::vector<std::vector<T>> t;\n    for (int i = 0; i < N; i++) {\n     \
    \   if (i == r) continue;\n        std::vector<T> res;\n        for (int j = 0;\
    \ j < N; j++)\n            if (j != c) res.push_back(x[i][j]);\n        t.push_back(res);\n\
    \    }\n\n    auto tdet = GaussElimination(t).second;\n\n    b[r][c] = ((r + c)\
    \ & 1) ? -tdet : tdet;\n    for (int i = 0; i < N; i++)\n        for (int j =\
    \ 0; j < N; j++) {\n            b[i][j] = p[i] * q[j] / (p[r] * q[c]) * b[r][c];\n\
    \        }\n\n    return b;\n}"
  dependsOn:
  - Matrix/GaussElimination.hpp
  - Template/Template.hpp
  - Matrix/LinearEquation.hpp
  isVerificationFile: false
  path: Matrix/AdjugateMatrix.hpp
  requiredBy: []
  timestamp: '2023-02-11 22:28:05+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Matrix/AdjugateMatrix.hpp
layout: document
redirect_from:
- /library/Matrix/AdjugateMatrix.hpp
- /library/Matrix/AdjugateMatrix.hpp.html
title: Matrix/AdjugateMatrix.hpp
---
