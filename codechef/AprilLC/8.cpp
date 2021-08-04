#include <iostream>
#include <vector>
#include <cstring>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod 1000000007
#define int long long int 
using namespace std;

int n;
int *cost;
vector<int> edges[100001];
bool *visited;
int **ans;
int curr, rel;
int primefactors[1000001];
int spf[1000001];

int power(int base, int exp) {
	int res = 1; 
	while(exp) {
		if(exp & 1)
			res = (res * base) % mod;
		base = (base % mod * base % mod) % mod;
		exp >>= 1;
	}
	return res % mod;
}

int modInverse(int num) {
	return power(num, mod - 2);
}

void sieve() {
	for(int i = 1; i <= 1000000; i++) spf[i] = i;
	for(int i = 2; i <= 1000000; i++) {
		if(spf[i] == i) {
			for(int j = i * i; j <= 1000000; j += i) {
				spf[j] = i;
			}
		}
	}
}

void factorize(int num) {
	int u = num;
	int count, factor;
	while(num > 1) {
		count = 0;
		factor = spf[num];
		while(num % factor == 0) {
			count++;
			num /= factor;
		}
		rel = (rel % mod *  modInverse(primefactors[factor] + 1) % mod) % mod;
		primefactors[factor] += count;
		rel = (rel % mod * (primefactors[factor] + 1) % mod) % mod;
	}
	ans[curr][u] = rel % mod;
		
}
void dfs(int u) {
	if(u == curr)
	factorize(cost[u]);
	visited[u] = true;
	for(auto e:edges[u])
		if(!visited[e])
			dfs(e);
}

void solve() {
	
	cin >> n;
	visited = new bool[n + 1];
	cost = new int[n + 1];
	int u, v;
	for(int i = 1; i < n; i++) {
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}	
	for(int i = 1; i <= n; i++) cin >> cost[i];
	ans = new int*[n + 1];
	*ans = new int[n + 1];
	for(int i = 1; i <= n; i++) { 
		memset(visited, false, sizeof(visited));
		memset(primefactors, 0ll, sizeof(primefactors));
		curr = i, rel = 1, dfs(i);
	}
	int q;
	cin >> q;
	while(q--) {
		cin >> u >> v;
		cout << max(ans[u][v], ans[v][u]) << "\n";
	}
	delete []ans;
	delete []visited;
	delete []cost;
}
int32_t main() {
	fastIO
		#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    //this can be opted out if you want to print the output to the sublime console
    freopen("output.txt", "w", stdout);
	#endif
	sieve();
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	#ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
	return 0;
}
