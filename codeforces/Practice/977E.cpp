#include <iostream>
#include <vector>
#include <cstring>
#define int long long int
using namespace std;

int n, m;
vector<int> edges[300000];
int degree[300000];
bool visited[300000];

void dfs(int u, vector<int>& conn) {
	visited[u] = true;
	conn.push_back(u);
	for(auto e:edges[u])
		if(!visited[e])
			dfs(e, conn);
}
int32_t main() {
	memset(degree, 0ll, sizeof(degree));
	memset(visited, false, sizeof(visited));
	cin >> n >> m;
	int u, v;
	for(int i = 1; i <= n; i++) {
		cin >> u >> v;
		degree[u]++, degree[v]++;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}	
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(visited[i]) continue;
		vector<int> conn;
		dfs(i, conn);
		bool found = true;
		for(auto e:conn)
			if(degree[e] != 2)
				found = false;
		if(found) ans++;
	}	
	cout << ans;
	return 0;
}

