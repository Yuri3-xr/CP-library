#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../DataStructure/SegmentTree.hpp"
#include "../Template/Template.hpp"

struct Info {
    i64 x = 0;
};
Info operator+(const Info& a, const Info& b) { return {a.x + b.x}; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<Info> a(n);
    for (auto&& it : a) cin >> it.x;
    SegmentTree<Info> st(a);

    while (q--) {
        int op;
        cin >> op;
        if (op == 0) {
            int p, x;
            cin >> p >> x;
            st.update(p, {st[p].x + x});
        } else {
            int l, r;
            cin >> l >> r;
            cout << st.query(l, r).x << '\n';
        }
    }

    return 0;
}