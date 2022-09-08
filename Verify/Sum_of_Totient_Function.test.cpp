#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_totient_function"

#include "../ModInt/Modint32.hpp"
#include "../Number_Theory/Mf_Sieve.hpp"
#include "../Template/Template.hpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    constexpr int mod = 998244353;
    using Z = mint<mod>;

    i64 n;
    cin >> n;

    int TH = (int)pow(n, 2.0 / 3.0);

    auto f = [&](i64 n, i64 p, i64 c) -> Z { return Z(n - n / p); };
    auto phi = mf_sieve<Z>(TH, f);
    vector<Z> dphi(phi.size());
    for (int i = 1; i <= TH; i++) dphi[i] = dphi[i - 1] + phi[i];

    const Z inv2 = Z(2).inverse();
    unordered_map<i64, Z> mp;
    function<Z(i64)> dfs = [&](i64 x) -> Z {
        if (mp.count(x)) return mp[x];
        if (x <= TH) return dphi[x];
        Z ans = Z(x) * Z(x + 1) * inv2;
        for (i64 l = 2, r; l <= x; l = r + 1) {
            r = x / (x / l);
            ans -= dfs(x / l) * Z(r - l + 1);
        }
        return mp[x] = ans;
    };

    cout << dfs(n) << '\n';

    return 0;
}