//NCR , NPR , binary_exp

const int N = 1e3;
int  fact[N + 10];
int  inv_fact[N + 10];

int binary_exp(int a, int b, int M){
    int ans = 1;
    while (b){
        if (b & 1) ans = (ans * a) % M;
        a = (a * a) % M;
        b >>= 1;
    }
    return ans;
}

void precompute(){
    fact[0] = inv_fact[0] = 1;
    for (int i = 1;i < N;i++){
        fact[i] = (i * fact[i - 1]) % mod;
        inv_fact[i] = binary_exp(fact[i], mod - 2, mod) % mod;
    }
}

int NCR(int n, int r){
    if (r > n) return 0;
    return (((fact[n] * inv_fact[n - r]) % mod) * inv_fact[r]) % mod;
}

int NPR(int n, int r){
    if (r > n) return 0;
    return (((fact[n] * inv_fact[n - r]) % mod)) % mod;
}

// Segment tree

class SegmentTree{
private:
    int n;
    vi tree, arr;
    void build(int node, int l, int r){
        if (l == r) tree[node] = arr[l];
        else{
            int mid = (l + r) / 2;
            build(2 * node, l, mid);
            build(2 * node + 1, mid + 1, r);
            tree[node] = tree[2 * node] + tree[2 * node + 1]; //
        }
    }
    int query(int node, int l, int r, int ql, int qr){
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return query(2 * node, l, mid, ql, qr) + query(2 * node + 1, mid + 1, r, ql, qr);//
    }
    void update(int node, int l, int r, int idx, int val){
        if (l == r){
            arr[idx] = val;
            tree[node] = val;
        }
        else{
            int mid = (l + r) / 2;
            if (idx <= mid) update(2 * node, l, mid, idx, val);
            else update(2 * node + 1, mid + 1, r, idx, val);
            tree[node] = tree[2 * node] + tree[2 * node + 1];//
        }
    }
public:
    SegmentTree(vi arr_1){
        arr = arr_1;
        n = arr.size();
        tree.assign(4 * n, 0);
        build(1, 0, n - 1);
    }
    int rangeSum(int l, int r) { return query(1, 0, n - 1, l, r); }
    void Update(int idx, int val) { update(1, 0, n - 1, idx, val); }
};

// dijkstra 

int dijkstra(int src, int dst, vector<vector<pii>>& graph){
    int n = graph.size();
    vi dist(n, LONG_LONG_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[src] = 0;
    pq.push({ 0,src });
    while (!pq.empty()){
        int v = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (d > dist[v]) continue;
        for (auto u : graph[v]){
            if (d + u.second < dist[u.first]){
                pq.push({ u.first,d + u.second });
                dist[u.first] = d + u.second;
            }
        }
    }
    if (dist[dst] == LONG_LONG_MAX) return -1;
    else return dist[dst];
}

// Floyd Warshall

vector<vi> dist(n, vi(n, inf));
forn(i, 0, m){
    int u, v, w;
    cin >> u >> v >> w; u--; v--;
    dist[u][v] = w;
    dist[v][u] = w;
}
forn(k, 0, n){
    dist[k][k] = 0;
    forn(i, 0, n){
        if (dist[i][k] == inf) continue;
        forn(j, 0, n){
            if (i == j) dist[i][j] = 0;
            else if (dist[j][k] != inf) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
    }
}

// prime sieve 
vector<bool> is_prime(N + 1, true);
is_prime[0] = is_prime[1] = false;
for (int i = 2; i * i <= N; i++){
    if (is_prime[i]){
        for (int j = i * i; j <= N; j += i){
            is_prime[j] = false;
        }
    }
}

// belman ford
vi bellman_ford(int src, vector<vector<pii>> &graph){
    int n = graph.size();
    vi dist(n, LONG_LONG_MAX);
    dist[src] = 0;
    for (int i = 0; i < n - 1; i++){
        for (int u = 0; u < n; u++){
            for (auto& edge : graph[u]){
                int v = edge.first;
                int weight = edge.second;
                if (dist[u] != LONG_LONG_MAX && dist[u] + weight < dist[v]){
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }
    return dist;
}

//KMP Algorithm (for string matching)
vi kmp_preprocess(const string & pattern){
    int m = pattern.size();
    vi lps(m, 0);
    int j = 0;
    for (int i = 1; i < m; i++){
        while (j > 0 && pattern[i] != pattern[j]){
            j = lps[j - 1];
        }
        if (pattern[i] == pattern[j]){
            j++;
        }
        lps[i] = j;
    }
    return lps;
}

vi kmp_search(const string & text, const string & pattern){
    vi lps = kmp_preprocess(pattern);
    vi matches;
    int j = 0;
    for (int i = 0; i < text.size(); i++){
        while (j > 0 && text[i] != pattern[j]){
            j = lps[j - 1];
        }
        if (text[i] == pattern[j]){
            j++;
        }
        if (j == pattern.size()){
            matches.push_back(i - j + 1);
            j = lps[j - 1];
        }
    }
    return matches;
}


// binary lifting  0-base

class BinaryLifting{
    int n, LOG;
    vector<vi> up;
    vector<vi> adj;

public:
    vi depth;// root sy distance kitna hy
    // leaf tak wali height hoti hy !

    BinaryLifting(int size, vector<vi>& graph){
        n = size;
        LOG = 32 - __builtin_clz(n); // ceil(log2(n))
        up.assign(n, vi(LOG,-1));
        depth.assign(n, 0);
        adj = graph;
    }

    void preprocess(int root = 0){
        dfs(root, -1);
    }

    // kth ancestor of node u
    int lift(int u, int k){
        for (int j = 0; j < LOG; j++){
            if (k & (1 << j)){
                u = up[u][j];
                if (u == -1) break;
            }
        }
        return u;
    }

    int LCA(int u, int v){
        if (depth[u] < depth[v]) swap(u, v);

        // Lift u up to same depth as v
        int diff = depth[u] - depth[v];
        u = lift(u, diff);

        if (u == v) return u;

        for (int j = LOG - 1; j >= 0; j--){
            if (up[u][j] != up[v][j]){
                u = up[u][j];
                v = up[v][j];
            }
        }
        return up[u][0];
    }
    //private
    void dfs(int u, int p){
        up[u][0] = p;
        depth[u] = (p == -1 ? 0 : depth[p] + 1);

        for (int j = 1; j < LOG && up[u][j - 1] != -1; j++)
            up[u][j] = up[up[u][j - 1]][j - 1];

        for (int v : adj[u]){
            if (v != p)
                dfs(v, u);
        }
    }
};

// BIT Fenwick Tree

struct BIT{
    int n;
    vi bit;
    BIT(int nn){
        n = nn;
        bit.assign(n + 2, 0);
    }
    // Point update: add 'val' to index 'i'
    void update(int i, int val){ //bit[i]+=x;
        while (i <= n){
            bit[i] += val;
            i += i & -i;
        }
    }
    // Prefix sum: sum[1...i]
    int query(int i){
        int res = 0;
        while (i > 0){
            res += bit[i];
            i -= i & -i;
        }
        return res;
    }
};

// bridges in graph

vvi res;
vector<set<int>> graph;
int DFS(int idx, vi & vis, vi & count){
    vis[idx] = 1;
    int upper = 0;// upper bhejna hy count
    int nechy = 0;// nechy sy mila
    for (auto it : graph[idx]){
        graph[it].erase(idx);//parent nikalo
        if (vis[it]){ upper++; count[it]++; }// it py subtract hoga
        else{
            int x = DFS(it, vis, count);
            if (!x) res.pb({ idx,it });
            nechy += x;//nechy sy mila
        }
    }
    nechy -= count[idx];
    return nechy + upper;
}

//DSU

struct DSU{
    vi parent, size;
    DSU(int n){
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x){
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    bool unite(int a, int b){
        a = find(a), b = find(b);
        if (a == b) return false;
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
};


//compression
forn(i, 0, n){
    comp.pb(arr[i]);
}
sort(all(comp));
comp.erase(unique(all(comp)), comp.end());
forn(i, 0, n){
    arr[i] = lower_bound(all(comp), arr[i]) - comp.begin() + 1;
}


//Trie

const int ALPHA = 26;
// const int MAXN = 2000000;   // total characters

struct TrieNode {
    TrieNode* child[ALPHA];
    int cnt,end;

    TrieNode() {
        cnt = 0; end=0;
        for(int i = 0; i < 26; i++) child[i] = nullptr;
    }
};

struct Trie {
    TrieNode* root;
    Trie() root = new TrieNode();
    void insert(const string &s) {
        TrieNode* cur = root;
        for(char c : s) {
            int id = c - 'a';
            if(cur->child[id] == nullptr) cur->child[id] = new TrieNode();
            cur = cur->child[id];
            cur->cnt++;
        }
        cur->end++;
    }
    int search(const string &s) {
        TrieNode* cur = root;
        for(char c : s) {
            int id = c - 'a';
            if(cur->child[id] == nullptr) return 0;
            cur = cur->child[id];
        }
        return cur->end;
    }
};
