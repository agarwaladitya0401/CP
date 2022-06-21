struct binaryLifting {
    int n;
    int mxLog;
    int maxRequirement;

    vector<vector<int>> parent;
    vector<int> logValues;
    bool precomputeLogs = false;

    binaryLifting(int n1, vector<int> *edges, int require, int root) {
        n = n1;
        mxLog = log2(require + 1);
        maxRequirement = require;

        for (int i = 0; i < n; i++) {
            parent[i].resize(mxLog + 1);

            for (int j = 0; j <= mxLog; j++) {
                parent[i][j] = -1;
            }
        }

        fillParents(root, edges);
        if (maxRequirement <= 1000000) {
            precomputeLogs();
        }
    }

    void fillParents(int root, vector<int> *edges) {
        vector<bool> visited(n);
        dfsParent(root, edges, visited);
    }

    void dfsParent(int root, vector<int> *edges, vector<bool> &visited) {
        visited[root] = 1;

        for (auto it : edges[root]) {
            if (!visited[it]) {
                parent[it][0] = root;
                dfsParent(it, edges, visited);
            }
        }
    }
};
