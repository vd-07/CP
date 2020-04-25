#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

const int N = 1e5 + 5;
int n, m;
int colors[N];
vector<int> edges[N];
unordered_set<int> Q[N];
bool visited[N];

void dfs(int u) {
	visited[u] = true;
	
	for(auto e:edges[u]) {
		if(!visited[e])
			dfs(e);
		if(colors[u] != colors[e])
		Q[colors[u]].insert(colors[e]);
	}
}
int main() {
	fastIO
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> colors[i], visited[i] = false;
	int u, v;
	int ans[N];
	for(int i = 0; i <= 100000; i++) ans[i] = 0;
	while(m--) {
		cin >> u >> v;
		if(colors[u] == colors[v]) continue;
		if((Q[colors[u]]).find(colors[v]) == Q[colors[u]].end())
			ans[colors[u]]++;
		if((Q[colors[v]]).find(colors[u]) == Q[colors[v]].end())
			ans[colors[v]]++;
		Q[colors[u]].insert(colors[v]);	
		Q[colors[v]].insert(colors[u]);		
	}
	int color = N, maxi = 0;
	for(int i = 1; i <= n; i++) {
		if(ans[colors[i]] > maxi || (ans[colors[i]] == maxi && colors[i] < color)) {
			color = colors[i];
			maxi = ans[colors[i]];
		}
	}
	cout << color;
	return 0;
}
