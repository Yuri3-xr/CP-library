#pragma once

template <class T>
struct DivSumSegmentTreeBeats {
    /*
        applyDiv(l,r,v) i \in [l,r) a_i = a_i/v (floor)
        applyGive(l,r,v) i \in [l,r) a_i = v (floor)
        rangeQuery(l,r) [l,r) sum
        Time Complexity: O(NKlogN) K = __LG(max(x))
        Verify: https://atcoder.jp/contests/abc256/tasks/abc256_h
    */
    const int n;
    vector<T> tmax, tmin, tag, tsum;
    DivSumSegmentTreeBeats(int n)
        : n(n),
          tmax(4 << __lg(n)),
          tmin(4 << __lg(n)),
          tag(4 << __lg(n), -1),
          tsum(4 << __lg(n)){};
    DivSumSegmentTreeBeats(const vector<T>& init)
        : DivSumSegmentTreeBeats(init.size()) {
        function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                tmax[p] = tmin[p] = tsum[p] = init[l];
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
        tmax[p] = max(tmax[p * 2], tmax[p * 2 + 1]);
        tmin[p] = min(tmin[p * 2], tmin[p * 2 + 1]);
        tsum[p] = tsum[p * 2] + tsum[p * 2 + 1];
        return;
    }
    void apply(int l, int r, int p, T v) {
        if (v != -1) {
            tmax[p] = tmin[p] = tag[p] = v;
            tsum[p] = T(r - l) * v;
        }
        return;
    }
    void push(int l, int r, int p) {
        if (tag[p] != -1) {
            int mid = (l + r) / 2;
            apply(l, mid, p * 2, tag[p]);
            apply(mid, r, p * 2 + 1, tag[p]);
            tag[p] = -1;
        }
        return;
    }
    void applyDiv(int p, int l, int r, int x, int y, const T v) {
        if (l >= y || r <= x) return;
        if (l >= x && r <= y) {
            if (tmax[p] == tmin[p]) {
                apply(l, r, p, tmax[p] / v);
                return;
            }
        }
        push(l, r, p);
        int mid = (l + r) / 2;
        applyDiv(p * 2, l, mid, x, y, v);
        applyDiv(p * 2 + 1, mid, r, x, y, v);
        pull(p);
    }
    void applyGive(int p, int l, int r, int x, int y, const T v) {
        if (l >= y || r <= x) return;
        if (l >= x && r <= y) {
            apply(l, r, p, v);
            return;
        }
        push(l, r, p);
        int mid = (l + r) / 2;
        applyGive(p * 2, l, mid, x, y, v);
        applyGive(p * 2 + 1, mid, r, x, y, v);
        pull(p);
    }
    void applyDiv(int l, int r, const T v) { applyDiv(1, 0, n, l, r, v); }
    void applyGive(int l, int r, const T v) { applyGive(1, 0, n, l, r, v); }
    T rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return T();
        }
        if (r - l > 1) push(l, r, p);
        if (l >= x && r <= y) {
            return tsum[p];
        }
        int m = (l + r) / 2;
        T ans = 0;
        ans = rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
        return ans;
    }
    T rangeQuery(int l, int r) { return rangeQuery(1, 0, n, l, r); }
};