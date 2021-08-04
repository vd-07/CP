#include <bits/stdc++.h>

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long int 

using namespace std;

//by me
class DisjointUnion {
	private:
		vector<int> p, rank;
	public:
		DisjointUnion(int N) {
			p.assign(N + 1, 0);
			for(int i = 1; i <= N; i++) p[i] = i;
			rank.assign(N + 1, 0);
		}

		int findMe(int node) {
			return p[node] == node ? node : p[node] = findMe(p[node]);
		}
		void unionMe(int i, int j) {
			int x = findMe(i), y = findMe(j);
			if(x != y) {
				if(rank[x] > rank[y]) {
					p[y] = x;	
				} else {
					p[x] = y;
					if(rank[x]  == rank[y])
						rank[y]++;
				}
			}
		}
};
bool comp(pair<int, int> p1, pair<int, int> p2) {
    if(p1.first > p2.first)
        return true;
    return false;
}
int32_t main() {
	fastIO	
	int n, m;
	cin >> n >> m;
	DisjointUnion dsu(n);
	while(m--) {
		int a, b;
		cin >> a >> b;
		dsu.unionMe(a, b);
	}
	map<int, int> mp;
	bool visited[n+1] = {};
	for(int  i = 1; i <= n; i++) {
 		int c;
		cin >> c;
		int node = dsu.findMe(i);
		if(!visited[node]) {
		    mp[node] = 1000000;
		    visited[node] = true;
		}
	    if(c < 0) {
	        c = 1000000;
	    }
	    mp[node] = min(mp[node], c);
	}
	
	if(mp.size() == 1) {
	    cout<<0;
	    return 0;
	}
	int miX = INT_MAX, ans = 0;
	for(auto e:mp) {
	   if(e.second > 10000) {
	       cout<<-1;
	       return 0;
	   }
	   miX = min(miX, e.second);
	   ans += e.second;
	}
	
	ans = ans + (int)(mp.size() - 2) * miX;
	cout << ans;
	return 0;	
}	
