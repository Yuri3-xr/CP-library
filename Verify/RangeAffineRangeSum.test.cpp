#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include "../DataStructure/LazySegmentTree.hpp"
#include "../ModInt/Modint32.hpp"
#include "../Template/Template.hpp"

constexpr int mod = 998244353;
using Z = mint<mod>;
struct Tag {
    Z x = 1;
    Z y = 0;
    void apply(const Tag& a) {
        x = x * a.x;
        y = a.x * y + a.y;
    }
};
struct Info {
    Z x = 0;
    int l, r;
    void apply(const Tag& a) {
        x *= a.x;
        x += Z(r - l) * a.y;
    }
};
Info operator+(const Info& a, const Info& b) { return {a.x + b.x, a.l, b.r}; }
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;

    std::vector<Info> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].x;
        a[i].l = i;
        a[i].r = i + 1;
    }

    LazySegmentTree<Info, Tag> t(a);

    for (int i = 1; i <= q; i++) {
        int op;
        std::cin >> op;
        if (op == 0) {
            int l, r, b, c;
            std::cin >> l >> r >> b >> c;
            t.rangeApply(l, r, Tag{b, c});
        }
        if (op == 1) {
            int l, r;
            std::cin >> l >> r;
            auto ans = t.rangeQuery(l, r);
            std::cout << ans.x << '\n';
        }
    }

    return 0;
}