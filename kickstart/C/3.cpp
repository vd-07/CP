//Author : Vivek Dubey
#include <iostream>
#include <cstring>
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
char wall[32][32];
int r, c;
string ans;
bool visited[32][32];
bool done;
int count;
void dfs(int x, int y) {
    if(x == r - 1 || visited[x + 1][y]) {
        visited[x][y] = true;
        count++;
        if(x == r - 1) {
            if(y < c - 1 && wall[x][y] == wall[x][y + 1])
                dfs(x, y + 1);
            if(y > 0 && wall[x][y] == wall[x][y - 1])
                dfs(x, y - 1);    
        }
        if(x > 0 && wall[x][y] == wall[x - 1][y])
        dfs(x - 1, y);
    }
}
void solve(){
    cin >> r >> c;
    int ispresent[26] = {};
    pair<int, int> issupported[26];
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> wall[i][j], ispresent[wall[i][j] - 'a']++;
            issupported[wall[i][j] - 'a'] = {i, j};
        }
    }
    memset(visited, false, sizeof(visited));
    ans.clear();
    done = true;
    while(done) {
        int i = 0;
        for(i = 0; i < 26; i++) {
            count = 0;
            if(ispresent[i]) {
                dfs(issupported[i].first, issupported[i].second); 
                if(count == ispresent[i]) break;
            }
        }
        if(i != 26) {
            ans.push_back(i + 'a');    
            ispresent[i] = 0;
        }
        else
            break;
    }
    for(int i = r - 1; i >= 0; i--) {
        for(int j = c - 1; j >= 0; j--) {
            if(i == r - 1 || visited[i][j])
        }
    }
    for(int i = 0; i < 26; i++) {
        if(ispresent[i]) {
            cout << -1 << "\n";
            return;
        }
    }
    cout << ans << "\n";
}

int main(){
    
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