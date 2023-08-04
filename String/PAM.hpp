#pragma once

#include "../Template/Template.hpp"
struct PAM {
    struct node {
        std::array<int, 26> next;
        int len, fail;
        node(int L) {
            next.fill(0);
            len = L;
            fail = 0;
        }
    };

    int last;
    std::string s;
    std::vector<node> pam;
    PAM() {
        last = 0;
        s = "$";
        pam.emplace_back(0);
        pam.emplace_back(-1);
        pam[0].fail = 1;
    };

    int getFail(int x) {
        int tot = s.size() - 1;
        while (s[tot - pam[x].len - 1] != s[tot]) {
            x = pam[x].fail;
        }
        return x;
    }

    int insert(char c) {
        s.push_back(c);
        int now = getFail(last);
        if (pam[now].next[c - 'a'] == 0) {
            pam.emplace_back(pam[now].len + 2);
            pam.back().fail = pam[getFail(pam[now].fail)].next[c - 'a'];
            pam[now].next[c - 'a'] = pam.size() - 1;
        }
        last = pam[now].next[c - 'a'];

        return last;
    }

    std::vector<std::vector<int>> getFailTree() {
        // root at 1 !!!
        std::vector<std::vector<int>> adj(pam.size());
        for (int i = 1; i < pam.size(); i++) {
            if (pam[i].fail != -1) {
                adj[i].push_back(pam[i].fail), adj[pam[i].fail].push_back(i);
            }
        }
        return adj;
    }

    node& operator[](const int x) { return this->pam[x]; }
    int size() const { return pam.size(); }
};