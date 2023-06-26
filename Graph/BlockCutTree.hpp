#pragma once

#include "../Template/Template.hpp"
template <class G>
struct BlockCutTree {
    G tree;
    std::vector<int> dfn, low;
    std::vector<int> ar;  // cut vertex 1/0
    std::vector<int> idar, idcc;

    std::vector<std::vector<int>> bcc;
    std::vector<std::vector<int>> aux;  // block cut tree
    BlockCutTree(const G& tree) : tree(tree) {
        int sz = tree.size();
        dfn.assign(sz, -1);
        low.assign(sz, -1);
        ar.assign(sz, 0);
        idar.assign(sz, -1);
        idcc.assign(sz, -1);

        build();
    }
    void build() {
        int cnt = 0;
        std::stack<int> st;
        auto dfs = [&](auto&& self, int u, int fa) -> void {
            dfn[u] = low[u] = cnt++;
            int childCnt = 0;
            st.push(u);
            for (const auto& v : tree[u]) {
                if (v == fa) continue;
                if (dfn[v] == -1) {
                    childCnt++;
                    self(self, v, u);
                    low[u] = std::min(low[u], low[v]);
                    if (low[v] >= dfn[u]) {
                        ar[u] = 1;
                        std::vector<int> curBcc;
                        while (true) {
                            int cur = st.top();
                            curBcc.push_back(cur);
                            st.pop();
                            if (cur == v) break;
                        }
                        curBcc.push_back(u);
                        bcc.push_back(curBcc);
                    }
                } else
                    low[u] = std::min(low[u], dfn[v]);
            }
            if (fa < 0 && childCnt < 2) ar[u] = 0;
        };
        for (int i = 0; i < (int)tree.size(); i++) {
            if (dfn[i] == -1) dfs(dfs, i, -1);
        }

        std::vector<int> arSet;
        for (int i = 0; i < (int)ar.size(); i++)
            if (ar[i]) arSet.push_back(i);

        for (int i = 0; i < (int)arSet.size(); i++) idar[arSet[i]] = i;

        aux.resize(arSet.size() + bcc.size());
        std::vector<int> last(tree.size(), -1);

        for (int i = 0; i < (int)bcc.size(); i++) {
            auto add = [&](int i, int j) {
                if (i == -1 or j == -1) return;
                aux[i].push_back(j);
                aux[j].push_back(i);
                return;
            };
            for (const auto& u : bcc[i]) {
                if (idar[u] == -1)
                    idcc[u] = i + (int)arSet.size();
                else if (last[u] != i) {
                    add(i + (int)arSet.size(), idar[u]);
                    last[u] = i;
                }
            }
        }
    }
    std::vector<int>& operator[](int i) { return aux[i]; }
    int size() const { return aux.size(); }
    int id(int i) { return idar[i] == -1 ? idcc[i] : idar[i]; }
    bool is_arti(int i) { return idar[i] != -1; }
};