#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include "../Magic/Poly.hpp"
#include "../ModInt/Modint32.hpp"
#include "../Template/Template.hpp"

constexpr int mod = 998244353;

using Z = ModInt<mod>;
int main() {
    int n, m;
    cin >> n >> m;

    vector<Z> a(n), b(m);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    auto ans = Poly(a) * Poly(b);

    for (int i = 0; i < (int)(ans.size()); i++)
        cout << ans[i] << " \n"[i == (int)ans.size() - 1];
}