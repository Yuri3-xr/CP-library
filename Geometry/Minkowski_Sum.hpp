#pragma once

#include "../Template/Template.hpp"
#include "Point.hpp"

constexpr double EPS = 1E-6;
template <class P>
std::vector<P> Minkowski_Sum(const std::vector<P>& a, const std::vector<P>& b) {
    std::vector<P> res;
    auto sgnp = [&](P a) -> int {
        return (a.y > 0 || (a.y == 0 && a.x > 0) ? 1 : -1);
    };
    auto argcmp = [&](P a, P b) {
        return sgnp(a) != sgnp(b) ? sgnp(a) == 1 : a.cross(b) > EPS;
    };
    std::vector<pair<P, P>> e1(a.size()), e2(b.size()),
        edge(a.size() + b.size());
    auto cmp = [&](const pair<P, P>& u, const pair<P, P>& v) {
        return argcmp(u.second - u.first, v.second - v.first);
    };
    for (size_t i = 0; i < a.size(); i++) e1[i] = {a[i], a[(i + 1) % a.size()]};
    for (size_t i = 0; i < b.size(); i++) e2[i] = {b[i], b[(i + 1) % b.size()]};
    std::rotate(e1.begin(), min_element(e1.begin(), e1.end(), cmp), e1.end());
    std::rotate(e2.begin(), min_element(e2.begin(), e2.end(), cmp), e2.end());
    merge(e1.begin(), e1.end(), e2.begin(), e2.end(), edge.begin(), cmp);
    const auto check = [&](const std::vector<P>& res, const P& u) {
        const auto back1 = res.back(), back2 = *prev(res.end(), 2);
        return sgn<double>((back1 - back2).cross(u - back1)) == 0 &&
               (back1 - back2) * (u - back1) > -EPS;
    };
    auto u = e1[0].first + e2[0].first;
    for (auto& v : edge) {
        while (res.size() > 1 && check(res, u)) res.pop_back();
        res.push_back(u);
        u = u + v.second - v.first;
    }
    if (res.size() > 1 && check(res, res[0])) res.pop_back();
    return res;
};