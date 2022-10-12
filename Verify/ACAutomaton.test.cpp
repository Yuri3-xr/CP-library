#define PROBLEM "https://yukicoder.me/problems/no/430"

#include "../String/ACAutomaton.hpp"

#include "../Template/Template.hpp"

struct TrieNode {
    TrieNode() { id = 0, dep = 0, nxt = array<int, 26>(); };
    TrieNode(int _id, int _dep) : id(_id), dep(_dep) {}
    int id;
    int dep;
    array<int, 26> nxt = {};
    int &operator[](const int x) { return this->nxt[x]; }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int m;
    cin >> s >> m;

    ACAutomaton<TrieNode> ac;
    vector<int> pos(m + 1);
    for (int i = 1; i <= m; i++) {
        string res;
        cin >> res;
        pos[i] = ac.add(res);
    }
    ac.BuildAC();

    vector<int> val(ac.size());
    vector<vector<int>> adj(ac.size());
    for (int i = 0; i < ac.size(); i++) {
        if (i != ac.fail[i]) adj[ac.fail[i]].push_back(i);
    }

    int p = 0;
    for (auto it : s) {
        p = ac.tr[p][it - 'A'];
        val[p]++;
    }

    function<void(int)> dfs = [&](int u) {
        for (auto v : adj[u]) {
            dfs(v);
            val[u] += val[v];
        }
    };
    dfs(0);

    int ans = 0;

    for (int i = 1; i <= m; i++) ans += val[pos[i]];
    cout << ans << endl;

    return 0;
}