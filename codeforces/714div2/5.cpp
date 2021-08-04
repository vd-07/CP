//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n, k;
int a[mxN];

void dfs(int node, vector<bool> &visited, vector<string> &related) {
	visited[node] = true;

	for(int i = 0; i < related[node].size(); i++) {
		if(related[node][i] == '1' && visited[i] == false) {
			dfs(i, visited, related);
		}
	}
}

int countGroups(vector<string> related) {
	int n = related.size();

	int relatedGroups = 0;

	vector<bool> visited(n, false);

	for(int i = 0; i < n; i++) {
		if(!visited[i]) {

			dfs(i, visited, related);

			relatedGroups++;
		}
	}

	return relatedGroups;
}

int32_t main() {
	#ifndef ONLINE_JUDGE
	    // for getting input from input.txt
		freopen("input.txt", "r", stdin);
	    // for writing output to output.txt
	    //this can be opted out if you want to print the output to the sublime console
		freopen("output.txt", "w", stdout);
	#endif

	// for fast i/o
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	// test cases
	vector<string> io;
	int n;
	cin >> n;

	while(n--) {
		string s;
		cin >> s;
		io.push_back(s);
	}

	cout << countGroups(io);

	return 0;
}