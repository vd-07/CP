#include <iostream>
using namespace std;

int n, r, c;
int p[2000000], rank[1000000];
bool state[1000000];
int numSource[1000000];
void init(int n) {
	for(int  i = 1; i <=n ; i++) {
 		p[i] = i;
		rank[i] = 0;
		state[i] = false;
		numSource[i] = 0;
	}
}

int findMe(int node) {
	return p[node] == node ? node : p[node] = findMe(p[node]);
}

void unionUs(int i, int j) {
	int x = findMe(i), y = findMe(j);
	if(x != y) {
		if(rank[x] > rank[y]) 
			p[y] = x;
		else {
			p[x] = y;
			if(rank[x] == rank[y])
				rank[y]++;			
		}
		if(state[x] || state[y]) {
			state[x] = true;
			state[y] = true;	
		}
	}
}
int x, y;

int converted(char c) {
	if(c > 96) 
		return (c - 'a') + 26;
	else
		return (c - 'A');
}
void getCoordinates(string s) {
	int t1 = converted(s[1]) * 26 + converted(s[2]);
	int t2 = converted(s[3]) * 26 + converted(s[4]);
	x = t1 + ((t2 + 4) / 5 - 1) * c;
	
	if(s.size() == 5)
	return;
	int t1 = converted(s[5]) * 26 + converted(s[6]);
        int t2 = converted(s[7]) * 26 + converted(s[8]);
        y = t1 + ((t2 + 4) / 5 - 1) * c;	
}

int main() {
	cin>>n>>r>>c;
	init(r * c);
	while(n--) {
		string s;
		cin>>s;
		getCoordinates(s);
		if(s[0] == 'W'){
			unionUs(x, y);	
		}	
		if(s[0] == 'V') {
 			numSource[x]++;
			state[x] = true;
		}
		if(s[0] == 'R') {
			numSource[x]--;
			if(numSource[x] == 0) state[x] = false;
		}
		if(s[0] == 'L') {
			if(state[x] != state[y])
				cout<<"ON\n";
			else
				cout<<"OFF\n";
		}
	}	
	return 0;
}
