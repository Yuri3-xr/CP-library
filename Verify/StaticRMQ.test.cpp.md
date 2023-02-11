---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/RMQ.hpp
    title: DataStructure/RMQ.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"Verify/StaticRMQ.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\
    \n\n#line 2 \"Template/Template.hpp\"\n\n#include <bits/stdc++.h>\n\nusing i64\
    \ = std::int64_t;\n#line 3 \"DataStructure/RMQ.hpp\"\n\ntemplate <class T, class\
    \ Cmp = std::less<T>>\nstruct RMQ {\n    const int n;\n    const Cmp cmp;\n  \
    \  std::vector<std::vector<T>> a;\n    RMQ(const std::vector<T> &init) : n(init.size()),\
    \ cmp(Cmp()) {\n        int lg = std::__lg(n);\n        a.assign(lg + 1, std::vector<T>(n));\n\
    \        for (int j = 0; j <= lg; j++) {\n            for (int i = 0; i + (1 <<\
    \ j) <= n; i++) {\n                a[j][i] =\n                    (j == 0 ? init[i]\n\
    \                            : std::min(a[j - 1][i],\n                       \
    \                a[j - 1][i + (1 << (j - 1))], cmp));\n            }\n       \
    \ }\n    }\n    T rangeMin(int l, int r) {\n        int k = std::__lg(r - l);\n\
    \        return std::min(a[k][l], a[k][r - (1 << k)], cmp);\n    }\n};\n#line\
    \ 5 \"Verify/StaticRMQ.test.cpp\"\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n\n    int n, q;\n    std::cin >> n >> q;\n    std::vector<int>\
    \ a(n);\n    for (auto&& it : a) std::cin >> it;\n    RMQ<int> rmq(a);\n\n   \
    \ while (q--) {\n        int l, r;\n        std::cin >> l >> r;\n        std::cout\
    \ << rmq.rangeMin(l, r) << '\\n';\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ \"../DataStructure/RMQ.hpp\"\n#include \"../Template/Template.hpp\"\n\nint main()\
    \ {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\n   \
    \ int n, q;\n    std::cin >> n >> q;\n    std::vector<int> a(n);\n    for (auto&&\
    \ it : a) std::cin >> it;\n    RMQ<int> rmq(a);\n\n    while (q--) {\n       \
    \ int l, r;\n        std::cin >> l >> r;\n        std::cout << rmq.rangeMin(l,\
    \ r) << '\\n';\n    }\n\n    return 0;\n}"
  dependsOn:
  - DataStructure/RMQ.hpp
  - Template/Template.hpp
  isVerificationFile: true
  path: Verify/StaticRMQ.test.cpp
  requiredBy: []
  timestamp: '2023-02-11 22:28:05+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/StaticRMQ.test.cpp
layout: document
redirect_from:
- /verify/Verify/StaticRMQ.test.cpp
- /verify/Verify/StaticRMQ.test.cpp.html
title: Verify/StaticRMQ.test.cpp
---
