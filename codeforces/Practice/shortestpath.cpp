//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;
#define int long long int
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
// Guide on how to use 128 bit integer on g++

int edges[4000][4000] = {};
int forbidden[4000] = {};
int p[4000];
int vis[4000] = {};

void bfs(int node, int n) {
	queue<array<int, 2>> q;
	q.push({node, 0});
	// vis[node] = true;
	p[node] = -1;
	while(!q.empty()) {
		array<int, 2> v = q.front();
		q.pop();
		for(int i = 1; i <= n; i++) {
			if(edges[v[0]][i] == 0) continue;
			if(forbidden[ov[1]] == v[0] && forbidden[v[0]] == i)
				continue;
			if(vis[i]) continue;
			vis[i] = true;
			q.push({i, v[0]});
			p[i] = v[0];
		}
	}
	d1(node);
}

void solve(){
	READ3(n, m, k);
	int a, b, c;
	for(int i = 1; i <= m; i++) {
		cin >> a >> b;
		edges[a][b] = 1;
		edges[b][a] = 1;
	}
	for(int i = 1; i <= k; i++) {
		cin >> a >> b >> c;
		forbidden[a] = b;
		forbidden[b] = c;
	}

	bfs(1, n);
	if(!vis[n]) {
		cout << -1;
		return;
	}
	vector<int> path;
	for(int i = n; i != -1; i = p[i]) {
		path.pb(i);
	}
	cout << path.size() - 1 << "\n";
	reverse(path.begin(), path.end());
	for(int v:path) {
		cout << v << " ";
	}

}

int32_t main(){
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    //this can be opted out if you want to print the output to the sublime console
    freopen("output.txt", "w", stdout);
	#endif

	solve();

	#ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
    return 0;
}