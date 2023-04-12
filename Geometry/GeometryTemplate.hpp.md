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
  bundledCode: "#line 2 \"Geometry/GeometryTemplate.hpp\"\n\n#line 2 \"Template/Template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\nusing i64 = std::int64_t;\n#line 4 \"Geometry/GeometryTemplate.hpp\"\
    \n\nnamespace Geometry {\n// using T = i64;\n// constexpr T eps = 0;\n\nusing\
    \ T = double;\nconstexpr T eps = 1E-10;\n\nbool equal(const T &x, const T &y)\
    \ { return abs(x - y) <= eps; }\nint sgn(T x) { return (x > 0) - (x < 0); }\n\
    inline constexpr int type(T x, T y) {\n    if (x == 0 and y == 0) return 0;\n\
    \    if (y < 0 or (y == 0 and x > 0)) return -1;\n    return 1;\n}\nstruct Point\
    \ {\n    T x, y;\n    constexpr Point(T _x = 0, T _y = 0) : x(_x), y(_y) {}\n\
    \    constexpr Point operator+() const noexcept { return *this; }\n    constexpr\
    \ Point operator-() const noexcept { return Point(-x, -y); }\n    constexpr Point\
    \ operator+(const Point &p) const {\n        return Point(x + p.x, y + p.y);\n\
    \    }\n    constexpr Point operator-(const Point &p) const {\n        return\
    \ Point(x - p.x, y - p.y);\n    }\n    constexpr Point &operator+=(const Point\
    \ &p) {\n        return x += p.x, y += p.y, *this;\n    }\n    constexpr Point\
    \ &operator-=(const Point &p) {\n        return x -= p.x, y -= p.y, *this;\n \
    \   }\n    constexpr T operator*(const Point &p) const { return x * p.x + y *\
    \ p.y; }\n    const Point operator/(T d) const { return Point(x / d, y / d); }\n\
    \    constexpr Point &operator*=(const T &k) { return x *= k, y *= k, *this; }\n\
    \    constexpr Point operator*(const T &k) { return Point(x * k, y * k); }\n \
    \   constexpr bool operator==(const Point &r) const noexcept {\n        return\
    \ r.x == x and r.y == y;\n    }\n    constexpr bool operator!=(const Point &r)\
    \ const noexcept {\n        return !(*this == r);\n    }\n    constexpr T cross(const\
    \ Point &r) const { return x * r.y - y * r.x; }\n    constexpr T cross(Point a,\
    \ Point b) const {\n        return (a - *this).cross(b - *this);\n    }\n    constexpr\
    \ bool operator<(const Point &r) const {\n        return std::pair(x, y) < std::pair(r.x,\
    \ r.y);\n    }\n\n    // 1 : left, 0 : same, -1 : right\n    constexpr int toleft(const\
    \ Point &r) const {\n        auto t = cross(r);\n        return t > eps ? 1 :\
    \ t < -eps ? -1 : 0;\n    }\n\n    constexpr bool arg_cmp(const Point &r) const\
    \ {\n        int L = type(x, y), R = type(r.x, r.y);\n        if (L != R) return\
    \ L < R;\n\n        T X = x * r.y, Y = r.x * y;\n        if (X != Y) return X\
    \ > Y;\n        return x < r.x;\n    }\n};\nbool arg_cmp(const Point &l, const\
    \ Point &r) { return l.arg_cmp(r); }\nstd::ostream &operator<<(std::ostream &os,\
    \ const Point &p) {\n    return os << p.x << \" \" << p.y;\n}\nstd::istream &operator>>(std::istream\
    \ &is, Point &p) {\n    is >> p.x >> p.y;\n    return is;\n}\n\nstruct Line {\n\
    \    Point a, b;\n    Line() = default;\n    Line(Point a, Point b) : a(a), b(b)\
    \ {}\n    // ax + by = c\n    Line(T A, T B, T C) {\n        if (A == 0) {\n \
    \           a = Point(0, C / B), b = Point(1, C / B);\n        } else if (B ==\
    \ 0) {\n            a = Point(C / A, 0), b = Point(C / A, 1);\n        } else\
    \ {\n            a = Point(0, C / B), b = Point(C / A, 0);\n        }\n    }\n\
    \    // 1 : left, 0 : same, -1 : right\n    constexpr int toleft(const Point &r)\
    \ const {\n        auto t = (b - a).cross(r - a);\n        return t > eps ? 1\
    \ : t < -eps ? -1 : 0;\n    }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, Line &ls) {\n        return os << \"{\"\n                  << \"(\" <<\
    \ ls.a.x << \", \" << ls.a.y << \"), (\" << ls.b.x << \", \"\n               \
    \   << ls.b.y << \")}\";\n    }\n};\nstd::istream &operator>>(std::istream &is,\
    \ Line &p) { return is >> p.a >> p.b; }\n\nstruct Segment : Line {\n    Segment()\
    \ = default;\n    Segment(Point a, Point b) : Line(a, b) {}\n};\n\nstd::ostream\
    \ &operator<<(std::ostream &os, Segment &p) {\n    return os << p.a << \" to \"\
    \ << p.b;\n}\nstd::istream &operator>>(std::istream &is, Segment &p) {\n    is\
    \ >> p.a >> p.b;\n    return is;\n}\n\nstruct Circle {\n    Point p;\n    T r;\n\
    \    Circle() = default;\n    Circle(Point p, T r) : p(p), r(r) {}\n};\n\nusing\
    \ pt = Point;\nusing Points = std::vector<pt>;\nusing Polygon = Points;\nT cross(const\
    \ pt &x, const pt &y) { return x.x * y.y - x.y * y.x; }\nT dot(const pt &x, const\
    \ pt &y) { return x.x * y.x + x.y * y.y; }\n\nT abs2(const pt &x) { return dot(x,\
    \ x); }\n\nint ccw(const Point &a, Point b, Point c) {\n    b = b - a, c = c -\
    \ a;\n    if (cross(b, c) > 0) return +1;    // \"COUNTER_CLOCKWISE\"\n    if\
    \ (cross(b, c) < 0) return -1;    // \"CLOCKWISE\"\n    if (dot(b, c) < 0) return\
    \ +2;      // \"ONLINE_BACK\"\n    if (abs2(b) < abs2(c)) return -2;  // \"ONLINE_FRONT\"\
    \n    return 0;                          // \"ON_SEGMENT\"\n}\n\nbool parallel(const\
    \ Line &a, const Line &b) {\n    return (cross(a.b - a.a, b.b - b.a) == 0);\n\
    }\n\nbool orthogonal(const Line &a, const Line &b) {\n    return (dot(a.a - a.b,\
    \ b.a - b.b) == 0);\n}\n\nbool intersect(const Line &l, const Point &p) {\n  \
    \  return abs(ccw(l.a, l.b, p)) != 1;\n}\n\nbool intersect(const Line &l, const\
    \ Line &m) { return !parallel(l, m); }\n\nbool intersect(const Segment &s, const\
    \ Point &p) {\n    return ccw(s.a, s.b, p) == 0;\n}\n\nbool intersect(const Line\
    \ &l, const Segment &s) {\n    return cross(l.b - l.a, s.a - l.a) * cross(l.b\
    \ - l.a, s.b - l.a) <= 0;\n}\n\nbool intersect(const Segment &s, const Segment\
    \ &t) {\n    return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 &&\n        \
    \   ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;\n}\n\nstd::vector<Point> segInter(const\
    \ Segment &sa, const Segment &sb) {\n    // if no intersect point return {}\n\
    \    // if inf intersect points return two end point\n    auto a = sa.a, b = sa.b;\n\
    \    auto c = sb.a, d = sb.b;\n    auto oa = c.cross(d, a), ob = c.cross(d, b),\
    \ oc = a.cross(b, c),\n         od = a.cross(b, d);\n    if (sgn(oa) * sgn(ob)\
    \ < 0 && sgn(oc) * sgn(od) < 0)\n        return {(a * ob - b * oa) / (ob - oa)};\n\
    \    std::set<Point> s;\n    if (intersect(Segment(c, d), a)) s.insert(a);\n \
    \   if (intersect(Segment(c, d), b)) s.insert(b);\n    if (intersect(Segment(a,\
    \ b), c)) s.insert(c);\n    if (intersect(Segment(a, b), d)) s.insert(d);\n  \
    \  return {begin(s), end(s)};\n}\n\nbool intersect(const Polygon &ps, const Polygon\
    \ &qs) {\n    int pl = size(ps), ql = size(qs), i = 0, j = 0;\n    while ((i <\
    \ pl or j < ql) and (i < 2 * pl) and (j < 2 * ql)) {\n        auto ps0 = ps[(i\
    \ + pl - 1) % pl], ps1 = ps[i % pl];\n        auto qs0 = qs[(j + ql - 1) % ql],\
    \ qs1 = qs[j % ql];\n        if (intersect(Segment(ps0, ps1), Segment(qs0, qs1)))\
    \ return true;\n        Point a = ps1 - ps0;\n        Point b = qs1 - qs0;\n \
    \       T v = cross(a, b);\n        T va = cross(qs1 - qs0, ps1 - qs0);\n    \
    \    T vb = cross(ps1 - ps0, qs1 - ps0);\n\n        if (!v and va < 0 and vb <\
    \ 0) return false;\n        if (!v and !va and !vb) {\n            i += 1;\n \
    \       } else if (v >= 0) {\n            if (vb > 0)\n                i += 1;\n\
    \            else\n                j += 1;\n        } else {\n            if (va\
    \ > 0)\n                j += 1;\n            else\n                i += 1;\n \
    \       }\n    }\n    return false;\n}\n\nT norm(const Point &p) { return p.x\
    \ * p.x + p.y * p.y; }\nPoint projection(const Segment &l, const Point &p) {\n\
    \    T t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);\n    return l.a + (l.a -\
    \ l.b) * t;\n}\n\nPoint crossPoint(const Line &l, const Line &m) {\n    T A =\
    \ cross(l.b - l.a, m.b - m.a);\n    T B = cross(l.b - l.a, l.b - m.a);\n    if\
    \ (A == 0 and B == 0) return m.a;\n    return m.a + (m.b - m.a) * (B / A);\n}\n\
    \nPoint crossPoint(const Segment &l, const Segment &m) {\n    return crossPoint(Line(l),\
    \ Line(m));\n}\n\nbool isConvex(const Points &p) {\n    int n = (int)p.size();\n\
    \    for (int i = 0; i < n; i++) {\n        if (ccw(p[(i + n - 1) % n], p[i],\
    \ p[(i + 1) % n]) == -1) return false;\n    }\n    return true;\n}\n\nPoints convexHull(Points\
    \ p) {\n    int n = p.size(), k = 0;\n    if (n <= 2) return p;\n    std::sort(begin(p),\
    \ end(p),\n              [](pt x, pt y) { return (x.x != y.x ? x.x < y.x : x.y\
    \ < y.y); });\n    Points ch(2 * n);\n    for (int i = 0; i < n; ch[k++] = p[i++])\
    \ {\n        while (k >= 2 && cross(ch[k - 1] - ch[k - 2], p[i] - ch[k - 1]) <=\
    \ 0)\n            --k;\n    }\n    for (int i = n - 2, t = k + 1; i >= 0; ch[k++]\
    \ = p[i--]) {\n        while (k >= t && cross(ch[k - 1] - ch[k - 2], p[i] - ch[k\
    \ - 1]) <= 0)\n            --k;\n    }\n    ch.resize(k - 1);\n    return ch;\n\
    }\n\nT area2(const Points &p) {\n    T res = 0;\n    for (int i = 0; i < (int)p.size();\
    \ i++) {\n        res += cross(p[i], p[i == int(size(p)) - 1 ? 0 : i + 1]);\n\
    \    }\n    return res;\n}\n\nenum { _OUT, _ON, _IN };\n\nint containsHullPoint(const\
    \ Polygon &Q, const Point &p) {\n    // Brute Force : O(|Q|)\n    bool in = false;\n\
    \    for (int i = 0; i < Q.size(); i++) {\n        Point a = Q[i] - p, b = Q[(i\
    \ + 1) % Q.size()] - p;\n        if (a.y > b.y) std::swap(a, b);\n        if (a.y\
    \ <= 0 && 0 < b.y && cross(a, b) < 0) in = !in;\n        if (cross(a, b) == 0\
    \ && dot(a, b) <= 0) return _ON;\n    }\n    return in ? _IN : _OUT;\n}\n\nPolygon\
    \ minkowskiSum(const Polygon &P, const Polygon &Q) {\n    std::vector<Segment>\
    \ e1(P.size()), e2(Q.size()), ed(P.size() + Q.size());\n    const auto cmp = [](const\
    \ Segment &u, const Segment &v) {\n        return (u.b - u.a).arg_cmp(v.b - v.a);\n\
    \    };\n    for (int i = 0; i < int(P.size()); i++)\n        e1[i] = {P[i], P[(i\
    \ + 1) % P.size()]};\n    for (int i = 0; i < int(Q.size()); i++)\n        e2[i]\
    \ = {Q[i], Q[(i + 1) % Q.size()]};\n    std::rotate(begin(e1), std::min_element(begin(e1),\
    \ end(e1), cmp), end(e1));\n    std::rotate(begin(e2), std::min_element(begin(e2),\
    \ end(e2), cmp), end(e2));\n    std::merge(begin(e1), end(e1), begin(e2), end(e2),\
    \ begin(ed), cmp);\n    const auto check = [](const Points &res, const Point &u)\
    \ {\n        const auto back1 = res.back(), back2 = *prev(end(res), 2);\n    \
    \    return equal(cross(back1 - back2, u - back2), eps) and\n               dot(back1\
    \ - back2, u - back1) >= -eps;\n    };\n    auto u = e1[0].a + e2[0].a;\n    Points\
    \ res{u};\n    res.reserve(P.size() + Q.size());\n    for (const auto &v : ed)\
    \ {\n        u = u + v.b - v.a;\n        while (int(size(res)) >= 2 and check(res,\
    \ u)) res.pop_back();\n        res.emplace_back(u);\n    }\n    if (res.size()\
    \ and check(res, res[0])) res.pop_back();\n    return res;\n}\n\n// -1 : on, 0\
    \ : out, 1 : in\n// O(log(n))\nint containsHullPointFast(const Polygon &p, const\
    \ Point &a) {\n    // Binary Search O(log|P|)\n    if (p.size() == 1) return a\
    \ == p[0] ? -1 : 0;\n    if (p.size() == 2) return intersect(Segment(p[0], p[1]),\
    \ a);\n    if (a == p[0]) return -1;\n    if ((p[1] - p[0]).toleft(a - p[0]) ==\
    \ -1 ||\n        (p.back() - p[0]).toleft(a - p[0]) == 1)\n        return 0;\n\
    \    const auto cmp = [&](const Point &u, const Point &v) {\n        return (u\
    \ - p[0]).toleft(v - p[0]) == 1;\n    };\n    const size_t i = lower_bound(p.begin()\
    \ + 1, p.end(), a, cmp) - p.begin();\n    if (i == 1) return intersect(Segment(p[0],\
    \ p[i]), a) ? -1 : 0;\n    if (i == p.size() - 1 && intersect(Segment(p[0], p[i]),\
    \ a)) return -1;\n    if (intersect(Segment(p[i - 1], p[i]), a)) return -1;\n\
    \    return (p[i] - p[i - 1]).toleft(a - p[i - 1]) > 0;\n}\n\nPoints halfplaneIntersection(std::vector<Line>\
    \ L, const T inf = 1e9) {\n    // left half plane\n    Point box[4] = {Point(inf,\
    \ inf), Point(-inf, inf), Point(-inf, -inf),\n                    Point(inf, -inf)};\n\
    \    for (int i = 0; i < 4; i++) {\n        L.emplace_back(box[i], box[(i + 1)\
    \ % 4]);\n    }\n    std::sort(begin(L), end(L), [](const Line &l, const Line\
    \ &r) {\n        return (l.b - l.a).arg_cmp(r.b - r.a);\n    });\n    std::deque<Line>\
    \ dq;\n    int len = 0;\n    auto check = [](const Line &a, const Line &b, const\
    \ Line &c) {\n        return a.toleft(crossPoint(b, c)) == -1;\n    };\n    for\
    \ (int i = 0; i < (int)L.size(); i++) {\n        while (dq.size() > 1 and check(L[i],\
    \ *(end(dq) - 2), *(end(dq) - 1)))\n            dq.pop_back();\n        while\
    \ (dq.size() > 1 and check(L[i], dq[0], dq[1])) dq.pop_front();\n        // dump(L[i],\
    \ si(dq));\n\n        if (dq.size() and\n            equal(cross(L[i].b - L[i].a,\
    \ dq.back().b - dq.back().a), 0)) {\n            if (dot(L[i].b - L[i].a, dq.back().b\
    \ - dq.back().a) < eps)\n                return {};\n            if (L[i].toleft(dq.back().a)\
    \ == -1)\n                dq.pop_back();\n            else\n                continue;\n\
    \        }\n        dq.emplace_back(L[i]);\n    }\n\n    while (dq.size() > 2\
    \ and check(dq[0], *(end(dq) - 2), *(end(dq) - 1)))\n        dq.pop_back();\n\
    \    while (dq.size() > 2 and check(dq.back(), dq[0], dq[1])) dq.pop_front();\n\
    \    if ((int)size(dq) < 3) return {};\n    Polygon ret(dq.size());\n    for (int\
    \ i = 0; i < (int)dq.size(); i++)\n        ret[i] = crossPoint(dq[i], dq[(i +\
    \ 1) % dq.size()]);\n\n    return ret;\n}\n} \n"
  code: "#pragma once\n\n#include \"../Template/Template.hpp\"\n\nnamespace Geometry\
    \ {\n// using T = i64;\n// constexpr T eps = 0;\n\nusing T = double;\nconstexpr\
    \ T eps = 1E-10;\n\nbool equal(const T &x, const T &y) { return abs(x - y) <=\
    \ eps; }\nint sgn(T x) { return (x > 0) - (x < 0); }\ninline constexpr int type(T\
    \ x, T y) {\n    if (x == 0 and y == 0) return 0;\n    if (y < 0 or (y == 0 and\
    \ x > 0)) return -1;\n    return 1;\n}\nstruct Point {\n    T x, y;\n    constexpr\
    \ Point(T _x = 0, T _y = 0) : x(_x), y(_y) {}\n    constexpr Point operator+()\
    \ const noexcept { return *this; }\n    constexpr Point operator-() const noexcept\
    \ { return Point(-x, -y); }\n    constexpr Point operator+(const Point &p) const\
    \ {\n        return Point(x + p.x, y + p.y);\n    }\n    constexpr Point operator-(const\
    \ Point &p) const {\n        return Point(x - p.x, y - p.y);\n    }\n    constexpr\
    \ Point &operator+=(const Point &p) {\n        return x += p.x, y += p.y, *this;\n\
    \    }\n    constexpr Point &operator-=(const Point &p) {\n        return x -=\
    \ p.x, y -= p.y, *this;\n    }\n    constexpr T operator*(const Point &p) const\
    \ { return x * p.x + y * p.y; }\n    const Point operator/(T d) const { return\
    \ Point(x / d, y / d); }\n    constexpr Point &operator*=(const T &k) { return\
    \ x *= k, y *= k, *this; }\n    constexpr Point operator*(const T &k) { return\
    \ Point(x * k, y * k); }\n    constexpr bool operator==(const Point &r) const\
    \ noexcept {\n        return r.x == x and r.y == y;\n    }\n    constexpr bool\
    \ operator!=(const Point &r) const noexcept {\n        return !(*this == r);\n\
    \    }\n    constexpr T cross(const Point &r) const { return x * r.y - y * r.x;\
    \ }\n    constexpr T cross(Point a, Point b) const {\n        return (a - *this).cross(b\
    \ - *this);\n    }\n    constexpr bool operator<(const Point &r) const {\n   \
    \     return std::pair(x, y) < std::pair(r.x, r.y);\n    }\n\n    // 1 : left,\
    \ 0 : same, -1 : right\n    constexpr int toleft(const Point &r) const {\n   \
    \     auto t = cross(r);\n        return t > eps ? 1 : t < -eps ? -1 : 0;\n  \
    \  }\n\n    constexpr bool arg_cmp(const Point &r) const {\n        int L = type(x,\
    \ y), R = type(r.x, r.y);\n        if (L != R) return L < R;\n\n        T X =\
    \ x * r.y, Y = r.x * y;\n        if (X != Y) return X > Y;\n        return x <\
    \ r.x;\n    }\n};\nbool arg_cmp(const Point &l, const Point &r) { return l.arg_cmp(r);\
    \ }\nstd::ostream &operator<<(std::ostream &os, const Point &p) {\n    return\
    \ os << p.x << \" \" << p.y;\n}\nstd::istream &operator>>(std::istream &is, Point\
    \ &p) {\n    is >> p.x >> p.y;\n    return is;\n}\n\nstruct Line {\n    Point\
    \ a, b;\n    Line() = default;\n    Line(Point a, Point b) : a(a), b(b) {}\n \
    \   // ax + by = c\n    Line(T A, T B, T C) {\n        if (A == 0) {\n       \
    \     a = Point(0, C / B), b = Point(1, C / B);\n        } else if (B == 0) {\n\
    \            a = Point(C / A, 0), b = Point(C / A, 1);\n        } else {\n   \
    \         a = Point(0, C / B), b = Point(C / A, 0);\n        }\n    }\n    //\
    \ 1 : left, 0 : same, -1 : right\n    constexpr int toleft(const Point &r) const\
    \ {\n        auto t = (b - a).cross(r - a);\n        return t > eps ? 1 : t <\
    \ -eps ? -1 : 0;\n    }\n\n    friend std::ostream &operator<<(std::ostream &os,\
    \ Line &ls) {\n        return os << \"{\"\n                  << \"(\" << ls.a.x\
    \ << \", \" << ls.a.y << \"), (\" << ls.b.x << \", \"\n                  << ls.b.y\
    \ << \")}\";\n    }\n};\nstd::istream &operator>>(std::istream &is, Line &p) {\
    \ return is >> p.a >> p.b; }\n\nstruct Segment : Line {\n    Segment() = default;\n\
    \    Segment(Point a, Point b) : Line(a, b) {}\n};\n\nstd::ostream &operator<<(std::ostream\
    \ &os, Segment &p) {\n    return os << p.a << \" to \" << p.b;\n}\nstd::istream\
    \ &operator>>(std::istream &is, Segment &p) {\n    is >> p.a >> p.b;\n    return\
    \ is;\n}\n\nstruct Circle {\n    Point p;\n    T r;\n    Circle() = default;\n\
    \    Circle(Point p, T r) : p(p), r(r) {}\n};\n\nusing pt = Point;\nusing Points\
    \ = std::vector<pt>;\nusing Polygon = Points;\nT cross(const pt &x, const pt &y)\
    \ { return x.x * y.y - x.y * y.x; }\nT dot(const pt &x, const pt &y) { return\
    \ x.x * y.x + x.y * y.y; }\n\nT abs2(const pt &x) { return dot(x, x); }\n\nint\
    \ ccw(const Point &a, Point b, Point c) {\n    b = b - a, c = c - a;\n    if (cross(b,\
    \ c) > 0) return +1;    // \"COUNTER_CLOCKWISE\"\n    if (cross(b, c) < 0) return\
    \ -1;    // \"CLOCKWISE\"\n    if (dot(b, c) < 0) return +2;      // \"ONLINE_BACK\"\
    \n    if (abs2(b) < abs2(c)) return -2;  // \"ONLINE_FRONT\"\n    return 0;  \
    \                        // \"ON_SEGMENT\"\n}\n\nbool parallel(const Line &a,\
    \ const Line &b) {\n    return (cross(a.b - a.a, b.b - b.a) == 0);\n}\n\nbool\
    \ orthogonal(const Line &a, const Line &b) {\n    return (dot(a.a - a.b, b.a -\
    \ b.b) == 0);\n}\n\nbool intersect(const Line &l, const Point &p) {\n    return\
    \ abs(ccw(l.a, l.b, p)) != 1;\n}\n\nbool intersect(const Line &l, const Line &m)\
    \ { return !parallel(l, m); }\n\nbool intersect(const Segment &s, const Point\
    \ &p) {\n    return ccw(s.a, s.b, p) == 0;\n}\n\nbool intersect(const Line &l,\
    \ const Segment &s) {\n    return cross(l.b - l.a, s.a - l.a) * cross(l.b - l.a,\
    \ s.b - l.a) <= 0;\n}\n\nbool intersect(const Segment &s, const Segment &t) {\n\
    \    return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 &&\n           ccw(t.a,\
    \ t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;\n}\n\nstd::vector<Point> segInter(const\
    \ Segment &sa, const Segment &sb) {\n    // if no intersect point return {}\n\
    \    // if inf intersect points return two end point\n    auto a = sa.a, b = sa.b;\n\
    \    auto c = sb.a, d = sb.b;\n    auto oa = c.cross(d, a), ob = c.cross(d, b),\
    \ oc = a.cross(b, c),\n         od = a.cross(b, d);\n    if (sgn(oa) * sgn(ob)\
    \ < 0 && sgn(oc) * sgn(od) < 0)\n        return {(a * ob - b * oa) / (ob - oa)};\n\
    \    std::set<Point> s;\n    if (intersect(Segment(c, d), a)) s.insert(a);\n \
    \   if (intersect(Segment(c, d), b)) s.insert(b);\n    if (intersect(Segment(a,\
    \ b), c)) s.insert(c);\n    if (intersect(Segment(a, b), d)) s.insert(d);\n  \
    \  return {begin(s), end(s)};\n}\n\nbool intersect(const Polygon &ps, const Polygon\
    \ &qs) {\n    int pl = size(ps), ql = size(qs), i = 0, j = 0;\n    while ((i <\
    \ pl or j < ql) and (i < 2 * pl) and (j < 2 * ql)) {\n        auto ps0 = ps[(i\
    \ + pl - 1) % pl], ps1 = ps[i % pl];\n        auto qs0 = qs[(j + ql - 1) % ql],\
    \ qs1 = qs[j % ql];\n        if (intersect(Segment(ps0, ps1), Segment(qs0, qs1)))\
    \ return true;\n        Point a = ps1 - ps0;\n        Point b = qs1 - qs0;\n \
    \       T v = cross(a, b);\n        T va = cross(qs1 - qs0, ps1 - qs0);\n    \
    \    T vb = cross(ps1 - ps0, qs1 - ps0);\n\n        if (!v and va < 0 and vb <\
    \ 0) return false;\n        if (!v and !va and !vb) {\n            i += 1;\n \
    \       } else if (v >= 0) {\n            if (vb > 0)\n                i += 1;\n\
    \            else\n                j += 1;\n        } else {\n            if (va\
    \ > 0)\n                j += 1;\n            else\n                i += 1;\n \
    \       }\n    }\n    return false;\n}\n\nT norm(const Point &p) { return p.x\
    \ * p.x + p.y * p.y; }\nPoint projection(const Segment &l, const Point &p) {\n\
    \    T t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);\n    return l.a + (l.a -\
    \ l.b) * t;\n}\n\nPoint crossPoint(const Line &l, const Line &m) {\n    T A =\
    \ cross(l.b - l.a, m.b - m.a);\n    T B = cross(l.b - l.a, l.b - m.a);\n    if\
    \ (A == 0 and B == 0) return m.a;\n    return m.a + (m.b - m.a) * (B / A);\n}\n\
    \nPoint crossPoint(const Segment &l, const Segment &m) {\n    return crossPoint(Line(l),\
    \ Line(m));\n}\n\nbool isConvex(const Points &p) {\n    int n = (int)p.size();\n\
    \    for (int i = 0; i < n; i++) {\n        if (ccw(p[(i + n - 1) % n], p[i],\
    \ p[(i + 1) % n]) == -1) return false;\n    }\n    return true;\n}\n\nPoints convexHull(Points\
    \ p) {\n    int n = p.size(), k = 0;\n    if (n <= 2) return p;\n    std::sort(begin(p),\
    \ end(p),\n              [](pt x, pt y) { return (x.x != y.x ? x.x < y.x : x.y\
    \ < y.y); });\n    Points ch(2 * n);\n    for (int i = 0; i < n; ch[k++] = p[i++])\
    \ {\n        while (k >= 2 && cross(ch[k - 1] - ch[k - 2], p[i] - ch[k - 1]) <=\
    \ 0)\n            --k;\n    }\n    for (int i = n - 2, t = k + 1; i >= 0; ch[k++]\
    \ = p[i--]) {\n        while (k >= t && cross(ch[k - 1] - ch[k - 2], p[i] - ch[k\
    \ - 1]) <= 0)\n            --k;\n    }\n    ch.resize(k - 1);\n    return ch;\n\
    }\n\nT area2(const Points &p) {\n    T res = 0;\n    for (int i = 0; i < (int)p.size();\
    \ i++) {\n        res += cross(p[i], p[i == int(size(p)) - 1 ? 0 : i + 1]);\n\
    \    }\n    return res;\n}\n\nenum { _OUT, _ON, _IN };\n\nint containsHullPoint(const\
    \ Polygon &Q, const Point &p) {\n    // Brute Force : O(|Q|)\n    bool in = false;\n\
    \    for (int i = 0; i < Q.size(); i++) {\n        Point a = Q[i] - p, b = Q[(i\
    \ + 1) % Q.size()] - p;\n        if (a.y > b.y) std::swap(a, b);\n        if (a.y\
    \ <= 0 && 0 < b.y && cross(a, b) < 0) in = !in;\n        if (cross(a, b) == 0\
    \ && dot(a, b) <= 0) return _ON;\n    }\n    return in ? _IN : _OUT;\n}\n\nPolygon\
    \ minkowskiSum(const Polygon &P, const Polygon &Q) {\n    std::vector<Segment>\
    \ e1(P.size()), e2(Q.size()), ed(P.size() + Q.size());\n    const auto cmp = [](const\
    \ Segment &u, const Segment &v) {\n        return (u.b - u.a).arg_cmp(v.b - v.a);\n\
    \    };\n    for (int i = 0; i < int(P.size()); i++)\n        e1[i] = {P[i], P[(i\
    \ + 1) % P.size()]};\n    for (int i = 0; i < int(Q.size()); i++)\n        e2[i]\
    \ = {Q[i], Q[(i + 1) % Q.size()]};\n    std::rotate(begin(e1), std::min_element(begin(e1),\
    \ end(e1), cmp), end(e1));\n    std::rotate(begin(e2), std::min_element(begin(e2),\
    \ end(e2), cmp), end(e2));\n    std::merge(begin(e1), end(e1), begin(e2), end(e2),\
    \ begin(ed), cmp);\n    const auto check = [](const Points &res, const Point &u)\
    \ {\n        const auto back1 = res.back(), back2 = *prev(end(res), 2);\n    \
    \    return equal(cross(back1 - back2, u - back2), eps) and\n               dot(back1\
    \ - back2, u - back1) >= -eps;\n    };\n    auto u = e1[0].a + e2[0].a;\n    Points\
    \ res{u};\n    res.reserve(P.size() + Q.size());\n    for (const auto &v : ed)\
    \ {\n        u = u + v.b - v.a;\n        while (int(size(res)) >= 2 and check(res,\
    \ u)) res.pop_back();\n        res.emplace_back(u);\n    }\n    if (res.size()\
    \ and check(res, res[0])) res.pop_back();\n    return res;\n}\n\n// -1 : on, 0\
    \ : out, 1 : in\n// O(log(n))\nint containsHullPointFast(const Polygon &p, const\
    \ Point &a) {\n    // Binary Search O(log|P|)\n    if (p.size() == 1) return a\
    \ == p[0] ? -1 : 0;\n    if (p.size() == 2) return intersect(Segment(p[0], p[1]),\
    \ a);\n    if (a == p[0]) return -1;\n    if ((p[1] - p[0]).toleft(a - p[0]) ==\
    \ -1 ||\n        (p.back() - p[0]).toleft(a - p[0]) == 1)\n        return 0;\n\
    \    const auto cmp = [&](const Point &u, const Point &v) {\n        return (u\
    \ - p[0]).toleft(v - p[0]) == 1;\n    };\n    const size_t i = lower_bound(p.begin()\
    \ + 1, p.end(), a, cmp) - p.begin();\n    if (i == 1) return intersect(Segment(p[0],\
    \ p[i]), a) ? -1 : 0;\n    if (i == p.size() - 1 && intersect(Segment(p[0], p[i]),\
    \ a)) return -1;\n    if (intersect(Segment(p[i - 1], p[i]), a)) return -1;\n\
    \    return (p[i] - p[i - 1]).toleft(a - p[i - 1]) > 0;\n}\n\nPoints halfplaneIntersection(std::vector<Line>\
    \ L, const T inf = 1e9) {\n    // left half plane\n    Point box[4] = {Point(inf,\
    \ inf), Point(-inf, inf), Point(-inf, -inf),\n                    Point(inf, -inf)};\n\
    \    for (int i = 0; i < 4; i++) {\n        L.emplace_back(box[i], box[(i + 1)\
    \ % 4]);\n    }\n    std::sort(begin(L), end(L), [](const Line &l, const Line\
    \ &r) {\n        return (l.b - l.a).arg_cmp(r.b - r.a);\n    });\n    std::deque<Line>\
    \ dq;\n    int len = 0;\n    auto check = [](const Line &a, const Line &b, const\
    \ Line &c) {\n        return a.toleft(crossPoint(b, c)) == -1;\n    };\n    for\
    \ (int i = 0; i < (int)L.size(); i++) {\n        while (dq.size() > 1 and check(L[i],\
    \ *(end(dq) - 2), *(end(dq) - 1)))\n            dq.pop_back();\n        while\
    \ (dq.size() > 1 and check(L[i], dq[0], dq[1])) dq.pop_front();\n        // dump(L[i],\
    \ si(dq));\n\n        if (dq.size() and\n            equal(cross(L[i].b - L[i].a,\
    \ dq.back().b - dq.back().a), 0)) {\n            if (dot(L[i].b - L[i].a, dq.back().b\
    \ - dq.back().a) < eps)\n                return {};\n            if (L[i].toleft(dq.back().a)\
    \ == -1)\n                dq.pop_back();\n            else\n                continue;\n\
    \        }\n        dq.emplace_back(L[i]);\n    }\n\n    while (dq.size() > 2\
    \ and check(dq[0], *(end(dq) - 2), *(end(dq) - 1)))\n        dq.pop_back();\n\
    \    while (dq.size() > 2 and check(dq.back(), dq[0], dq[1])) dq.pop_front();\n\
    \    if ((int)size(dq) < 3) return {};\n    Polygon ret(dq.size());\n    for (int\
    \ i = 0; i < (int)dq.size(); i++)\n        ret[i] = crossPoint(dq[i], dq[(i +\
    \ 1) % dq.size()]);\n\n    return ret;\n}\n} "
  dependsOn:
  - Template/Template.hpp
  isVerificationFile: false
  path: Geometry/GeometryTemplate.hpp
  requiredBy: []
  timestamp: '2023-04-13 01:55:49+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/GeometryTemplate.hpp
layout: document
redirect_from:
- /library/Geometry/GeometryTemplate.hpp
- /library/Geometry/GeometryTemplate.hpp.html
title: Geometry/GeometryTemplate.hpp
---
