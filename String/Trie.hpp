#pragma once
#include "../Template/Template.hpp"

// struct TrieNode {
//     TrieNode() { id = 0, dep = 0, nxt = array<int, 26>(); };
//     TrieNode(int _id, int _dep) : id(_id), dep(_dep) {}
//     int id;
//     int dep;
//     array<int, 26> nxt = {};
//     int &operator[](const int x) { return this->nxt[x]; }
// };
template <class Node>
struct trie {
    vector<Node> tr;
    trie() { tr.push_back(Node()); };

    int add(const string &s) {
        int n = s.size();
        int p = 0;
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'A';
            if (!tr[p][c]) {
                tr[p][c] = tr.size();
                tr.emplace_back(tr[p][c], tr[p].dep + 1);
            }
            p = tr[p][c];
        }
        return p;
    }

    int size() const { return tr.size(); }
};
