---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Template/Template.hpp
    title: Template/Template.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Geometry/Minkowski_Sum.hpp
    title: Geometry/Minkowski_Sum.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Template/Template.hpp\"\n\n#include <bits/stdc++.h>\n\n\
    using i64 = std::int64_t;\n#line 2 \"Geometry/Point.hpp\"\n\ntemplate <class T>\n\
    int sgn(T x) {\n    return (x > 0) - (x < 0);\n}\ntemplate <class T>\nstruct Point\
    \ {\n    typedef Point P;\n    T x, y;\n    explicit Point(T x = 0, T y = 0) :\
    \ x(x), y(y) {}\n    bool operator<(P p) const { return tie(x, y) < tie(p.x, p.y);\
    \ }\n    bool operator==(P p) const { return tie(x, y) == tie(p.x, p.y); }\n \
    \   P operator+(P p) const { return P(x + p.x, y + p.y); }\n    P operator-(P\
    \ p) const { return P(x - p.x, y - p.y); }\n    P operator*(T d) const { return\
    \ P(x * d, y * d); }\n    P operator/(T d) const { return P(x / d, y / d); }\n\
    \    T dot(P p) const { return x * p.x + y * p.y; }\n    T operator*(P p) const\
    \ { return x * p.x + y * p.y; }\n    T cross(P p) const { return x * p.y - y *\
    \ p.x; }\n    T cross(P a, P b) const { return (a - *this).cross(b - *this); }\n\
    \    T dist2() const { return x * x + y * y; }\n    double dist() const { return\
    \ sqrt((double)dist2()); }\n    // angle to x-axis in interval [-pi, pi]\n   \
    \ double angle() const { return atan2(y, x); }\n    P unit() const { return *this\
    \ / dist(); }  // makes dist()=1\n    P perp() const { return P(-y, x); }    \
    \    // rotates +90 degrees\n    P normal() const { return perp().unit(); }\n\
    \    // returns point rotated 'a' radians ccw around the origin\n    P rotate(double\
    \ a) const {\n        return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));\n\
    \    }\n    friend std::ostream& operator<<(std::ostream& os, P p) {\n       \
    \ return os << \"(\" << p.x << \",\" << p.y << \")\";\n    }\n};\n"
  code: "#include \"../Template/Template.hpp\"\n\ntemplate <class T>\nint sgn(T x)\
    \ {\n    return (x > 0) - (x < 0);\n}\ntemplate <class T>\nstruct Point {\n  \
    \  typedef Point P;\n    T x, y;\n    explicit Point(T x = 0, T y = 0) : x(x),\
    \ y(y) {}\n    bool operator<(P p) const { return tie(x, y) < tie(p.x, p.y); }\n\
    \    bool operator==(P p) const { return tie(x, y) == tie(p.x, p.y); }\n    P\
    \ operator+(P p) const { return P(x + p.x, y + p.y); }\n    P operator-(P p) const\
    \ { return P(x - p.x, y - p.y); }\n    P operator*(T d) const { return P(x * d,\
    \ y * d); }\n    P operator/(T d) const { return P(x / d, y / d); }\n    T dot(P\
    \ p) const { return x * p.x + y * p.y; }\n    T operator*(P p) const { return\
    \ x * p.x + y * p.y; }\n    T cross(P p) const { return x * p.y - y * p.x; }\n\
    \    T cross(P a, P b) const { return (a - *this).cross(b - *this); }\n    T dist2()\
    \ const { return x * x + y * y; }\n    double dist() const { return sqrt((double)dist2());\
    \ }\n    // angle to x-axis in interval [-pi, pi]\n    double angle() const {\
    \ return atan2(y, x); }\n    P unit() const { return *this / dist(); }  // makes\
    \ dist()=1\n    P perp() const { return P(-y, x); }        // rotates +90 degrees\n\
    \    P normal() const { return perp().unit(); }\n    // returns point rotated\
    \ 'a' radians ccw around the origin\n    P rotate(double a) const {\n        return\
    \ P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));\n    }\n    friend std::ostream&\
    \ operator<<(std::ostream& os, P p) {\n        return os << \"(\" << p.x << \"\
    ,\" << p.y << \")\";\n    }\n};"
  dependsOn:
  - Template/Template.hpp
  isVerificationFile: false
  path: Geometry/Point.hpp
  requiredBy:
  - Geometry/Minkowski_Sum.hpp
  timestamp: '2023-02-11 22:28:05+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/Point.hpp
layout: document
redirect_from:
- /library/Geometry/Point.hpp
- /library/Geometry/Point.hpp.html
title: Geometry/Point.hpp
---
