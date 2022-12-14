#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"

#include "../String/SuffixArrayFast.hpp"
#include "../Template/Template.hpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    SuffixArrayFast<string> SA(s);

    i64 ans = 1ll * (SA.n + 1) * (SA.n) / 2;
    for (int i = 0; i < SA.n - 1; i++) {
        ans -= SA.lc[i];
    }

    cout << ans << '\n';

    return 0;
}