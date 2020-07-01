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

const int mod = 1e9 + 7;
const int p = 31;
void compute_hash(string const& s, int prefix[]) {
    long long hash_value = 0;
    long long p_pow = 1;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % mod;
        prefix[i] = hash_value;
        p_pow = (p_pow * p) % mod;
    }
}
int ppp[100001];
void solve() {
	READS(s);
    int n = s.size();
    int prefix[n] = {};
    compute_hash(s, prefix);
    int count = 0;
    int s1 = 0, s2 = 0, s3 = 0;
	for(int i = 0; ; i++) {
        int s1 = i, s2 = 2 * i + 1;
        int s3 = (n - s2) / 2 + s2; 
        if(s3 + 1 >= n) break;
        // d3(s1, s2, s3)
        int t11 = prefix[s1],
            t12 = prefix[s2] - prefix[s1],
            t21 = prefix[s3] - prefix[s2],
            t22 = prefix[n - 1] - prefix[s3];
        t11 = ((t11 + mod) % mod);
        t12 = (((t12 + mod) % mod) * (modInverse(ppp[s1 + 1] % mod, mod)) % mod) % mod;
        t21 = (((t21 + mod) % mod) * (modInverse(ppp[s2 + 1] % mod, mod)) % mod) % mod;
        t22 = (((t22 + mod) % mod) * (modInverse(ppp[s3 + 1] % mod, mod)) % mod) % mod;
        // d1(i)
        // d4(t11, t12, t21, t22)
        if(t11 == t12 && t21 == t22)
            count++;
    }
    cout << count << "\n";
}

int32_t main() {
    ppp[0] = 1; 
    for(int i=1; i<=100001; i++) 
        ppp[i] = (ppp[i-1]%mod * p%mod)%mod; 
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    //this can be opted out if you want to print the output to the sublime console
    freopen("output.txt", "w", stdout);
	#endif


	test solve();



	// #ifndef ONLINE_JUDGE
 //    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	// #endif
    return 0;
}