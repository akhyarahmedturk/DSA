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

//