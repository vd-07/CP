#include <bits/stdc++.h> 
using namespace std; 

const int ALPHABET_SIZE = 13; 

// trie node '
const int mxn = 5 * (1e6) + 1;
int spf[mxn];

void preprocess() {
	for(int i = 1; i < mxn; i++) {
		spf[i] = i;
	}
	for(int i = 2; i * i < mxn; i++) {
		if(spf[i] == i) {
			for(int j = i * i; j < mxn; j += i) {
				spf[j] = i;
			}
		}
	}
}

int prio(int num) {
	int ct = 0;
	while(num > 1) {
		int pf = spf[num];
		while(num % pf == 0) {
			num /= pf;
			ct++;
		}
	}
	return ct;
}

map<string, string> mp = {{"a","a"},{"a#","b"},{"b","c"},{"c","d"},{"c#","e"},{"d","f"},{"d#","g"},{"e","h"},{"f","i"},
{"f#","j"},{"g","k"},{"g#","l"}};

struct TrieNode 
{ 
	TrieNode *children[ALPHABET_SIZE]; 
	pair<int, int> power;
}; 

// Returns new trie node (initialized to NULLs) 
TrieNode *getNode() 
{ 
	TrieNode *pNode = new TrieNode; 

	pNode->power = {0, 0}; 

	for (int i = 0; i < ALPHABET_SIZE; i++) 
		pNode->children[i] = NULL; 

	return pNode; 
} 

// If not present, inserts key into trie 
// If the key is prefix of trie node, just 
// marks leaf node 
void insert(TrieNode *root, string key, int pw) 
{ 

	TrieNode *pCrawl = root; 

	for (int i = 0; i < key.size(); i++) 
	{ 
		int index = key[i] - 'a'; 

		cout << index << " " << key[i];

		if (!pCrawl->children[index]) 
			pCrawl->children[index] = getNode(); 

		pCrawl = pCrawl->children[index]; 
	} 

	// mark last node as leaf 
	pCrawl->power = {prio(pw), pw}; 
} 

// Returns true if key presents in trie, else 
// false 

int search(struct TrieNode *root, string key) 
{ 
	struct TrieNode *pCrawl = root; 

	for (int i = 0; i < key.length(); i++) 
	{ 
		int index = key[i] - 'a'; 
		// if (!pCrawl->children[index]) 
		// 	return false; 

		pCrawl = pCrawl->children[index]; 
	} 

	return (pCrawl->power).second; 
} 

pair<int, int> dfs(struct TrieNode *root) {
	if(root == NULL)
		return {0, 0};

	pair<int, int> curr = root->power;

	// all children
	for (int i = 0; i < ALPHABET_SIZE; i++) {
		pair<int, int> childValue = dfs(root->children[i]);

		if(curr.first < childValue.first) {
			curr = childValue;
		} else if(curr.first == childValue.first) {
			curr.second = max(curr.second, childValue.second);
		}
	}
	
	root->power = curr;

	return curr;


}

// Driver 
int main() 
{ 
	int n, t;
	cin >> n >> t;

	struct TrieNode *root = getNode(); 

	int p, l;
	string temp;

	while(n--) {
		cin >> p >> l;
		string note = "";

		while(l--) {
			cin >> temp;
			note += (mp[temp]);
		
			cout << note << endl;
		}
		
		insert(root, note, p);
		
	}
	
	dfs(root);

	while(t--) {
		cin >> l;
		string note = "";
		while(l--) {
			cin >> temp;
			note += mp[temp];
		}

		cout << search(root, note) << "\n";
	}

	return 0; 
} 
