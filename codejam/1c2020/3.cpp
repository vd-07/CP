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

void solve(){
	READ2(n, d);
    READA(a, n);
    unordered_map<int, int> freq, pieces, cuts;
    int maxfreq = 0;
    for(int i = 0; i < n; i++) {
        freq[a[i]]++;
        if(maxfreq < freq[a[i]]) {
            maxfreq = freq[a[i]];
        }
        pieces[a[i]]++;
    }
    if(d <= maxfreq) {
        cout << 0 << "\n";
        return;
    }
    if(n == 1) {
        cout << d - 1 << "\n";
        return;
    }
    sort(a, a + n);
    int mincuts = d - 1;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(pieces[a[j]] == d) continue;
            int c = a[i] / a[j];
            int formed = c;
            if(a[i] % a[j] == 0) {
                // formed++;
                c--;
            }
            // if(a[i] % a[j])
            //     formed--;
            if(pieces[a[j]] + formed >= d) {
                int diff = d - pieces[a[j]] - formed;
                c -= diff;
                // d4(cuts[a[j]], a[j], pieces[a[j]], a[i])
                mincuts = min(mincuts, cuts[a[j]] + c);
                // d3(cuts[a[j]], a[j], pieces[a[j]])
                pieces[a[j]] = d;
                continue;
            }
            pieces[a[j]] += formed;
            cuts[a[j]] += c;

        }
    }
    cout << mincuts;
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


	int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
      cout << "Case #"<<i<<": ";
      solve();
    }



	#ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
    return 0;
}