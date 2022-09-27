#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../DataStructure/RMQ.hpp"
#include "../Template/Template.hpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto&& it : a) cin >> it;
    RMQ<int> rmq(a);

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << rmq.rangeMin(l, r) << '\n';
    }

    return 0;
}