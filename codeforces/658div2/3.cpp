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

void change(int a[], int r) {
    for(int i = 1; i <= r; i++) {
        a[i] = a[i] ^ 1;
    }
    reverse(a + 1, a + r + 1);
}

void solve() {
	READ(n);
    char c;
    int a[n + 1], b[n + 1];
    for(int i = 1; i <= n; i++) {
        cin >> c;
        if(c == '1')
            a[i] = 1;
        else
            a[i] = 0;
    }
    for(int i = 1; i <= n; i++) {
        cin >> c;
        if(c == '1')
            b[i] = 1;
        else
            b[i] = 0;
    }
    // cout << a[1] << endl;
    vector<int> ans;
    // two problems
    // 1. flip the bits :> maintain a count variable for this
    // 2. position of elements :> the same sol :> if count is odd then actual pos is prev op idx - curr pos
    int count = 0;
    int l = 1, r = n;
    for(int i = n; i >= 1; i--) {
        if(count & 1) {
            a[r] = a[r] ^ 1;
            if(a[r] ^ 1 != b[i]) {
                ans.pb(1);
            }
            ans.pb(i);
            count++;
            r--;
        }
        else {
            count++;
            if(a[l] ^ 1 != b[i]) {
                ans.pb(1);
            }
            ans.pb(i);
            //     count++;
            l++;
        }
        //fix each i
        // int pos;
        // int at1;
        // if(idx == -1) {
        //     pos = i;
        //     at1 = 1;
        // }
        // else if(count & 1) {
        //     pos = idx - i;
        //     at1 =  i;
        // }
        // a[pos] = a[pos] ^ (count & 1);
        // // if(a[pos] == b[i]) {

        // //     continue;
        // // }
        // if(a[at1] ^ 1 == b[i]) {
        //     count++;
        //     ans.pb(i);

        // }
        // if(a[at1] ^ 1 != b[i]) {
        //     // d1(i)
        //     ans.pb(1);
        // }
        // // // if(a[i] == b[i])
        // // //     continue;
        // ans.pb(1);
        // count++;
        // idx = i;
        // a[i] = b[i];

        // if(a[1] ^ 1 == b[i]) {
        //     ans.pb(i);
        //     change(a, i);
        // }

    }
    cout << ans.size() << " ";
    for(auto e:ans) cout << e << ' ';
    cout << "\n";
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