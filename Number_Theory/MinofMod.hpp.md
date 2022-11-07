---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Template/Template.hpp
    title: Template/Template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/MinofModofLinear.test.cpp
    title: Verify/MinofModofLinear.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Number_Theory/MinofMod.hpp\"\n\n#line 2 \"Template/Template.hpp\"\
    \n\nusing namespace std;\n\n#include <bits/stdc++.h>\n\nusing i64 = long long;\n\
    using VI = vector<int>;\nusing pii = pair<int, int>;\n#line 4 \"Number_Theory/MinofMod.hpp\"\
    \n\ntemplate <typename T, typename U>\nT ceil(T x, U y) {\n    return (x > 0 ?\
    \ (x + y - 1) / y : x / y);\n}\ntemplate <class T>\npair<vector<T>, vector<T>>\
    \ min_of_linear_segments(T a, T b, T mod) {\n    assert(0 <= a && a < mod);\n\
    \    assert(0 <= b && b < mod);\n    vector<T> X = {0};\n    vector<T> DX;\n \
    \   T g = gcd(a, mod);\n    a /= g, b /= g, mod /= g;\n    T p = 0, q = 1, r =\
    \ 1, s = 1;\n    T det_l = mod - a, det_r = a;\n    T x = 0, y = b;\n\n    while\
    \ (y) {\n        T k = det_r / det_l;\n        det_r %= det_l;\n        if (det_r\
    \ == 0) {\n            --k;\n            det_r = det_l;\n        }\n        r\
    \ += k * p;\n        s += k * q;\n        while (1) {\n            T k = max<T>(0,\
    \ ceil(det_l - y, det_r));\n            if (det_l - k * det_r <= 0) break;\n \
    \           det_l -= k * det_r;\n            p += k * r;\n            q += k *\
    \ s;\n            k = y / det_l;\n            y -= k * det_l;\n            x +=\
    \ q * k;\n            X.emplace_back(x);\n            DX.emplace_back(q);\n  \
    \      }\n        k = det_l / det_r;\n        det_l -= k * det_r;\n        p +=\
    \ k * r;\n        q += k * s;\n        assert(min({p, q, r, s}) >= 0);\n    }\n\
    \    return {X, DX};\n}\n// min_{x in [L, R)} (ax+b mod MOD)\ntemplate <class\
    \ T>\npair<T, T> min_of_linear(T L, T R, T a, T b, T mod) {\n    // return [x,fx]\n\
    \    T n = R - L;\n    b = (b + a * L) % mod;\n    if (b < 0) b += mod;\n    auto\
    \ [X, DX] = min_of_linear_segments<T>(a, b, mod);\n    T x = 0;\n    for (T i\
    \ = 0; i < int(X.size()) - 1; ++i) {\n        T xl = X[i], xr = X[i + 1];\n  \
    \      if (xr < n) {\n            x = xr;\n            continue;\n        }\n\
    \        x = xl + (n - 1 - x) / DX[i] * DX[i];\n        break;\n    }\n    T y\
    \ = (T(a) * x + b) % mod;\n    return {L + x, y};\n}\n"
  code: "#pragma once\n\n#include \"../Template/Template.hpp\"\n\ntemplate <typename\
    \ T, typename U>\nT ceil(T x, U y) {\n    return (x > 0 ? (x + y - 1) / y : x\
    \ / y);\n}\ntemplate <class T>\npair<vector<T>, vector<T>> min_of_linear_segments(T\
    \ a, T b, T mod) {\n    assert(0 <= a && a < mod);\n    assert(0 <= b && b < mod);\n\
    \    vector<T> X = {0};\n    vector<T> DX;\n    T g = gcd(a, mod);\n    a /= g,\
    \ b /= g, mod /= g;\n    T p = 0, q = 1, r = 1, s = 1;\n    T det_l = mod - a,\
    \ det_r = a;\n    T x = 0, y = b;\n\n    while (y) {\n        T k = det_r / det_l;\n\
    \        det_r %= det_l;\n        if (det_r == 0) {\n            --k;\n      \
    \      det_r = det_l;\n        }\n        r += k * p;\n        s += k * q;\n \
    \       while (1) {\n            T k = max<T>(0, ceil(det_l - y, det_r));\n  \
    \          if (det_l - k * det_r <= 0) break;\n            det_l -= k * det_r;\n\
    \            p += k * r;\n            q += k * s;\n            k = y / det_l;\n\
    \            y -= k * det_l;\n            x += q * k;\n            X.emplace_back(x);\n\
    \            DX.emplace_back(q);\n        }\n        k = det_l / det_r;\n    \
    \    det_l -= k * det_r;\n        p += k * r;\n        q += k * s;\n        assert(min({p,\
    \ q, r, s}) >= 0);\n    }\n    return {X, DX};\n}\n// min_{x in [L, R)} (ax+b\
    \ mod MOD)\ntemplate <class T>\npair<T, T> min_of_linear(T L, T R, T a, T b, T\
    \ mod) {\n    // return [x,fx]\n    T n = R - L;\n    b = (b + a * L) % mod;\n\
    \    if (b < 0) b += mod;\n    auto [X, DX] = min_of_linear_segments<T>(a, b,\
    \ mod);\n    T x = 0;\n    for (T i = 0; i < int(X.size()) - 1; ++i) {\n     \
    \   T xl = X[i], xr = X[i + 1];\n        if (xr < n) {\n            x = xr;\n\
    \            continue;\n        }\n        x = xl + (n - 1 - x) / DX[i] * DX[i];\n\
    \        break;\n    }\n    T y = (T(a) * x + b) % mod;\n    return {L + x, y};\n\
    }"
  dependsOn:
  - Template/Template.hpp
  isVerificationFile: false
  path: Number_Theory/MinofMod.hpp
  requiredBy: []
  timestamp: '2022-11-03 22:25:00+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/MinofModofLinear.test.cpp
documentation_of: Number_Theory/MinofMod.hpp
layout: document
redirect_from:
- /library/Number_Theory/MinofMod.hpp
- /library/Number_Theory/MinofMod.hpp.html
title: Number_Theory/MinofMod.hpp
---
