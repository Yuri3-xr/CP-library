#pragma once

#include "../Template/Template.hpp"
template <class T>
struct AndOrSegmentTreeBeats {
    /*
        applyAnd(l,r,v) \forall x \in [l,r) x = x&v
        applyOr(l,r,v) \forall x \in [l,r) x = x|v
        rangeQuery(l,r)  max element  [l,r)
        Time Complexity: O(NKlogN) K = __LG(max(x))
        Verify: https://csacademy.com/contest/archive/task/and-or-max
    */
    const int n;
    vector<T> tor, tand, tag, mx;
    AndOrSegmentTreeBeats(int n)
        : n(n),
          tor(4 << __lg(n)),
          tand(4 << __lg(n)),
          tag(4 << __lg(n)),
          mx(4 << __lg(n)){};
    AndOrSegmentTreeBeats(const vector<T>& init)
        : AndOrSegmentTreeBeats(init.size()) {
        function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                tor[p] = tand[p] = mx[p] = init[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    void pull(int p) {
        tand[p] = tand[p * 2] & tand[p * 2 + 1];
        tor[p] = tor[p * 2] | tor[p * 2 + 1];
        mx[p] = max(mx[p * 2], mx[p * 2 + 1]);
        return;
    }
    void apply(int p, T v) {
        tag[p] += v;
        tand[p] += v;
        tor[p] += v;
        mx[p] += v;
        return;
    }
    void push(int p) {
        apply(p * 2, tag[p]);
        apply(p * 2 + 1, tag[p]);
        tag[p] = 0;
        return;
    }

    void applyAnd(int p, int l, int r, int x, int y, const T v) {
        if (l >= y || r <= x) {
            return;
        }
        if (r - l > 1) push(p);
        if ((tor[p] & v) == tor[p]) return;
        if (l >= x && r <= y) {
            if (((tand[p] & v) - tand[p]) == ((tor[p] & v) - tor[p])) {
                apply(p, ((tand[p] & v) - tand[p]));
                return;
            }
        }
        int mid = (l + r) / 2;
        applyAnd(p * 2, l, mid, x, y, v);
        applyAnd(p * 2 + 1, mid, r, x, y, v);
        pull(p);
    }
    void applyOr(int p, int l, int r, int x, int y, const T v) {
        if (l >= y || r <= x) {
            return;
        }
        if (r - l > 1) push(p);
        if ((tand[p] | v) == tand[p]) return;
        if (l >= x && r <= y) {
            if (((tand[p] | v) - tand[p]) == ((tor[p] | v) - tor[p])) {
                apply(p, ((tand[p] | v) - tand[p]));
                return;
            }
        }
        int mid = (l + r) / 2;
        applyOr(p * 2, l, mid, x, y, v);
        applyOr(p * 2 + 1, mid, r, x, y, v);
        pull(p);
    }
    void applyOr(int l, int r, const T v) { applyOr(1, 0, n, l, r, v); }
    void applyAnd(int l, int r, const T v) { applyAnd(1, 0, n, l, r, v); }
    T rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return T();
        }
        if (r - l > 1) push(p);
        if (l >= x && r <= y) {
            return mx[p];
        }
        int m = (l + r) / 2;
        return max(rangeQuery(2 * p, l, m, x, y),
                   rangeQuery(2 * p + 1, m, r, x, y));
    }
    T rangeQuery(int l, int r) { return rangeQuery(1, 0, n, l, r); }
};
