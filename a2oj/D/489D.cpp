#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int n, m;
int ct = 0;
vector<int> edges[3001];
int visited[3001];

void go(int u, int count) {
	if(count == 2) {
		visited[u]++;
		return;
	}
	for(auto e:edges[u])
		go(e, count + 1);
}
	
int main() {
	cin >> n >> m;
	int u, v;
	for(int i = 1; i <= m; i++) {
		cin >> u >> v;
		edges[u].push_back(v);
	}
	long long int res = 0;
	for(int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		go(i, 0);
		for(int j = 1; j <= n; j++)
			if(i != j) res += (visited[j] * (visited[j] - 1)) / 2;	
	}
	cout << res;
	return 0;
}
	
