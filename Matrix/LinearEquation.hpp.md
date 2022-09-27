---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Template/Template.hpp
    title: Template/Template.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Matrix/AdjugateMatrix.hpp
    title: Matrix/AdjugateMatrix.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Template/Template.hpp\"\n\nusing namespace std;\n\n#include\
    \ <bits/stdc++.h>\n\nusing i64 = long long;\nusing VI = vector<int>;\nusing pii\
    \ = pair<int, int>;\n#line 3 \"Matrix/LinearEquation.hpp\"\n\ntemplate <typename\
    \ T>\nvector<vector<T>> LinearEquation(vector<vector<T>> a, vector<T> b) {\n \
    \   int H = a.size(), W = a[0].size();\n    for (int i = 0; i < H; i++) a[i].push_back(b[i]);\n\
    \    auto p = GaussElimination(a, W, true);\n    int rank = p.first;\n\n    for\
    \ (int i = rank; i < H; ++i) {\n        if (a[i][W] != 0) return vector<vector<T>>{};\n\
    \    }\n\n    vector<vector<T>> res(1, vector<T>(W));\n    vector<int> pivot(W,\
    \ -1);\n    for (int i = 0, j = 0; i < rank; ++i) {\n        while (a[i][j] ==\
    \ 0) ++j;\n        res[0][j] = a[i][W], pivot[j] = i;\n    }\n    for (int j =\
    \ 0; j < W; ++j) {\n        if (pivot[j] == -1) {\n            vector<T> x(W);\n\
    \            x[j] = 1;\n            for (int k = 0; k < j; ++k) {\n          \
    \      if (pivot[k] != -1) x[k] = -a[pivot[k]][j];\n            }\n          \
    \  res.push_back(x);\n        }\n    }\n    return res;\n}\n"
  code: "#pragma once\n#include \"../Template/Template.hpp\"\n\ntemplate <typename\
    \ T>\nvector<vector<T>> LinearEquation(vector<vector<T>> a, vector<T> b) {\n \
    \   int H = a.size(), W = a[0].size();\n    for (int i = 0; i < H; i++) a[i].push_back(b[i]);\n\
    \    auto p = GaussElimination(a, W, true);\n    int rank = p.first;\n\n    for\
    \ (int i = rank; i < H; ++i) {\n        if (a[i][W] != 0) return vector<vector<T>>{};\n\
    \    }\n\n    vector<vector<T>> res(1, vector<T>(W));\n    vector<int> pivot(W,\
    \ -1);\n    for (int i = 0, j = 0; i < rank; ++i) {\n        while (a[i][j] ==\
    \ 0) ++j;\n        res[0][j] = a[i][W], pivot[j] = i;\n    }\n    for (int j =\
    \ 0; j < W; ++j) {\n        if (pivot[j] == -1) {\n            vector<T> x(W);\n\
    \            x[j] = 1;\n            for (int k = 0; k < j; ++k) {\n          \
    \      if (pivot[k] != -1) x[k] = -a[pivot[k]][j];\n            }\n          \
    \  res.push_back(x);\n        }\n    }\n    return res;\n}"
  dependsOn:
  - Template/Template.hpp
  isVerificationFile: false
  path: Matrix/LinearEquation.hpp
  requiredBy:
  - Matrix/AdjugateMatrix.hpp
  timestamp: '2022-08-20 01:45:54+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Matrix/LinearEquation.hpp
layout: document
redirect_from:
- /library/Matrix/LinearEquation.hpp
- /library/Matrix/LinearEquation.hpp.html
title: Matrix/LinearEquation.hpp
---
