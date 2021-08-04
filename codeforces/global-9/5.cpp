//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;
// #define int long long int
#define uint unsigned long long int
#define READ(a) int a; cin>>a
#define sz(a) (int)((a).size())
#define READ2(a,b) int a,b; cin>>a>>b
#define READ3(a,b,c) int a,b,c; cin>>a>>b>>c
#define READ4(a, b, c, d) int a, b, c, d; cin >> a >> b >> c >> d
#define d1(a) cerr << #a << " " << a << endl;
#define d2(a, b) cerr << #a << " " << a << " " << #b << " " << b << endl;
#define d3(a, b, c) cerr << #a << " " << a << " " << #b << " " << b << " " << #c << " " << c << endl;
#define d4(a, b, c, d) cerr << #a << " " << a << " " << #b << " " << b << " " << #c << " " << c << " " << #d << " " << d << endl;
#define f(i, s, e) for(int i=s;i<e;i++)
#define READC(c) char c; cin>>c
#define READA(a,n) int a[n]; f(i,0,n) cin>>a[i]
#define READS(s) string s; cin>>s
#define test int t; cin>>t; while(t--)
#define mod 1000000007
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int,int> 
#define int128 __int128
#define ff first
#define ss second

int power(int x, int y, int p) 
{ 
    int res = 1; 
    x = x % p;  
    while (y > 0){ 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1; 
        x = (x*x) % p; 
    } 
    return res; 
} 
int modInverse(int n, int p) 
{ 
    return power(n, p-2, p)%p; 
}

int a[1001];

bool comp(pair<int, int> i, pair<int, int> j) {
    return a[i.first] < a[j.first];
}

void solve() {
	READ(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<pair<int, int>> sorted(n), ans;
    for(int i = 0; i < n; i++)
        sorted[i].first = a[i], sorted[i].second = i;
    sort(sorted.begin(), sorted.end());
    vector<bool> vis(n, false);
    for(int i = 0; i < n; i++) {
        if(vis[i] || sorted[i].second == i)
            continue;
        int node = i;
        vector<pair<int, int>> G;
        while(!vis[node] && sorted[node].second != node) {
            vis[node] = true;
            
            // d2(node, sorted[node].second)
            node = sorted[node].second;
            // if(vis[node])
            //     break;
            G.push_back({node, sorted[node].second});
        }
        sort(G.begin(), G.end(), comp);
        for(auto e:G) {
            // d2(e.first, e.second)
            ans.push_back({e.second, e.first});
        }
    }
    if(ans.empty()) {
        cout << 0;
        return;
    }
    cout << ans.size() - 1<< endl;
    for(int i = 1; i < ans.size(); i++) {
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
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

	solve();



	#ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
    return 0;
}