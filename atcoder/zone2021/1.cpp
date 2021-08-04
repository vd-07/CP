//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

string operation1(string s) {
	deque<char> dq;

	bool rev = false;

	for(char c : s) {
		if(c == 'R') {
			rev ^= true;
		} else if(rev) {
			dq.push_front(c);
		} else {
			dq.push_back(c);
		}
	} 

	string temp = "";

	if(!rev) {
		while(!dq.empty()) {
			temp += dq.front();
			dq.pop_front();
		}
	} else {
		while(!dq.empty()) {
			temp += dq.back();
			dq.pop_back();
		}
	}

	return temp;
}

string operation2(string s) {
	stack<char> st;

	for(char c : s) {
		if(st.empty()) {
			st.push(c);
		} else {
			if(st.top() == c) {
				st.pop();
			} else {
				st.push(c);
			}
		}
	}	

	string temp = "";

	while(!st.empty()) {
		temp += st.top();
		st.pop();
	}

	reverse(temp.begin(), temp.end());

	return temp;
	
}

void solve() {
	string s;
	cin >> s;

	s = operation1(s);

	s = operation2(s);

	cout << s;

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
	int t = 1;
	// cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}