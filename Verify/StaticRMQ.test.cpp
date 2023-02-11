#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../DataStructure/RMQ.hpp"
#include "../Template/Template.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    for (auto&& it : a) std::cin >> it;
    RMQ<int> rmq(a);

    while (q--) {
        int l, r;
        std::cin >> l >> r;
        std::cout << rmq.rangeMin(l, r) << '\n';
    }

    return 0;
}