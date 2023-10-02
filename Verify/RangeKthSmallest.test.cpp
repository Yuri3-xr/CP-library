#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

#include "../DataStructure/PersistentSegmentTree.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    PersistentSegmentTree SegmentTree(a);
    while (q--) {
        int l, r, k;
        std::cin >> l >> r >> k;
        std::cout << SegmentTree.rangeKth(l, r, k + 1).first << std::endl;
    }

    return 0;
}