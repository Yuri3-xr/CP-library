---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Number_Theory/MinofMod.hpp
    title: Number_Theory/MinofMod.hpp
  - icon: ':heavy_check_mark:'
    path: Template/Template.hpp
    title: Template/Template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/min_of_mod_of_linear
    links:
    - https://judge.yosupo.jp/problem/min_of_mod_of_linear
  bundledCode: "#line 1 \"Verify/MinofModofLinear.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/min_of_mod_of_linear\"\
    \n\n#line 2 \"Number_Theory/MinofMod.hpp\"\n\n#line 2 \"Template/Template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\nusing i64 = std::int64_t;\n#line 4 \"Number_Theory/MinofMod.hpp\"\
    \n\ntemplate <typename T, typename U>\nT ceil(T x, U y) {\n    return (x > 0 ?\
    \ (x + y - 1) / y : x / y);\n}\ntemplate <class T>\nstd::pair<std::vector<T>,\
    \ std::vector<T>> min_of_linear_segments(T a, T b,\n                         \
    \                                        T mod) {\n    assert(0 <= a && a < mod);\n\
    \    assert(0 <= b && b < mod);\n    std::vector<T> X = {0};\n    std::vector<T>\
    \ DX;\n    T g = std::gcd(a, mod);\n    a /= g, b /= g, mod /= g;\n    T p = 0,\
    \ q = 1, r = 1, s = 1;\n    T det_l = mod - a, det_r = a;\n    T x = 0, y = b;\n\
    \n    while (y) {\n        T k = det_r / det_l;\n        det_r %= det_l;\n   \
    \     if (det_r == 0) {\n            --k;\n            det_r = det_l;\n      \
    \  }\n        r += k * p;\n        s += k * q;\n        while (1) {\n        \
    \    T k = std::max<T>(0, ceil(det_l - y, det_r));\n            if (det_l - k\
    \ * det_r <= 0) break;\n            det_l -= k * det_r;\n            p += k *\
    \ r;\n            q += k * s;\n            k = y / det_l;\n            y -= k\
    \ * det_l;\n            x += q * k;\n            X.emplace_back(x);\n        \
    \    DX.emplace_back(q);\n        }\n        k = det_l / det_r;\n        det_l\
    \ -= k * det_r;\n        p += k * r;\n        q += k * s;\n        assert(std::min({p,\
    \ q, r, s}) >= 0);\n    }\n    return {X, DX};\n}\n// min_{x in [L, R)} (ax+b\
    \ mod MOD)\ntemplate <class T>\nstd::pair<T, T> min_of_linear(T L, T R, T a, T\
    \ b, T mod) {\n    // return [x,fx]\n    T n = R - L;\n    b = (b + a * L) % mod;\n\
    \    if (b < 0) b += mod;\n    auto [X, DX] = min_of_linear_segments<T>(a, b,\
    \ mod);\n    T x = 0;\n    for (T i = 0; i < int(X.size()) - 1; ++i) {\n     \
    \   T xl = X[i], xr = X[i + 1];\n        if (xr < n) {\n            x = xr;\n\
    \            continue;\n        }\n        x = xl + (n - 1 - x) / DX[i] * DX[i];\n\
    \        break;\n    }\n    T y = (T(a) * x + b) % mod;\n    return {L + x, y};\n\
    }\n#line 4 \"Verify/MinofModofLinear.test.cpp\"\n\nvoid solve() {\n    i64 n,\
    \ m, a, b;\n    std::cin >> n >> m >> a >> b;\n    auto [x, fx] = min_of_linear<i64>(0,\
    \ n, a, b, m);\n    std::cout << fx << '\\n';\n    assert((a * x + b) % m == fx);\n\
    }\n\nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    int T;\n    std::cin >> T;\n\n    while (T--) {\n        solve();\n    }\n\
    \n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/min_of_mod_of_linear\"\n\
    \n#include \"../Number_Theory/MinofMod.hpp\"\n\nvoid solve() {\n    i64 n, m,\
    \ a, b;\n    std::cin >> n >> m >> a >> b;\n    auto [x, fx] = min_of_linear<i64>(0,\
    \ n, a, b, m);\n    std::cout << fx << '\\n';\n    assert((a * x + b) % m == fx);\n\
    }\n\nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    int T;\n    std::cin >> T;\n\n    while (T--) {\n        solve();\n    }\n\
    \n    return 0;\n}\n"
  dependsOn:
  - Number_Theory/MinofMod.hpp
  - Template/Template.hpp
  isVerificationFile: true
  path: Verify/MinofModofLinear.test.cpp
  requiredBy: []
  timestamp: '2023-02-11 22:28:05+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/MinofModofLinear.test.cpp
layout: document
redirect_from:
- /verify/Verify/MinofModofLinear.test.cpp
- /verify/Verify/MinofModofLinear.test.cpp.html
title: Verify/MinofModofLinear.test.cpp
---
