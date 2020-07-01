//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;
// #define int long long int
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
vector<int> perfects;
int n, sum = 0;
void solve() {
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int sum = 0;
    unordered_map<int, int> ispresent;
    int count = 0;
    ispresent[0] = 1;
    int curr = 0, maxsum = INT_MIN;
    for(int i = 0; i < n; i++) {
        sum += a[i];
        curr += a[i];        
        maxsum = max(curr, maxsum);
        if(curr < 0) 
            curr = 0;
        for(int j = 0; perfects[j] <= maxsum; j++) {
            // if(a[i] == perfects[j]) count++;
            if(ispresent.find(sum - perfects[j]) != ispresent.end())
            count += ispresent[sum - perfects[j]];
        }
        ispresent[sum]++;
    }
    cout << count << "\n";
}

int main(){
    for(int i = 0; i * i <= 1e7 + 20; i++) {
        perfects.pb(i * i);
    }
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    //this can be opted out if you want to print the output to the sublime console
    freopen("output.txt", "w", stdout);
    #endif
    fastIO
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cout << "Case #"<< i << ": ";
        solve();
    }

    



    
    return 0;
}