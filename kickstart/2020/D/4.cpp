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
	READ2(n, q);
    int locked[n];
    for(int i = 1; i < n; i++) cin >> locked[i];
    int start, k;
    while(q--) {
        cin >> start >> k;
        if(start == n) {
            cout << n - k + 1 << " ";
            continue;
        }
        if(start == 1) {
            cout << k << " ";
            continue;
        }
        int ptr = start;
        int lo = start, hi = start;
        while(k > 1) {
            // d3(lo, hi, ptr)
            if(ptr == n || ptr == 1) {
                break;
            }
            if(lo > 1 && locked[lo - 1] < locked[hi]) {
                lo--;
                ptr = lo;
            }
            else {
                hi++;
                ptr = hi;
            }
            k--;
        }
        if(k > 1) {
            if(lo == 1) {
                cout << hi + k - 1 << " ";
            }
            else
                cout << lo - k + 1<< " ";
        }
        else {
            cout << ptr << " ";
        }
    }
    cout << "\n";
}

int32_t main() {
	// #ifndef ONLINE_JUDGE
 //    // for getting input from input.txt
 //    freopen("input.txt", "r", stdin);
 //    // for writing output to output.txt
 //    //this can be opted out if you want to print the output to the sublime console
 //    freopen("output.txt", "w", stdout);
	// #endif
 //    fastIO

	int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cout << "Case #"<< i << ": ";
        solve();
    }



	// #ifndef ONLINE_JUDGE
 //    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	// #endif
    return 0;
}