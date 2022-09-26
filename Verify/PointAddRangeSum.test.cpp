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
    SegmentTree<Info> St(a);

    while (q--) {
        int op;
        cin >> op;
        if (op == 0) {
            int p, x;
            cin >> p >> x;
            St.modify(p, {St.rangeQuery(p, p + 1).x + x});
        } else {
            int l, r;
            cin >> l >> r;
            cout << St.rangeQuery(l, r).x << '\n';
        }
    }
}