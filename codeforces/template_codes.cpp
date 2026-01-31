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

//Segment Tree

struct Node{
    int val;
    Node(int val = 0) : val(val){ }
    void merge(Node& left, Node& right){
        val = left.val + right.val;
    }
};

struct Update{
    int val;
    Update(int val = 0) : val(val){ }
    void apply(Node& node, int l, int r){
        node.val += val * (r - l + 1ll); // Currently lazyUpdate is via updating val NOT replacing.
    }
    void propagate(Update& newU){
        val += newU.val;
    }
    void modify(Node& node){
        node.val = val;
    }
};

class SegmentTree{
private:
    int n;
    vector<Node> segTree;
    vector<Update> lazyTree;

    void buildTree(int node, int start, int end, vi& arr){
        if (start == end){
            segTree[node] = Node(arr[start]);
            return;
        }

        int mid = start + (end - start) / 2;
        buildTree(2 * node + 1, start, mid, arr);
        buildTree(2 * node + 2, mid + 1, end, arr);
        segTree[node].merge(segTree[2 * node + 1], segTree[2 * node + 2]);
    }

    void updateTree(int i, int l, int r, int& idx, Update& u1){
        pushdown(i, l, r);
        if (l == r){
            u1.modify(segTree[i]);
            return;
        }

        int mid = l + (r - l) / 2;
        if (idx <= mid)
            updateTree(2 * i + 1, l, mid, idx, u1);
        else
            updateTree(2 * i + 2, mid + 1, r, idx, u1);

        segTree[i].merge(segTree[2 * i + 1], segTree[2 * i + 2]);
    }

    void pushdown(int i, int l, int r){
        if (lazyTree[i].val){
            lazyTree[i].apply(segTree[i], l, r);
            if (l != r){
                lazyTree[2 * i + 1].propagate(lazyTree[i]);
                lazyTree[2 * i + 2].propagate(lazyTree[i]);
            }
            lazyTree[i] = Update();
        }
    }

    void lazyUpdateRange(int i, int l, int r, int start, int end, Update& u1){
        if (r < start || l > end)
            return;

        pushdown(i, l, r);
        if (start <= l && r <= end){
            u1.apply(segTree[i], l, r);
            if (l != r){
                lazyTree[2 * i + 1].propagate(u1);
                lazyTree[2 * i + 2].propagate(u1);
            }
            return;
        }

        int mid = l + (r - l) / 2;
        lazyUpdateRange(2 * i + 1, l, mid, start, end, u1);
        lazyUpdateRange(2 * i + 2, mid + 1, r, start, end, u1);
        segTree[i].merge(segTree[2 * i + 1], segTree[2 * i + 2]);
    }

    Node query(int i, int l, int r, int start, int end){
        if (r < start || l > end)
            // return Node( numeric_limits<int>::lowest() );
            return Node();

        pushdown(i, l, r);
        if (start <= l && r <= end)
            return segTree[i];

        int mid = l + (r - l) / 2;
        Node left = query(2 * i + 1, l, mid, start, end);
        Node right = query(2 * i + 2, mid + 1, r, start, end);
        Node res;
        res.merge(left, right);
        return res;
    }

public:
    SegmentTree(vi& nums) : n(nums.size()), segTree(4 * n, 0), lazyTree(4 * n, 0){
        // segTree.resize( 2 * n - 1 ) ;
        fill(all(segTree), Node());
        fill(all(lazyTree), Update());
        buildTree(0, 0, n - 1, nums);
    }

    void update(int index, int val){
        if (index < 0 || index >= n)  return;
        Update u1(val);
        updateTree(0, 0, n - 1, index, u1);
    }

    void lazyUpdateRange(int start, int end, int val){
        Update u1(val);
        lazyUpdateRange(0, 0, n - 1, start, end, u1);
    }

    int query(int start, int end){
        // if( start > end )   swap( start, end ) ;
        return query(0, 0, n - 1, start, end).val;
    }
};

// Floyd Warshall
vector<vi> dist(n, vi(n, inf));
forn(i, 0, m){
    int u, v, w;
    cin >> u >> v >> w; u--; v--;
    dist[u][v] = min(dist[u][v] ,w);
    dist[v][u] = min(dist[u][v] ,w);
}
FW(dist,n);
void FW(vector<vi>& dist,int n){
    for (int i = 0; i < n; i++) dist[i][i] = 0LL;
    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            if (dist[i][k] == inf) continue;
            for (int j = 0; j < n; j++){
                if (dist[k][j] == inf) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
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
// cycle check karny ky liy pori outer loop dobara chlao
vi bellman_ford(int src, vector<vector<pii>> &graph){
    int n = graph.size();
    vi dist(n, LONG_LONG_MAX);
    dist[src] = 0;
    for (int i = 0; i < n ; i++){// n tak chlao issue aa sakta( High Score CSES)
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
        up.assign(n, vi(LOG, -1));
        depth.assign(n, 0);
        adj = graph;
    }

    void preprocess(int root = 0){
        dfs(root, -1);
    }

    // void preprocess(){ for Directed Cyclic graphs ( planet queries)
    //     forn(i,1,n) up[0][i]=adj[i];//child 2^0=1 dis py hoga
    //     forn(i,1,LOG){
    //         forn(j,1,n) up[i][j]=  up[i-1][up[i-1][j]];//2^1 hy to child ka child
    //     }
    // }

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

se res;
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


// quadratic compression
forn(i, 0, n){
    comp.pb(arr[i]);
}
sort(all(comp));
comp.erase(unique(all(comp)), comp.end());
forn(i, 0, n){
    arr[i] = upper_bound(all(comp), arr[i]) - comp.begin();  // 1,2,3.....
}


//Trie

const int ALPHA = 26;
// const int MAXN = 2000000;   // total characters

struct TrieNode{
    TrieNode* child[ALPHA];
    int cnt, end;

    TrieNode(){
        cnt = 0; end = 0;
        for (int i = 0; i < 26; i++) child[i] = nullptr;
    }
};

struct Trie{
    TrieNode* root;
    Trie() root = new TrieNode();
    void insert(const string& s){
        TrieNode* cur = root;
        for (char c : s){
            int id = c - 'a';
            if (cur->child[id] == nullptr) cur->child[id] = new TrieNode();
            cur = cur->child[id];
            cur->cnt++;
        }
        cur->end++;
    }
    int search(const string& s){
        TrieNode* cur = root;
        for (char c : s){
            int id = c - 'a';
            if (cur->child[id] == nullptr) return 0;
            cur = cur->child[id];
        }
        return cur->end;
    }
};


//Mo's Algo

struct Query{
    int l, r, idx; //0 based
};

vector<int> mo_solve(const vector<int> &arr, vector<Query> queries){
    int n = arr.size();
    int q = queries.size();
    int block = max(1LL, (int)sqrt(n));

    sort(queries.begin(), queries.end(), [&](const Query& a, const Query& b){
        int block_a = a.l / block;
        int block_b = b.l / block;
        if (block_a != block_b) return block_a < block_b;
        // odd-even optimization (aka Hilbert-like tweak)
        return  (a.r < b.r);
    });

    vector<int> ans(q);

    vector<int> freq(1e6 + 10, 0);  // example freq array for values up to 1e6
    int cur_answer = 0;              // example: count distinct numbers
    // multiset<int> st;

    auto add = [&](int idx){
        int x = arr[idx];
        if (freq[x] == 0) cur_answer++;
        freq[x]++;
        };

    auto remove = [&](int idx){
        int x = arr[idx];
        freq[x]--;
        if (freq[x] == 0) cur_answer--;
        };
    int L = 0, R = -1;
    for (auto& qr : queries){
        while (L > qr.l) add(--L);
        while (R < qr.r) add(++R);
        while (L < qr.l) remove(L++);
        while (R > qr.r) remove(R--);

        ans[qr.idx] = cur_answer;
    }

    return ans;
}



//SCC( kosaraju )

class SCC{
    vector<bool> vis;
    vi order;

    void dfs1(int u){
        vis[u] = true;
        for (int v : g[u])
            if (!vis[v])
                dfs1(v);
        order.push_back(u);
    }

    void dfs2(int u, vi& comp){
        vis[u] = true;
        comp.push_back(u);
        for (int v : rg[u])
            if (!vis[v])
                dfs2(v, comp);
    }

    void find_scc(int n){
        vis.assign(n, false);
        order.clear();
        for (int i = 0; i < n; ++i)
            if (!vis[i])
                dfs1(i);

        vis.assign(n, false);
        reverse(order.begin(), order.end());
        scc.clear();
        component_id.assign(n, -1);
        int id = 0;
        for (int u : order)
            if (!vis[u]){
                vector<int> comp;
                dfs2(u, comp);
                for (int v : comp){
                    component_id[v] = id;
                }
                scc.push_back(comp);
                id++;
            }
    }
    void build_condened_graph(vector<pii>& edges){
        int k = scc.size();
        dag.assign(k, {});
        for (auto [u, v] : edges){
            int cu = component_id[u];
            int cv = component_id[v];
            if (cu != cv){
                dag[cu].push_back(cv);
            }
        }
    }
public:
    vi component_id;
    vector<vi> dag;
    vector<vi> g, rg, scc;
    SCC(int n, vector<pii>& edges){
        g.assign(n, {});
        rg.assign(n, {});
        for (auto& e : edges){
            int u = e.first;
            int v = e.second;
            g[u].push_back(v);
            rg[v].push_back(u);
        }
        find_scc(n);
        build_condened_graph(edges);
    }

};

