//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

// Macros
// #define int long long int
#define uint unsigned long long int
#define sz(a) (int)((a).size())
//read
#define read(a) int a; cin >> a
#define read2(a, b) int a,b; cin>>a>>b
#define read3(a, b, c) int a, b, c; cin >> a >> b >> c
#define read4(a, b, c, d) int a, b, c, d; cin >> a >> b >> c >> d
#define readC(c) char c; cin >> c
#define readA(a, n) int a[n]; for(int i = 0; i < n; i++) cin >> a[i]
#define readS(s) string s; cin >> s
//debug
#define d1(a) cerr << #a << " " << a << endl;
#define d2(a, b) cerr << #a << " " << a << " " << #b << " " << b << endl;
#define d3(a, b, c) cerr << #a << " " << a << " " << #b << " " << b << " " << #c << " " << c << endl;
#define d4(a, b, c, d) cerr << #a << " " << a << " " << #b << " " << b << " " << #c << " " << c << " " << #d << " " << d << endl;
//general
#define test int t; cin >> t; while(t--)
#define mod 1000000007
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int,int> 
#define ff first
#define ss second

vector<string> constructed;
int curr_idx;
int min_idx, max_idx;

map<string, int> ans;

struct TrieNode{
	TrieNode *children[26];
	// int index;
	int pos;
	int count;
};

TrieNode *makeNode() {
	TrieNode *obj = new TrieNode;
	for(int i = 0; i < 26; i++) {
		obj->children[i] = NULL;
	}
	// obj->index = -1;
	obj->pos = -1;
	obj->count = 0;
	return obj;
}

string min_all, max_all;

TrieNode *insertTrie(string s, TrieNode* root, int is) {
	string temp = "";

	bool newNodeCreated = false;

	for(int i = 0; i < s.size(); i++) {
		temp += s[i];
		int idx = s[i] - 'a';
		if(root->children[idx] == NULL) {
			// it is out of the race of pure prefix
			newNodeCreated = true;
			root->children[idx] = makeNode();
		}

		// if already some word with the current prefix
		if(root->count == 1 && curr_idx == -1) {
			root->count ++;
			
			if(ans.find(temp) != ans.end()) {
				ans.erase(temp);
			}
		}
		
		root = root->children[idx];
	}
	// mark word end
	root->count++;

	// retrieve the original word
	if(curr_idx != -1) {
		s = constructed[curr_idx - 1] + s;
	}
	
	// if no pure prefix
	if(root->count <= 1 && newNodeCreated) {
		ans[s] = is;
	}
	else {
		// duplicate found
		if(ans.find(s) != ans.end()) {
			ans.erase(s);
		}
		// else already deleted
	}

	return root;
}

// void dfs_min(TrieNode *root) {
// 	if(min_idx != -1)
// 		return;
// 	// d1(root->index)
// 	bool ok = true;
// 	for(int i = 0; i < 26; i++) {
// 		if(root->children[i] != NULL) {
// 			// d1(char(i + 'a'))
// 			ok = false;
// 			dfs_min(root->children[i]);
// 		}
// 	}
// 	if(ok) {
// 		if(root->count == 1) {
// 			min_idx = root->index;
// 		}
// 	}
	
// }

// void dfs_max(TrieNode *root) {

// 	if(max_idx != -1)
// 		return;

// 	bool ok = true;
// 	for(int i = 25; i >= 0; i--) {
// 		if(root->children[i] != NULL) {
// 			ok = false;
// 			dfs_max(root->children[i]);
// 		}
// 	}
	
// 	if(ok) {
// 		if(root->count == 1) {
// 			max_idx = root->index;
// 		}
// 	}
// }


void solve() {
	TrieNode *root = makeNode();
	int n;
	cin >> n;

	string s;
	
	vector<TrieNode*> lastpos;

	constructed.clear();
	ans.clear();

	curr_idx = -1;
	min_idx = -1;
	max_idx = -1;

	for(int i = 0; i < n; i++) {
		cin >> s;
		lastpos.pb(insertTrie(s, root, i + 1));
		constructed.pb(s);
	}

	int idx = n + 1;
	int q;

	cin >> q;

	// check for cases like aaaa, aaaa
	// both will be pure prefix
	// so need to recur to next

	int type;
	
	string c;

	while(q--) {
		cin >> type;
		if(type == 1) {
			cin >> curr_idx >> c;
			// saving time by callign the last prefix pointer
			lastpos.pb(insertTrie(c, lastpos[curr_idx - 1], idx++));
			constructed.pb(constructed[curr_idx - 1] + c);
			
		}
		else if(type == 2) {
			min_idx = ans.begin()->second;
			cout << min_idx << "\n";
		}
		else {
			max_idx = ans.rbegin()->second;
			cout << max_idx << "\n";
		}
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

	// for fast i/o
    fastIO

    // begin reading test cases
	test solve();

    return 0;
}