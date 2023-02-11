#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../DataStructure/SegmentTree.hpp"
#include "../Template/Template.hpp"

struct Info {
    i64 x = 0;
};
Info operator+(const Info& a, const Info& b) { return {a.x + b.x}; }

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;
    std::vector<Info> a(n);
    for (auto&& it : a) std::cin >> it.x;
    SegmentTree<Info> st(a);

    while (q--) {
        int op;
        std::cin >> op;
        if (op == 0) {
            int p, x;
            std::cin >> p >> x;
            st.update(p, {st[p].x + x});
        } else {
            int l, r;
            std::cin >> l >> r;
            std::cout << st.query(l, r).x << '\n';
        }
    }

    return 0;
}