---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Template/Template.hpp
    title: Template/Template.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Number_Theory/MultiplicativeFunctionPSumFast.hpp
    title: Number_Theory/MultiplicativeFunctionPSumFast.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/CountingPrimes.test.cpp
    title: Verify/CountingPrimes.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/SumofTotientFunction2.test.cpp
    title: Verify/SumofTotientFunction2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Polynomial/LagrangeInterpolation.hpp\"\n\n#line 2 \"Template/Template.hpp\"\
    \n\nusing namespace std;\n\n#include <bits/stdc++.h>\n\nusing i64 = long long;\n\
    using VI = vector<int>;\nusing pii = pair<int, int>;\n#line 4 \"Polynomial/LagrangeInterpolation.hpp\"\
    \ntemplate <typename T>\nT LagrangeInterpolation(const vector<T> &y, long long\
    \ x) {\n    //(0,y[0]),(1,y[1]),...,(N,y[N])\n    int N = (int)y.size() - 1;\n\
    \    if (x <= N) return y[x];\n    T ret = 0;\n    vector<T> dp(N + 1, 1), pd(N\
    \ + 1, 1), finv(N + 1, 0);\n    T a = x, one = 1;\n    finv[N] = T(1);\n    for\
    \ (int i = 1; i <= N; i++) finv[N] *= T(i);\n    finv[N] = finv[N].inverse();\n\
    \    for (int i = N - 1; i >= 0; i--) finv[i] = finv[i + 1] * T(i + 1);\n    for\
    \ (int i = 0; i < N; i++) dp[i + 1] = dp[i] * a, a -= one;\n    for (int i = N;\
    \ i > 0; i--) pd[i - 1] = pd[i] * a, a += one;\n    for (int i = 0; i <= N; i++)\
    \ {\n        T tmp = y[i] * dp[i] * pd[i] * finv[i] * finv[N - i];\n        ret\
    \ += ((N - i) & 1) ? -tmp : tmp;\n    }\n    return ret;\n}\n"
  code: "#pragma once\n\n#include \"../Template/Template.hpp\"\ntemplate <typename\
    \ T>\nT LagrangeInterpolation(const vector<T> &y, long long x) {\n    //(0,y[0]),(1,y[1]),...,(N,y[N])\n\
    \    int N = (int)y.size() - 1;\n    if (x <= N) return y[x];\n    T ret = 0;\n\
    \    vector<T> dp(N + 1, 1), pd(N + 1, 1), finv(N + 1, 0);\n    T a = x, one =\
    \ 1;\n    finv[N] = T(1);\n    for (int i = 1; i <= N; i++) finv[N] *= T(i);\n\
    \    finv[N] = finv[N].inverse();\n    for (int i = N - 1; i >= 0; i--) finv[i]\
    \ = finv[i + 1] * T(i + 1);\n    for (int i = 0; i < N; i++) dp[i + 1] = dp[i]\
    \ * a, a -= one;\n    for (int i = N; i > 0; i--) pd[i - 1] = pd[i] * a, a +=\
    \ one;\n    for (int i = 0; i <= N; i++) {\n        T tmp = y[i] * dp[i] * pd[i]\
    \ * finv[i] * finv[N - i];\n        ret += ((N - i) & 1) ? -tmp : tmp;\n    }\n\
    \    return ret;\n}"
  dependsOn:
  - Template/Template.hpp
  isVerificationFile: false
  path: Polynomial/LagrangeInterpolation.hpp
  requiredBy:
  - Number_Theory/MultiplicativeFunctionPSumFast.hpp
  timestamp: '2022-10-17 18:11:29+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/SumofTotientFunction2.test.cpp
  - Verify/CountingPrimes.test.cpp
documentation_of: Polynomial/LagrangeInterpolation.hpp
layout: document
redirect_from:
- /library/Polynomial/LagrangeInterpolation.hpp
- /library/Polynomial/LagrangeInterpolation.hpp.html
title: Polynomial/LagrangeInterpolation.hpp
---
