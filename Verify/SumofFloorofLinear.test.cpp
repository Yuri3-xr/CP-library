#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_floor_of_linear"

#include "../Number_Theory/SumofFloor.hpp"

void solve() {
    i64 n, m, a, b;
    std::cin >> n >> m >> a >> b;
    auto ans = sum_of_floor<i64>(n, m, a, b);
    std::cout << ans << '\n';
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}