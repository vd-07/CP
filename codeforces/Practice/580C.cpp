#include <iostream>
#include <vector>
#define int long long int
using namespace std;

int n, m, cats[200000];
vector<vector<int> > edges(200000);
int count = 0;
bool visited[200000] = {};

void dsf(int u, int catsc = 0) {
	if(cats[u]) catsc++;
	else catsc = 0;
	if(catsc > m) return;
	visited[u] = true;
	int alreadyVisited = 0;
	for(auto e:edges[u]) {
		if(!visited[e])
			dsf(e, catsc);
		else
			alreadyVisited++;
	}
//	cout<<u<<" "<<alreadyVisited<<" "<<edges[u].size()<<endl;
	if(alreadyVisited == edges[u].size())
	count++;
}

int32_t main() {
	cin >> n >> m;
	int x, y;
	for(int i = 1; i <= n; i++) {
		cin >> cats[i];
	}
	for(int i = 0; i < n - 1; i++) {
		cin >> x >> y;
		edges[x].push_back(y);
		edges[y].push_back(x);		
	}
	dsf(1);
	cout<<count;
	return 0;
}


