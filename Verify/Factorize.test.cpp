#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

#include "../Number_Theory/Factorization.hpp"
#include "../Template/Template.hpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _;
    cin >> _;
    while (_--) {
        i64 x;
        cin >> x;
        auto ans = factorization<i64>(x);
        sort(begin(ans), end(ans));

        cout << ans.size() << '\n';
        for (int i = 0; i < (int)ans.size(); i++) {
            cout << ans[i] << " \n"[i == (int)ans.size() - 1];
        }
    }

    return 0;
}
