#define PROBLEM "https://judge.yosupo.jp/problem/min_of_mod_of_linear"

#include "../Number_Theory/MinofMod.hpp"

void solve() {
    i64 n, m, a, b;
    cin >> n >> m >> a >> b;
    auto [x, fx] = min_of_linear<i64>(0, n, a, b, m);
    cout << fx << '\n';
    assert((a * x + b) % m == fx);
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
