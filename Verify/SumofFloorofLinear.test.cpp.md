---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Number_Theory/SumofFloor.hpp
    title: Number_Theory/SumofFloor.hpp
  - icon: ':question:'
    path: Template/Template.hpp
    title: Template/Template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_floor_of_linear
    links:
    - https://judge.yosupo.jp/problem/sum_of_floor_of_linear
  bundledCode: "#line 1 \"Verify/SumofFloorofLinear.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\n\n#line 2 \"Number_Theory/SumofFloor.hpp\"\
    \n\n#line 2 \"Template/Template.hpp\"\n\nusing namespace std;\n\n#include <bits/stdc++.h>\n\
    \nusing i64 = long long;\nusing VI = vector<int>;\nusing pii = pair<int, int>;\n\
    #line 4 \"Number_Theory/SumofFloor.hpp\"\n// sum_{0 <= i < N} (ai + b) // m\n\
    template <typename T>\nT sum_of_floor(T n, T m, T a, T b) {\n    T ret = 0;\n\
    \    if (a >= m) ret += (n - 1) * n * (a / m) / 2, a %= m;\n    if (b >= m) ret\
    \ += n * (b / m), b %= m;\n    T y = (a * n + b) / m;\n    if (y == 0) return\
    \ ret;\n    T x = y * m - b;\n    ret += (n - (x + a - 1) / a) * y;\n    ret +=\
    \ sum_of_floor(y, a, m, (a - x % a) % a);\n    return ret;\n}\n\n// verify www.codechef.com/viewsolution/36222026\n\
    // count x : ax + b mod m < yr, 0 <= x < xr\ntemplate <typename T>\nT mod_affine_range_counting(T\
    \ a, T b, T m, T xr, T yr) {\n    assert(0 <= yr && yr <= m);\n    return sum_of_floor(xr,\
    \ m, a, b + m) - sum_of_floor(xr, m, a, b + m - yr);\n}\n#line 4 \"Verify/SumofFloorofLinear.test.cpp\"\
    \n\nvoid solve() {\n    i64 n, m, a, b;\n    cin >> n >> m >> a >> b;\n    auto\
    \ ans = sum_of_floor<i64>(n, m, a, b);\n    cout << ans << '\\n';\n    return;\n\
    }\n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n\
    \    int T;\n    cin >> T;\n\n    while (T--) {\n        solve();\n    }\n\n \
    \   return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\
    \n\n#include \"../Number_Theory/SumofFloor.hpp\"\n\nvoid solve() {\n    i64 n,\
    \ m, a, b;\n    cin >> n >> m >> a >> b;\n    auto ans = sum_of_floor<i64>(n,\
    \ m, a, b);\n    cout << ans << '\\n';\n    return;\n}\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int T;\n    cin >> T;\n\n    while (T--) {\n   \
    \     solve();\n    }\n\n    return 0;\n}"
  dependsOn:
  - Number_Theory/SumofFloor.hpp
  - Template/Template.hpp
  isVerificationFile: true
  path: Verify/SumofFloorofLinear.test.cpp
  requiredBy: []
  timestamp: '2022-11-03 22:40:46+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/SumofFloorofLinear.test.cpp
layout: document
redirect_from:
- /verify/Verify/SumofFloorofLinear.test.cpp
- /verify/Verify/SumofFloorofLinear.test.cpp.html
title: Verify/SumofFloorofLinear.test.cpp
---
