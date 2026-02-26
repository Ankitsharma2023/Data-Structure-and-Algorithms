class DSU {

private:
    // rank
    // parent
    vector<int> rank;
    vector<int> parent;

public:
    // constructor

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i; // initially all are empty
    }

    // find
    int find(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = find(parent[node]);
    }
    // union

    void union_set(int a, int b) {
        int leader_a = find(a);
        int leader_b = find(b);

        if (leader_a != leader_b) {
            if (rank[leader_a] < rank[leader_b]) {
                parent[leader_a] = leader_b;
                rank[leader_b] += rank[leader_a];
            } else {
                parent[leader_b] = leader_a;
                rank[leader_a] += rank[leader_b];
            }
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        if (connections.size() < n - 1)
            return -1;

        DSU dsu(n);
         for (auto &e : connections) {
            int u = e[0];
            int v = e[1];
            dsu.union_set(u, v);
        }

        int component = 0;
        for(int i =0;i<n;i++)
        {
            if(dsu.find(i)==i) component++; // same parnet
        }

        return component - 1;
    }
};