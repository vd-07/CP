//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;
#define int short int
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

void solve(){
	READ2(n, m);

	pii chef[n], chefina[m];

	for(int i = 0; i < n; i++) cin >> chef[i].first >> chef[i].second;
	for(int i = 0; i < m; i++) cin >> chefina[i].first >> chefina[i].second;

	READ2(bl, br);
	READ(k);

	bool freetime[2401] = {};
	int s, e;

	for(int i = bl; i <= chef[0].first; i++)
		freetime[i] = true;

	for(int i = 1; i < n; i++) {
		if(chef[i].first <= br && chef[i - 1].second >= bl && chef[i].first - chef[i - 1].second >= k) {
			int t = chef[i - 1].second;
			while(t <= chef[i].first) {
				freetime[t++] = 1;
			}
		}
	}
	for(int i = chef[n - 1].second; i <= br; i++)
		freetime[i] = 1;
	// cout << freetime[1159];
	vector<pii> ans;
	for(int i = 1; i < m; i++) {
		if(chefina[i].first <= br && chefina[i - 1].second >= bl) {
			s = chefina[i - 1].second, e = s;
			while(freetime[e] && e++ < chefina[i].first);
			
			if(e - s - 1 >= k) ans.pb({s, e - 1});
			// d4(s, e, k, ans.size());
		}
	}
	s = chefina[m - 1].second, e = br;
	while(s != e) {
		if(!freetime[s])
			s++;
		if(!freetime[e])
			e--;
		if(freetime[e] && freetime[s])
			break;
	}
	if(e - s >= k) ans.pb({s, e});
	if(ans.size() == 0) {
		cout << "NO";
	}
	else {
		cout << "YES\n";
		for(auto e:ans) cout << e.first << " " << e.second << " ";
	}
	cout << "\n";
}

int32_t main(){
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    //this can be opted out if you want to print the output to the sublime console
    freopen("output.txt", "w", stdout);
	#endif
    fastIO

	test solve();



	#ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
    return 0;
}