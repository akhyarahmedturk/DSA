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