int dfs(int node, int parent, vector<vector<pair<int, int>>>& G, vector<long long>& ans) {
    
    long long degree = 1;
    long long wt = 0;
    for(auto e:G[node]) {
        if(e.first != parent) {
            degree += dfs(e.first, node, G, ans);
        }
        else {
            wt = e.second;
        }
    }
    ans.push_back(wt * degree);
    return degree;
}

int Solution::solve(int A, vector<vector<int> > &B, int C) {
    const int mod = 1e9 + 7;
    vector<vector<pair<int, int>>> G(A + 1);
    for(auto e:B) {
        G[e[0]].push_back({e[1], e[2]});
        G[e[1]].push_back({e[0], e[2]});
    } 
    vector<long long> ans;
    dfs(1, 1, G, ans);
    sort(ans.begin(), ans.end(), greater<>());
    long long res = 0;
    for(int i = C; i < ans.size(); i++) {
        cout << ans[i] << " ";
        res += (ans[i] % mod);
        // if(res < 0)
        //     res += mod;
        res %= mod;
    }
    if(res < 0)
        res += mod;
    return res;
}
