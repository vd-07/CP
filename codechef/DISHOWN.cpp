#include<iostream>
using namespace std;

	int p[10001], dish[10001];
	void DisjointSet(int arr[], int n) {
		for(int  i = 1; i <= n; i++) {
			p[i] = i;
			dish[i] = arr[i];
		}	
	}
	int findSet(int i) {
		return p[i] == i ? i : p[i] = findSet(p[i]);
	}
	void unionMe(int i, int j) {
		int x = p[i], y = p[j];
		if(x == y) {
			cout<<"Invalid query!\n";
			return;
		}
		if(dish[x] > dish[y]) {
			p[y] = x;
		} else {
			p[x] = y;
		}
	}

void solve() {
	int n;
	cin>>n;
	int s[n + 1];
	for(int  i = 1; i < n; i++) cin>>s[i];
	DisjointSet(s, n);
	int q;
	cin>>q;
	while(q--) {
		int c, x, y;
		cin>>c;
		if(c == 0) {
			cin>>x>>y;
			if(s[x] == s[y])
				continue;	
			else
				unionMe(x, y);
		}
		else {
			cin>>x;
			cout<<findSet(x)<<"\n";
		}
	}	
}
int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
