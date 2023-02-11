---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Geometry/Point.hpp
    title: Geometry/Point.hpp
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
  bundledCode: "#line 2 \"Geometry/Minkowski_Sum.hpp\"\n\n#line 2 \"Template/Template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\nusing i64 = std::int64_t;\n#line 2 \"Geometry/Point.hpp\"\
    \n\ntemplate <class T>\nint sgn(T x) {\n    return (x > 0) - (x < 0);\n}\ntemplate\
    \ <class T>\nstruct Point {\n    typedef Point P;\n    T x, y;\n    explicit Point(T\
    \ x = 0, T y = 0) : x(x), y(y) {}\n    bool operator<(P p) const { return tie(x,\
    \ y) < tie(p.x, p.y); }\n    bool operator==(P p) const { return tie(x, y) ==\
    \ tie(p.x, p.y); }\n    P operator+(P p) const { return P(x + p.x, y + p.y); }\n\
    \    P operator-(P p) const { return P(x - p.x, y - p.y); }\n    P operator*(T\
    \ d) const { return P(x * d, y * d); }\n    P operator/(T d) const { return P(x\
    \ / d, y / d); }\n    T dot(P p) const { return x * p.x + y * p.y; }\n    T operator*(P\
    \ p) const { return x * p.x + y * p.y; }\n    T cross(P p) const { return x *\
    \ p.y - y * p.x; }\n    T cross(P a, P b) const { return (a - *this).cross(b -\
    \ *this); }\n    T dist2() const { return x * x + y * y; }\n    double dist()\
    \ const { return sqrt((double)dist2()); }\n    // angle to x-axis in interval\
    \ [-pi, pi]\n    double angle() const { return atan2(y, x); }\n    P unit() const\
    \ { return *this / dist(); }  // makes dist()=1\n    P perp() const { return P(-y,\
    \ x); }        // rotates +90 degrees\n    P normal() const { return perp().unit();\
    \ }\n    // returns point rotated 'a' radians ccw around the origin\n    P rotate(double\
    \ a) const {\n        return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));\n\
    \    }\n    friend std::ostream& operator<<(std::ostream& os, P p) {\n       \
    \ return os << \"(\" << p.x << \",\" << p.y << \")\";\n    }\n};\n#line 5 \"Geometry/Minkowski_Sum.hpp\"\
    \n\nconstexpr double EPS = 1E-6;\ntemplate <class P>\nstd::vector<P> Minkowski_Sum(const\
    \ std::vector<P>& a, const std::vector<P>& b) {\n    std::vector<P> res;\n   \
    \ auto sgnp = [&](P a) -> int {\n        return (a.y > 0 || (a.y == 0 && a.x >\
    \ 0) ? 1 : -1);\n    };\n    auto argcmp = [&](P a, P b) {\n        return sgnp(a)\
    \ != sgnp(b) ? sgnp(a) == 1 : a.cross(b) > EPS;\n    };\n    std::vector<pair<P,\
    \ P>> e1(a.size()), e2(b.size()),\n        edge(a.size() + b.size());\n    auto\
    \ cmp = [&](const pair<P, P>& u, const pair<P, P>& v) {\n        return argcmp(u.second\
    \ - u.first, v.second - v.first);\n    };\n    for (size_t i = 0; i < a.size();\
    \ i++) e1[i] = {a[i], a[(i + 1) % a.size()]};\n    for (size_t i = 0; i < b.size();\
    \ i++) e2[i] = {b[i], b[(i + 1) % b.size()]};\n    std::rotate(e1.begin(), min_element(e1.begin(),\
    \ e1.end(), cmp), e1.end());\n    std::rotate(e2.begin(), min_element(e2.begin(),\
    \ e2.end(), cmp), e2.end());\n    merge(e1.begin(), e1.end(), e2.begin(), e2.end(),\
    \ edge.begin(), cmp);\n    const auto check = [&](const std::vector<P>& res, const\
    \ P& u) {\n        const auto back1 = res.back(), back2 = *prev(res.end(), 2);\n\
    \        return sgn<double>((back1 - back2).cross(u - back1)) == 0 &&\n      \
    \         (back1 - back2) * (u - back1) > -EPS;\n    };\n    auto u = e1[0].first\
    \ + e2[0].first;\n    for (auto& v : edge) {\n        while (res.size() > 1 &&\
    \ check(res, u)) res.pop_back();\n        res.push_back(u);\n        u = u + v.second\
    \ - v.first;\n    }\n    if (res.size() > 1 && check(res, res[0])) res.pop_back();\n\
    \    return res;\n};\n"
  code: "#pragma once\n\n#include \"../Template/Template.hpp\"\n#include \"Point.hpp\"\
    \n\nconstexpr double EPS = 1E-6;\ntemplate <class P>\nstd::vector<P> Minkowski_Sum(const\
    \ std::vector<P>& a, const std::vector<P>& b) {\n    std::vector<P> res;\n   \
    \ auto sgnp = [&](P a) -> int {\n        return (a.y > 0 || (a.y == 0 && a.x >\
    \ 0) ? 1 : -1);\n    };\n    auto argcmp = [&](P a, P b) {\n        return sgnp(a)\
    \ != sgnp(b) ? sgnp(a) == 1 : a.cross(b) > EPS;\n    };\n    std::vector<pair<P,\
    \ P>> e1(a.size()), e2(b.size()),\n        edge(a.size() + b.size());\n    auto\
    \ cmp = [&](const pair<P, P>& u, const pair<P, P>& v) {\n        return argcmp(u.second\
    \ - u.first, v.second - v.first);\n    };\n    for (size_t i = 0; i < a.size();\
    \ i++) e1[i] = {a[i], a[(i + 1) % a.size()]};\n    for (size_t i = 0; i < b.size();\
    \ i++) e2[i] = {b[i], b[(i + 1) % b.size()]};\n    std::rotate(e1.begin(), min_element(e1.begin(),\
    \ e1.end(), cmp), e1.end());\n    std::rotate(e2.begin(), min_element(e2.begin(),\
    \ e2.end(), cmp), e2.end());\n    merge(e1.begin(), e1.end(), e2.begin(), e2.end(),\
    \ edge.begin(), cmp);\n    const auto check = [&](const std::vector<P>& res, const\
    \ P& u) {\n        const auto back1 = res.back(), back2 = *prev(res.end(), 2);\n\
    \        return sgn<double>((back1 - back2).cross(u - back1)) == 0 &&\n      \
    \         (back1 - back2) * (u - back1) > -EPS;\n    };\n    auto u = e1[0].first\
    \ + e2[0].first;\n    for (auto& v : edge) {\n        while (res.size() > 1 &&\
    \ check(res, u)) res.pop_back();\n        res.push_back(u);\n        u = u + v.second\
    \ - v.first;\n    }\n    if (res.size() > 1 && check(res, res[0])) res.pop_back();\n\
    \    return res;\n};"
  dependsOn:
  - Template/Template.hpp
  - Geometry/Point.hpp
  isVerificationFile: false
  path: Geometry/Minkowski_Sum.hpp
  requiredBy: []
  timestamp: '2023-02-11 22:28:05+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/Minkowski_Sum.hpp
layout: document
redirect_from:
- /library/Geometry/Minkowski_Sum.hpp
- /library/Geometry/Minkowski_Sum.hpp.html
title: Geometry/Minkowski_Sum.hpp
---
