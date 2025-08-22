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
    vi tree, arr;
    int n;

    void build(int node, int l, int r){
        if (l == r){
            tree[node] = arr[l];
        }
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
            if (idx <= mid)
                update(2 * node, l, mid, idx, val);
            else
                update(2 * node + 1, mid + 1, r, idx, val);
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

    int rangeSum(int l, int r){
        return query(1, 0, n - 1, l, r);
    }

    void Update(int idx, int val){
        update(1, 0, n - 1, idx, val);
    }
};

// graph input

vector<vi> graph(n);

forn(i,0,m){
    int a,b;
    cin>>a>>b;
    a--;
    b--;
    graph[a].pb(b);
    graph[b].pb(a);
}


// dijkstra 

int dijkstra(int src,int dst,vector<vector<pii>> &graph){
    int n=graph.size();
    vi dist(n,LONG_LONG_MAX);
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    dist[src]=0;
    pq.push({0,src});
    while(!pq.empty()){
        int v=pq.top().second;
        int d=pq.top().first;
        pq.pop();
        if(d>dist[v]) continue;
        for(auto u:graph[v]){
            if(d+u.second<dist[u.first]){
                pq.push({u.first,d+u.second});
                dist[u.first]=d+u.second;
            }
        } 
    }
    if(dist[dst]==LONG_LONG_MAX) return -1;
    else return dist[dst];
}

// Floyd Warshall

vector<vi> dist(n,vi(n,inf));
forn(i,0,m){
    int u,v,w;
    cin>>u>>v>>w;
    dist[u][v]=w;
    dist[v][u]=w;
}
forn(k,0,n){
    forn(i,0,n){
        if(dist[i][k]==inf) continue;
        forn(j,0,n){
            if(i==j) dist[i][j]=0;
            else if(dist[j][k]!=inf) dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
        }
    }
}

// prime sieve 
vector<bool> is_prime(N + 1, true);
is_prime[0] = is_prime[1] = false;
for (int i = 2; i * i <= N; i++) {
    if (is_prime[i]) {
        for (int j = i * i; j <= N; j += i) {
            is_prime[j] = false;
        }
    }
}

// belman ford
vi bellman_ford(int src, vector<vector<pii>> &graph) {
    int n = graph.size();
    vi dist(n, LONG_LONG_MAX);
    dist[src] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int u = 0; u < n; u++) {
            for (auto &edge : graph[u]) {
                int v = edge.first;
                int weight = edge.second;
                if (dist[u] != LONG_LONG_MAX && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }
    return dist;
}

//KMP Algorithm (for string matching)
vi kmp_preprocess(const string &pattern) {
    int m = pattern.size();
    vi lps(m, 0);
    int j = 0;
    for (int i = 1; i < m; i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = lps[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            j++;
        }
        lps[i] = j;
    }
    return lps;
}

vi kmp_search(const string &text, const string &pattern) {
    vi lps = kmp_preprocess(pattern);
    vi matches;
    int j = 0;
    for (int i = 0; i < text.size(); i++) {
        while (j > 0 && text[i] != pattern[j]) {
            j = lps[j - 1];
        }
        if (text[i] == pattern[j]) {
            j++;
        }
        if (j == pattern.size()) {
            matches.push_back(i - j + 1);
            j = lps[j - 1];
        }
    }
    return matches;
}


// segement tree lazy update foo  ( for range based qerries)

class SegmentTree {
private:
    vi tree, lazy;
    int n;

    // CHANGE THIS: How to apply lazy to a node
    void apply(int node, int l, int r, int val) {
        tree[node] += (r - l + 1) * val; // For range sum + add
        if (l != r) {
            lazy[node * 2] += val;
            lazy[node * 2 + 1] += val;
        }
    }

    // Propagate pending updates
    void propagate(int node, int l, int r) {
        if (lazy[node] != 0) {
            apply(node, l, r, lazy[node]);
            lazy[node] = 0;
        }
    }

    void update(int node, int l, int r, int ql, int qr, int val) {
        propagate(node, l, r);
        if (qr < l || ql > r) return; // No overlap
        if (ql <= l && r <= qr) {     // Complete overlap
            apply(node, l, r, val);
            return;
        }
        int mid = (l + r) / 2;
        update(node * 2, l, mid, ql, qr, val);
        update(node * 2 + 1, mid + 1, r, ql, qr, val);
        tree[node] = tree[node * 2] + tree[node * 2 + 1]; // CHANGE if needed
    }

    int query(int node, int l, int r, int ql, int qr) {
        propagate(node, l, r);
        if (qr < l || ql > r) return 0; // No overlap
        if (ql <= l && r <= qr) return tree[node]; // Complete overlap
        int mid = (l + r) / 2;
        return query(node * 2, l, mid, ql, qr) + query(node * 2 + 1, mid + 1, r, ql, qr); // CHANGE if needed
    }

public:
    SegmentTree(int size) {
        n = size;
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }

    // Public update: add val to all elements in [l, r]
    void range_update(int l, int r, int val) {
        update(1, 0, n - 1, l, r, val);
    }

    // Public query: sum of elements in [l, r]
    int range_query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }

    // Optional: set initial values via a build function
    void build(int node, int l, int r, const vi &arr) {
        if (l == r) {
            tree[node] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node, l, mid, arr);
        build(2 * node + 1, mid + 1, r, arr);
        tree[node] = tree[2 * node] + tree[2 * node + 1]; // CHANGE if needed
    }

    void build(const vi &arr) {
        build(1, 0, n - 1, arr);
    }
};



// binary lifting  0-base

class BinaryLifting {
    int n, LOG;
    vector<vi> up;
    vector<vi> adj;

public:
    vi depth;

    BinaryLifting(int size, vector<vi>& graph) {
        n = size;
        LOG = 32 - __builtin_clz(n); // ceil(log2(n))
        up.assign(n, vi(LOG));
        depth.assign(n, 0);
        adj = graph;
    }

    void preprocess(int root = 0) {
        dfs(root, -1);
    }

    // kth ancestor of node u
    int lift(int u, int k) {
        for (int j = 0; j < LOG; j++) {
            if (k & (1 << j)) {
                u = up[u][j];
                if(u==-1) break;
            }
        }
        return u;
    }

    int LCA(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        // Lift u up to same depth as v
        int diff = depth[u] - depth[v];
        u = lift(u, diff);

        if (u == v) return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }
        return up[u][0];
    }

private:
    void dfs(int u, int p) {
        up[u][0] = p;
        depth[u] = (p == -1 ? 0 : depth[p] + 1);

        for (int j = 1; j < LOG; j++)
            up[u][j] = up[up[u][j - 1]][j - 1];

        for (int v : adj[u]) {
            if (v != p)
                dfs(v, u);
        }
    }
};

// BIT Fenwick Tree

struct BIT {
    int n;
    vi bit;
    BIT(int nn) {
        n = nn;
        bit.assign(n + 2, 0);
    }
    // Point update: add 'val' to index 'i'
    void update(int i,int val) { //bit[i]+=x;
        while (i <= n) {
            bit[i] += val;
            i += i & -i;
        }
    }
    // Prefix sum: sum[1...i]
    int query(int i) {
        int res = 0;
        while (i > 0) {
            res += bit[i];
            i -= i & -i;
        }
        return res;
    }
};
