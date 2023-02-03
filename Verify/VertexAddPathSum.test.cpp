#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include "../DataStructure/SegmentTree.hpp"
#include "../Template/Template.hpp"
#include "../Tree/HeavyLightDecomposition.hpp"

struct Info {
    i64 x = 0;
    Info& operator+=(const Info& a) {
        x += a.x;
        return *this;
    }
};
Info operator+(const Info& a, const Info& b) { return {a.x + b.x}; }

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;

    std::vector<i64> val(n);
    std::vector<Info> _init(n);

    for (int i = 0; i < n; i++) {
        std::cin >> val[i];
    }

    HLD hld(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        hld.addEdge(u, v);
    }

    hld.build();

    for (int i = 0; i < n; i++) {
        _init[hld.dfn[i]].x = val[i];
    }

    SegmentTree<Info> ST(_init);

    while (q--) {
        int op;
        std::cin >> op;
        if (op == 0) {
            int p, x;
            std::cin >> p >> x;
            ST.add(hld.dfn[p], {x});
        }
        if (op == 1) {
            int u, v;
            std::cin >> u >> v;

            i64 sum = 0;
            auto processSum = [&](int L, int R) -> void {
                sum += ST.query(L, R + 1).x;
            };

            hld.processP2P(u, v, processSum);
            std::cout << sum << '\n';
        }
    }

    return 0;
}