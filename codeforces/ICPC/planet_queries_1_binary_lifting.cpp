class BinaryLifting{
    int n, LOG;
    vector<vi> up;
    vi adj;
public:
    BinaryLifting(int size, vi & graph){
        n = size;
        LOG = 31;
        up.assign(LOG, vi(n,-1));
        adj = graph;
        preprocess();
    }
 
    void preprocess(){
        forn(i,1,n) up[0][i]=adj[i];//child 2^0=1 dis py hoga
        forn(i,1,LOG){
            forn(j,1,n) up[i][j]=  up[i-1][up[i-1][j]];//2^1 hy to child ka child
        }
    }
 
    // kth ancestor of node u
    int down(int u, int k){
        for (int j = 0; j < LOG; j++){
            if (k & (1LL << j)){
                u = up[j][u];
            }
        }
        return u;
    }
};
 
 
 
void solve() {
    int n,q; cin>>n>>q;
    vi graph(n+1);
    forn(i,0,n) cin>>graph[i+1];
    BinaryLifting bl(n+1,graph);
    while(q--){
        int idx,v; cin>>idx>>v;
        cout<<bl.down(idx,v)<<nl;
    }
}
