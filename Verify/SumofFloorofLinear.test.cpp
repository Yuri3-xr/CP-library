#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_floor_of_linear"

#include "../Number_Theory/SumofFloor.hpp"

void solve() {
    i64 n, m, a, b;
    cin >> n >> m >> a >> b;
    auto ans = sum_of_floor<i64>(n, m, a, b);
    cout << ans << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}