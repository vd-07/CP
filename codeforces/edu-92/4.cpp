//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define uint unsigned long long int
#define sz(a) (int)((a).size())
//read
#define READ(a) int a; cin>>a
#define READ2(a,b) int a,b; cin>>a>>b
#define READ3(a,b,c) int a,b,c; cin>>a>>b>>c
#define READ4(a, b, c, d) int a, b, c, d; cin >> a >> b >> c >> d
#define READC(c) char c; cin>>c
#define READA(a,n) int a[n]; for(int i = 0; i < n; i++) cin>>a[i]
#define READS(s) string s; cin>>s
//debug
#define d1(a) cerr << #a << " " << a << endl;
#define d2(a, b) cerr << #a << " " << a << " " << #b << " " << b << endl;
#define d3(a, b, c) cerr << #a << " " << a << " " << #b << " " << b << " " << #c << " " << c << endl;
#define d4(a, b, c, d) cerr << #a << " " << a << " " << #b << " " << b << " " << #c << " " << c << " " << #d << " " << d << endl;
//for loop
#define F_OR(i, a, b, s) for (int i = (a); ((s) > 0 ? i < (b) : i > (b)); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
//general
#define test int t; cin>>t; while(t--)
#define mod 1000000007
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int,int> 
#define int128 __int128
#define ff first
#define ss second

int power(int x, int y, int p) 
{ 
    int res = 1; 
    x = x % p;  
    while (y > 0){ 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1; 
        x = (x*x) % p; 
    } 
    return res; 
} 
int modInverse(int n, int p) 
{ 
    return power(n, p-2, p)%p; 
}

void solve() {
	READ2(n, k);
    READ2(l1, r1);
    READ2(l2, r2);
    if(l1 > l2) {
        swap(l1, l2);
        swap(r1, r2);
    }
    if(l2 < r1) {
        //removing the already intersected parts
        if(r2 < r1) {
            k -= n * (r2 - l2);
            r1 -= r2 - l2;
            l2 = r2 = r1;
        }
        else {
            k -= n * (r1 - l2);
            r2 -= (r1 - l2);
            r1 -= r1 -  l2;
        }
    }
    if(k <= 0) {
        cout << "0\n";
        return;
    }
    int ans = LLONG_MAX;
    for(int i = 1; i <= n; i++) {
        int curr = i * (l2 - r1);
        // ans = min(ans, curr);
        int got = i * (r2 - l1);
        curr += min(k, got);
        if(got < k) {
            curr += 2 * (k - (got));
        }
        ans = min(ans, curr);
    }
    cout << ans << "\n";
    // int done = (l2 - r1) * n;
    // int range1 = r1 - l1, range2 = r2 - l2;
    // int ans = INT_MAX;
    // if(n * (r1 - l1) >= k + done * (done < 0) || (n * (l2 - r1)) >= k + done * (done < 0)) {
    //     done = l2 - r1;
    //     if(done < 0) {
    //         ans = min({ans, ceil(k / (range1 + done)), ceil(k / (range2 + done))});
    //     }
    //     else 
    //         ans = min({ans, ceil(k / range1), ceil(k / range2)});
    // }
    // else if(n * (range1 + range2) >= k) {
    //     done = l2 - r1;
    //     ans = ceil(k / (range1 + range2));
        
    // }
}

int32_t main() {
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