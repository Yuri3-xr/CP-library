---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Template/Template.hpp
    title: Template/Template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Template/Template.hpp\"\n\nusing namespace std;\n\n#include\
    \ <bits/stdc++.h>\n\nusing i64 = long long;\nusing VI = vector<int>;\nusing pii\
    \ = pair<int, int>;\n#line 2 \"Geometry/Minkowski_Sum.hpp\"\n\nauto Minkowski_Sum\
    \ = [&](const vector<P>& a, const vector<P>& b) {\n    vector<P> res;\n    auto\
    \ sgnp = [&](P a) -> int {\n        return (a.y > 0 || (a.y == 0 && a.x > 0) ?\
    \ 1 : -1);\n    };\n    auto argcmp = [&](P a, P b) {\n        return sgnp(a)\
    \ != sgnp(b) ? sgnp(a) == 1 : a.cross(b) > eps;\n    };\n    vector<pair<P, P>>\
    \ e1(a.size()), e2(b.size()), edge(a.size() + b.size());\n    auto cmp = [&](const\
    \ pair<P, P>& u, const pair<P, P>& v) {\n        return argcmp(u.second - u.first,\
    \ v.second - v.first);\n    };\n    for (size_t i = 0; i < a.size(); i++) e1[i]\
    \ = {a[i], a[(i + 1) % a.size()]};\n    for (size_t i = 0; i < b.size(); i++)\
    \ e2[i] = {b[i], b[(i + 1) % b.size()]};\n    rotate(e1.begin(), min_element(e1.begin(),\
    \ e1.end(), cmp), e1.end());\n    rotate(e2.begin(), min_element(e2.begin(), e2.end(),\
    \ cmp), e2.end());\n    merge(e1.begin(), e1.end(), e2.begin(), e2.end(), edge.begin(),\
    \ cmp);\n    const auto check = [&](const vector<P>& res, const P& u) {\n    \
    \    const auto back1 = res.back(), back2 = *prev(res.end(), 2);\n        return\
    \ sgn<double>((back1 - back2).cross(u - back1)) == 0 &&\n               (back1\
    \ - back2) * (u - back1) > -eps;\n    };\n    auto u = e1[0].first + e2[0].first;\n\
    \    for (auto& v : edge) {\n        while (res.size() > 1 && check(res, u)) res.pop_back();\n\
    \        res.push_back(u);\n        u = u + v.second - v.first;\n    }\n    if\
    \ (res.size() > 1 && check(res, res[0])) res.pop_back();\n    return res;\n};\n"
  code: "#include \"../Template/Template.hpp\"\n\nauto Minkowski_Sum = [&](const vector<P>&\
    \ a, const vector<P>& b) {\n    vector<P> res;\n    auto sgnp = [&](P a) -> int\
    \ {\n        return (a.y > 0 || (a.y == 0 && a.x > 0) ? 1 : -1);\n    };\n   \
    \ auto argcmp = [&](P a, P b) {\n        return sgnp(a) != sgnp(b) ? sgnp(a) ==\
    \ 1 : a.cross(b) > eps;\n    };\n    vector<pair<P, P>> e1(a.size()), e2(b.size()),\
    \ edge(a.size() + b.size());\n    auto cmp = [&](const pair<P, P>& u, const pair<P,\
    \ P>& v) {\n        return argcmp(u.second - u.first, v.second - v.first);\n \
    \   };\n    for (size_t i = 0; i < a.size(); i++) e1[i] = {a[i], a[(i + 1) % a.size()]};\n\
    \    for (size_t i = 0; i < b.size(); i++) e2[i] = {b[i], b[(i + 1) % b.size()]};\n\
    \    rotate(e1.begin(), min_element(e1.begin(), e1.end(), cmp), e1.end());\n \
    \   rotate(e2.begin(), min_element(e2.begin(), e2.end(), cmp), e2.end());\n  \
    \  merge(e1.begin(), e1.end(), e2.begin(), e2.end(), edge.begin(), cmp);\n   \
    \ const auto check = [&](const vector<P>& res, const P& u) {\n        const auto\
    \ back1 = res.back(), back2 = *prev(res.end(), 2);\n        return sgn<double>((back1\
    \ - back2).cross(u - back1)) == 0 &&\n               (back1 - back2) * (u - back1)\
    \ > -eps;\n    };\n    auto u = e1[0].first + e2[0].first;\n    for (auto& v :\
    \ edge) {\n        while (res.size() > 1 && check(res, u)) res.pop_back();\n \
    \       res.push_back(u);\n        u = u + v.second - v.first;\n    }\n    if\
    \ (res.size() > 1 && check(res, res[0])) res.pop_back();\n    return res;\n};"
  dependsOn:
  - Template/Template.hpp
  isVerificationFile: false
  path: Geometry/Minkowski_Sum.hpp
  requiredBy: []
  timestamp: '2022-08-31 04:02:48+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/Minkowski_Sum.hpp
layout: document
redirect_from:
- /library/Geometry/Minkowski_Sum.hpp
- /library/Geometry/Minkowski_Sum.hpp.html
title: Geometry/Minkowski_Sum.hpp
---