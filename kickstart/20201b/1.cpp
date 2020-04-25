//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define uint unsigned long long int
#define READ(a) int a; cin>>a
#define sz(a) (int)((a).size())
#define READ2(a,b) int a,b; cin>>a>>b
#define READ3(a,b,c) int a,b,c; cin>>a>>b>>c
#define READ4(a, b, c, d) int a, b, c, d; cin >> a >> b >> c >> d
#define d1(a) cerr << #a << " " << a << endl;
#define d2(a, b) cerr << #a << " " << a << " " << #b << " " << b << endl;
#define d3(a, b, c) cerr << #a << " " << a << " " << #b << " " << b << " " << #c << " " << c << endl;
#define d4(a, b, c, d) cerr << #a << " " << a << " " << #b << " " << b << " " << #c << " " << c << " " << #d << " " << d << endl;
#define f(i, s, e) for(int i=s;i<e;i++)
#define READC(c) char c; cin>>c
#define READA(a,n) int a[n]; f(i,0,n) cin>>a[i]
#define READS(s) string s; cin>>s
#define test int t; cin>>t; while(t--)
#define mod 1000000007
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int,int> 
string ans;
int a, b;
bool done = false;
int an = INT_MAX;
map<array<int, 3>, bool> dp;

void calc(int x, int y, string s = "") {
	
	if(done) {
		if(s.size() > an)
		return;
	}
	if(x == a && y == b) {
	    if(an > s.size()) {
		    ans = s;
		    an = s.size();
		    done = true;    
	    }
		return;
	}
	// if(s == "SEN") d2(x, y);
	// d1(s);
	int n = s.size();

	if(dp[{x, y, n}])
	    return;
	dp[{x, y, n}] = 1;
	
	int fac = 1 << (n);
	if(n == 4)
		return;
	calc(x - fac, y, s + "W");
	calc(x, y - fac, s + "S");
	calc(x + fac, y, s + "E");
	calc(x, y + fac, s + "N");
}
void solve(){
    dp.clear();
	cin >> a >> b;
	ans = "";
	done = false;
	an = INT_MAX;
	calc(0, 0);
	if(done)
		cout << ans << "\n";
	else
		cout << "Impossible\n";
}

int32_t main(){
	
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    //this can be opted out if you want to print the output to the sublime console
    freopen("output.txt", "w", stdout);
	#endif

    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
    	cout << "Case #"<< i << ": ";
    	solve();
    }

	



	
    return 0;
}