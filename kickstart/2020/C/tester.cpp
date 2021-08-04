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
// int n, sum = 0;
int solve2(int n, vector<int> a) {
    // cin >> n;
    // int a[n];
    // for(int i = 0; i < n; i++) cin >> a[i];
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
    // cout << count << "\n";
    return count;
}

int solve1(int n, vector<int> a) {
    int count = ceil(sqrt(a[0])) == floor(sqrt(a[0]));
    for(int i = 1; i < n; i++) {
        a[i] += a[i - 1];
        count += ceil(sqrt(a[i])) == floor(sqrt(a[i]));;
    }
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            count += ceil(sqrt(a[j] - a[i])) == floor(sqrt(a[j] - a[i]));
        }
    }
    return count;
}

int main(){
    for(int i = 0; i * i <= 1e7 + 20; i++) {
        perfects.pb(i * i);
    }
    // cout << "vd";
    srand(time(0));
    int steps = 0;
    // cout << "vd";
    while(1000) {
        int randn = (rand() % (10000) + 1);
        vector<int> randvec;
        for(int i = 0; i < randn; i++)
            randvec.push_back((rand() % (201) -100));
        steps++;
        cout << steps << " " << randn << "\n";
        int ans1 = solve1(randn, randvec), ans2 = solve2(randn, randvec);
        if(ans1 != ans2) {
            cout << "BUG\n";
            cout << ans1 << " " << ans2 << endl;
            cout << randn << endl;
            for(auto e:randvec) cout << e << " ";
            break;
        }
        cout << ans1 << ' ' << ans2 << "\n";
    }
    
    return 0;
}