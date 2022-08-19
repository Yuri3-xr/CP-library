---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Matrix/Adjugate_matrix.hpp
    title: Matrix/Adjugate_matrix.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Matrix/GaussElimination.hpp\"\n\n#include <../Template/Template.hpp>\n\
    \ntemplate <typename T>\nstd::pair<int, T> GaussElimination(vector<vector<T>>\
    \ &a, int pivot_end = -1,\n                                   bool diagonalize\
    \ = false) {\n    int H = a.size(), W = a[0].size();\n    int rank = 0, je = pivot_end;\n\
    \    if (je == -1) je = W;\n    T det = 1;\n    for (int j = 0; j < je; j++) {\n\
    \        int idx = -1;\n        for (int i = rank; i < H; i++) {\n           \
    \ if (a[i][j] != T(0)) {\n                idx = i;\n                break;\n \
    \           }\n        }\n        if (idx == -1) {\n            det = 0;\n   \
    \         continue;\n        }\n        if (rank != idx) {\n            det =\
    \ -det;\n            swap(a[rank], a[idx]);\n        }\n        det *= a[rank][j];\n\
    \        if (diagonalize && a[rank][j] != T(1)) {\n            T coeff = a[rank][j].inverse();\n\
    \            for (int k = j; k < W; k++) a[rank][k] *= coeff;\n        }\n   \
    \     int is = diagonalize ? 0 : rank + 1;\n        for (int i = is; i < H; i++)\
    \ {\n            if (i == rank) continue;\n            if (a[i][j] != T(0)) {\n\
    \                T coeff = a[i][j] / a[rank][j];\n                for (int k =\
    \ j; k < W; k++) a[i][k] -= a[rank][k] * coeff;\n            }\n        }\n  \
    \      rank++;\n    }\n    return make_pair(rank, det);\n}\n"
  code: "#pragma once\n\n#include <../Template/Template.hpp>\n\ntemplate <typename\
    \ T>\nstd::pair<int, T> GaussElimination(vector<vector<T>> &a, int pivot_end =\
    \ -1,\n                                   bool diagonalize = false) {\n    int\
    \ H = a.size(), W = a[0].size();\n    int rank = 0, je = pivot_end;\n    if (je\
    \ == -1) je = W;\n    T det = 1;\n    for (int j = 0; j < je; j++) {\n       \
    \ int idx = -1;\n        for (int i = rank; i < H; i++) {\n            if (a[i][j]\
    \ != T(0)) {\n                idx = i;\n                break;\n            }\n\
    \        }\n        if (idx == -1) {\n            det = 0;\n            continue;\n\
    \        }\n        if (rank != idx) {\n            det = -det;\n            swap(a[rank],\
    \ a[idx]);\n        }\n        det *= a[rank][j];\n        if (diagonalize &&\
    \ a[rank][j] != T(1)) {\n            T coeff = a[rank][j].inverse();\n       \
    \     for (int k = j; k < W; k++) a[rank][k] *= coeff;\n        }\n        int\
    \ is = diagonalize ? 0 : rank + 1;\n        for (int i = is; i < H; i++) {\n \
    \           if (i == rank) continue;\n            if (a[i][j] != T(0)) {\n   \
    \             T coeff = a[i][j] / a[rank][j];\n                for (int k = j;\
    \ k < W; k++) a[i][k] -= a[rank][k] * coeff;\n            }\n        }\n     \
    \   rank++;\n    }\n    return make_pair(rank, det);\n}"
  dependsOn: []
  isVerificationFile: false
  path: Matrix/GaussElimination.hpp
  requiredBy:
  - Matrix/Adjugate_matrix.hpp
  timestamp: '2022-08-20 01:45:54+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Matrix/GaussElimination.hpp
layout: document
redirect_from:
- /library/Matrix/GaussElimination.hpp
- /library/Matrix/GaussElimination.hpp.html
title: Matrix/GaussElimination.hpp
---
