//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define uint unsigned long long int
#define sz(a) (int)((a).size())
//read
#define read(a) int a; cin>>a
#define read2(a,b) int a,b; cin>>a>>b
#define read3(a,b,c) int a,b,c; cin>>a>>b>>c
#define read4(a, b, c, d) int a, b, c, d; cin >> a >> b >> c >> d
#define readC(c) char c; cin>>c
#define readA(a,n) int a[n]; for(int i = 0; i < n; i++) cin>>a[i]
#define readS(s) string s; cin>>s
//debug
#define d1(a) cerr << #a << " " << a << endl;
#define d2(a, b) cerr << #a << " " << a << " " << #b << " " << b << endl;
#define d3(a, b, c) cerr << #a << " " << a << " " << #b << " " << b << " " << #c << " " << c << endl;
#define d4(a, b, c, d) cerr << #a << " " << a << " " << #b << " " << b << " " << #c << " " << c << " " << #d << " " << d << endl;
//for loop
#define F_OR(i, a, b, s) for (int i = (a); ((s) > 0 ? i < (b) : i > (b)); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
//general
#define test int t; cin>>t; while(t--)
#define mod 1000000007
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int,int> 
#define int128 __int128
#define ff first
#define ss second

const int mxn = 1e5 + 1;
int n, m;
int people[mxn];
int happy[mxn];
bool visited[mxn];
// int crowd[mxn];
vector<vector<int>> G;
bool ok;

pair<int, int> calc(int node) {
    if(visited[node] || !ok)
        return {0, 0};

    visited[node] = true;

    int good = 0, bad = 0;
    for(auto e:G[node]) {
        pair<int, int> p1 = calc(e); 
        good += p1.first;
        bad += p1.second;
    }

    int total = people[node] + good + bad;
    int total_good = 0, total_bad = 0;

    if((total + happy[node]) % 2 == 0) {
        total_good = (total + happy[node]) / 2; 
        total_bad = total - total_good;
    }
    else {
        ok = false;
    }
    
    if(total_good > total || good > total_good)
        ok = false;

    return {total_good, total_bad};
}

// int see(int node) {
//     if()
// }


void solve() {
    read2(n, m);
    G = vector<vector<int>> (n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> people[i];
        visited[i] = false;
    }

    for(int i = 1; i <= n; i++) {
        cin >> happy[i];
        // visited[i] = false;
    }

    int u, v;
    for(int i = 1; i < n; i++) {
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }

    ok = true;

    calc(1);

    // for(int i = 1; i <= n; i++) {
    //     visited[i] = false;
    // }

    // see(1);
    if(ok) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

int32_t main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    //this can be opted out if you want to print the output to the sublime console
    freopen("output.txt", "w", stdout);
	#endif
    fastIO

	test solve();



	#ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
    return 0;
}