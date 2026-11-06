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

/* ===== NORMAL -> LAZY CHECKLIST =====
 1. Add  vector<Update> lazyTree  (0 = no pending update, so 0 can't be a real update value)
 2. Full-cover case of range update: apply to own value, then lazyTree[i].propagate(u1)
 3. Before going down (update/query, partial overlap): pushdown(i,l,r)
 4. pushdown applies the tag to both CHILDREN's values, then propagates the tag to them, then clears own tag

 ===== WHAT TO CHANGE PER PROBLEM (only Node::merge and Update::apply/propagate) =====
 Node::merge (identity Node() = 0 for all three; for max use -inf, min use +inf)
    sum: val = left.val + right.val;
    xor: val = left.val ^ right.val;
    OR : val = left.val | right.val;

 Update::apply(node,l,r)   (len = r-l+1)
    range assign, sum : node.val = val * len;
    range add,    sum : node.val += val * len;
    range xor,    xor : if(len & 1) node.val ^= val;   // even length cancels out
    range assign, OR  : node.val = (1LL<<val);         // or node.val = val if val is already a mask
    range OR,     OR  : node.val |= val;

 Update::propagate(newU)   (how a new tag combines with the old tag; 0 = identity)
    assign : val = newU.val;     // newest overwrites
    add    : val += newU.val;
    xor    : val ^= newU.val;
    OR     : val |= newU.val;
 NOTE: for assign, 0 can't be a real value; if it can, use a separate bool has / sentinel -1.
*/

struct Node{
    int val;
    Node(int val = 0) : val(val){}
    void merge(Node& left, Node& right){
        val = left.val + right.val;
    }
};

struct Update{
    int val;
    Update(int val = 0) : val(val){}
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

    // CHANGED: pushdown applies the tag to the CHILDREN's values right away,
    // so children are never stale when we merge.
    void pushdown(int i, int l, int r){
        if (l == r) return;                          // leaf has no children
        if (lazyTree[i].val){                        // 0 -> no need to update
            int mid = l + (r - l) / 2;
            Update& u = lazyTree[i];
            u.apply(segTree[2 * i + 1], l, mid);     // update left child's value
            u.apply(segTree[2 * i + 2], mid + 1, r); // update right child's value
            lazyTree[2 * i + 1].propagate(u);        // leave tag for grandchildren
            lazyTree[2 * i + 2].propagate(u);
            lazyTree[i] = Update();                  // clear
        }
    }

    void updateTree(int i, int l, int r, int& idx, Update& u1){
        if (l == r){                                 // CHANGED: no pushdown at leaf
            u1.modify(segTree[i]);
            return;
        }
        pushdown(i, l, r);                           // push before going down

        int mid = l + (r - l) / 2;
        if (idx <= mid)
            updateTree(2 * i + 1, l, mid, idx, u1);
        else
            updateTree(2 * i + 2, mid + 1, r, idx, u1);

        segTree[i].merge(segTree[2 * i + 1], segTree[2 * i + 2]);
    }

    void lazyUpdateRange(int i, int l, int r, int start, int end, Update& u1){
        if (r < start || l > end)
            return;

        if (start <= l && r <= end){
            u1.apply(segTree[i], l, r);              // fix own value now
            if (l != r) lazyTree[i].propagate(u1);   // CHANGED: tag lives on THIS node
            return;
        }

        pushdown(i, l, r);                           // CHANGED: pushdown only when going down
        int mid = l + (r - l) / 2;
        lazyUpdateRange(2 * i + 1, l, mid, start, end, u1);
        lazyUpdateRange(2 * i + 2, mid + 1, r, start, end, u1);
        segTree[i].merge(segTree[2 * i + 1], segTree[2 * i + 2]);
    }

    Node query(int i, int l, int r, int start, int end){
        if (r < start || l > end)
            // return Node( numeric_limits<int>::lowest() );
            return Node();

        if (start <= l && r <= end)
            return segTree[i];

        pushdown(i, l, r);                           // CHANGED: pushdown only when going down
        int mid = l + (r - l) / 2;
        Node left = query(2 * i + 1, l, mid, start, end);
        Node right = query(2 * i + 2, mid + 1, r, start, end);
        Node res;
        res.merge(left, right);
        return res;
    }

public:
    SegmentTree(vi& nums) : n(nums.size()), segTree(4 * n, 0), lazyTree(4 * n, 0){
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
    dist[u][v] = min(dist[u][v], w);
    dist[v][u] = min(dist[u][v], w);
}
FW(dist, n);
void FW(vector<vi>& dist, int n){
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
    for (int i = 0; i < n; i++){// n tak chlao issue aa sakta( High Score CSES)
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

vector<pii> res;
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



//SCC( kosaraju ) (0-based edge list)

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
        dag.assign(k, { });
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
        g.assign(n, { });
        rg.assign(n, { });
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


// MULTI LINE INPUT

string line;
while (getline(cin, line)){
    if (line.empty()) continue;   // skip empty lines (optional)

    stringstream ss(line);
    vector<int> v;// can be vector<string>
    int x;

    while (ss >> x) v.push_back(x);

    // process this line
}


//Manacher

struct Manacher{
    vi p;
    string t;
    Manacher(const string& s){
        t = "#";
        for (char c : s){ t += c, t += '#'; }
        int n = (int)t.size();
        p.assign(n, 1);
        for (int i = 0, l = 0, r = 0; i < n; i++){
            if (i <= r) p[i] = min(r - i + 1, p[l + r - i]);
            while (i - p[i] >= 0 && i + p[i] < n && t[i - p[i]] == t[i + p[i]]) p[i]++;
            if (i + p[i] - 1 > r){
                l = i - p[i] + 1,
                    r = i + p[i] - 1;
            }
        }
    }
    int odd(int i){ return p[2 * i + 1] - 1; }
    int even(int i){ return p[2 * i + 2] - 1; }
    bool isPal(int l, int r){
        int len = r - l + 1;
        return p[l + r + 1] - 1 >= len;
    }
};


// euler cycle(1-based edge list)

// for directed graphs(indeg=outdeg)

// for Euler path
// sirf start and end ki degree odd hogi/or all are even cause start py wapis nahi aana ans same for end
// directed me start=>outdeg=indeg+1  , end=>indeg+1=outdeg
// baqi sab ki degree even



vi getEulerCycle(int n, int m, vector<pii> &edges){
    vector<vector<pii>> adj(n + 1);
    vi degree(n + 1, 0);
    vector<bool> used(m, false);
    // Build graph
    for (int i = 0; i < m; i++){
        auto [u, v] = edges[i];
        adj[u].pb({ v, i });
        adj[v].pb({ u, i });
        degree[u]++;
        degree[v]++;
    }
    // Check even degree condition
    for (int i = 1; i <= n; i++){
        if (degree[i] % 2 != 0)
            return { };  // No Euler cycle
    }
    int start = 1;
    // Find starting node (with degree > 0)
    while (start <= n && adj[start].empty()) start++;
    if (start > n) return { }; // no edges
    vi euler;
    stack<int> st;
    st.push(start);
    while (!st.empty()){
        int u = st.top();
        while (!adj[u].empty() && used[adj[u].back().second])
            adj[u].pop_back();
        if (adj[u].empty()){ euler.pb(u); st.pop(); }
        else{
            auto [v, id] = adj[u].back();
            adj[u].pop_back();
            if (!used[id]){ used[id] = true;  st.push(v); }
        }
    }
    if ((int)euler.size() != m + 1) return { }; // Not connected
    reverse(euler.begin(), euler.end());
    return euler;
}


// AhoCorasick

const int ALPHABET_SIZE = 26;

struct AhoCorasick{
    struct Node{
        int children[ALPHABET_SIZE];
        int fail = 0;
        int count = 0; // Tracks patterns ending at this node
        Node(){ memset(children, 0, sizeof(children)); }
    };
    vector<Node> trie;
    AhoCorasick(){ trie.emplace_back(); }
    void insert(const string& s){
        int u = 0;
        for (char c : s){
            int v = c - 'a';
            if (!trie[u].children[v]){
                trie[u].children[v] = trie.size();
                trie.emplace_back();
            }
            u = trie[u].children[v];
        }
        trie[u].count++;
    }
    void build(){
        queue<int> q;
        forn(i, 0, ALPHABET_SIZE){
            if (trie[0].children[i]){
                q.push(trie[0].children[i]);
            }
        }
        while (!q.empty()){
            int u = q.front();
            q.pop();
            forn(i, 0, ALPHABET_SIZE){
                int& v = trie[u].children[i];
                int fail_node = trie[trie[u].fail].children[i];
                if (v){
                    trie[v].fail = fail_node;
                    // Propagate information along the failure path
                    trie[v].count += trie[fail_node].count;
                    q.push(v);
                }
                else{ v = fail_node; /* Transitions to the next best state*/ }
            }
        }
    }
    int query(const string& text){
        int u = 0;
        int total_matches = 0;
        for (char c : text){
            u = trie[u].children[c - 'a'];
            total_matches += trie[u].count;
        }
        return total_matches;
    }
};


//euler tour dfs ( in out based , use with ST)

void dfs(int idx, int p, vector<vi> &graph, vi & arr, vector<pii> &order, int& curr, vi & arr2){
    order[idx].f = curr;
    arr2.pb(arr[idx - 1]); curr++;
    for (auto it : graph[idx]){
        if (it == p) continue;
        dfs(it, idx, graph, arr, order, curr, arr2);
    }
    order[idx].ss = curr;
    arr2.pb(arr[idx - 1] * -1LL); curr++;
}

// Dynamic Median - Make all elements equal (dynamic)

class DynamicMedian{
public:
    int r1 = 0, r2 = 0, size = 0;
    multiset<int> st1, st2;

    // st1 ka maximum element reference hai, r1 total difference maintain karta hai
    void add1(int x){
        if (st1.empty() || x <= *st1.rbegin()){
            if (!st1.empty()) r1 += (*st1.rbegin() - x);
            st1.insert(x);
        }
        else{
            r1 += (x - *st1.rbegin()) * (int)st1.size();
            st1.insert(x);
        }
    }

    // st2 ka minimum element reference hai, r2 total difference maintain karta hai
    void add2(int x){
        if (st2.empty() || x >= *st2.begin()){
            st2.insert(x);
            r2 += (x - *st2.begin());
        }
        else{
            r2 += (*st2.begin() - x) * (int)st2.size();
            st2.insert(x);
        }
    }

    // st1 se element remove karte waqt r1 update karna
    void remove1(int x){
        auto it = st1.find(x);
        int end = *st1.rbegin();

        if (x == end && st1.size() > 1){
            st1.erase(it);
            int end2 = *st1.rbegin();
            if (end2 != x) r1 -= (x - end2) * (int)st1.size();
        }
        else{
            r1 -= (end - x);
            st1.erase(it);
        }
    }

    // st2 se element remove karte waqt r2 update karna
    void remove2(int x){
        auto it = st2.find(x);
        int start = *st2.begin();

        if (x == start && st2.size() > 1){
            st2.erase(it);
            int start2 = *st2.begin();
            if (start2 != x) r2 -= (start2 - x) * (int)st2.size();
        }
        else{
            r2 -= (x - start);
            st2.erase(it);
        }
    }

    // Element insert karna aur dono halves ka balance maintain karna
    void add(int x){
        size++;

        if (size == 1 || x <= *st1.rbegin()){
            add1(x);
            if (st1.size() > (size + 1) / 2){
                int v = *st1.rbegin();
                remove1(v);
                add2(v);
            }
        }
        else{
            add2(x);
            if (st2.size() > st1.size()){
                int v = *st2.begin();
                remove2(v);
                add1(v);
            }
        }
    }

    // Element delete karna, phir dono halves ko balance karna
    // Element exist na kare toh false return hoga
    bool remove(int x){
        if (size == 0) return false;

        if (st2.find(x) != st2.end()) remove2(x);
        else if (st1.find(x) != st1.end()) remove1(x);
        else return false;

        size--;

        if (st1.size() > (size + 1) / 2){
            int v = *st1.rbegin();
            remove1(v);
            add2(v);
        }
        else if (st2.size() > st1.size()){
            int v = *st2.begin();
            remove2(v);
            add1(v);
        }

        return true;
    }

    // Lower median return karega
    int get_median(){
        if (size == 0) return 0;
        return *st1.rbegin();
    }

    // Sab elements ko equal banane ki minimum cost (sum of absolute differences)
    int get_min(){
        if (size <= 1) return 0;
        return r1 + r2 + (*st2.begin() - *st1.rbegin()) * (int)st2.size();
    }
};



// DP on trees
// 2 dfs function
// 0-based (just change arr[idx-1] or arr based on 1-base)

void dfs1(int idx, int p, vector<vi> &graph, vector<pii> &dp1, vi & arr){
    dp1[idx] = { 0,arr[idx] };// sum, count/dist_sum
    for (auto it : graph[idx]){
        if (it == p) continue;
        dfs1(it, idx, graph, dp1, arr);
        dp1[idx].f += dp1[it].f + dp1[it].ss;
        dp1[idx].ss += dp1[it].ss;
    }
}
void dfs2(int idx, int p, int sum, int count, vector<vi> &graph, vector<pii> &dp1, vector<pii> &dp2){
    dp2[idx] = { sum + count + dp1[idx].f,count + dp1[idx].ss };// sum, count/dist_sum
    for (auto it : graph[idx]){
        if (it == p) continue;
        sum = dp2[idx].f - dp1[it].f - dp1[it].ss;
        count = dp2[idx].ss - dp1[it].ss;
        dfs2(it, idx, sum, count, graph, dp1, dp2);
    }
}