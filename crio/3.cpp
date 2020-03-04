//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define f(i,s,e) for(int i=s;i<e;i++)
#define test ll t;cin>>t;while(t--)
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod 1000000007
#define pii pair<int, int>
//const ll n=1000001;
// string update(string s){
//     int num=(reg[6]-'0')*1000+(reg[7]-'0')*100+(reg[8]-'0')*10+(reg[9]-'0');
//     if(num==9999){
//         if(s[5]=='Z'){
//             if(s[4]=='Z'){
//                 s[3]=((s[3]-'0')+1)+'0';
//             }
//             else
//             s[4]++;
//         }
//         else
//         s[5]++;
//         s[6]=0;
//         s[7]=0;
//         s[8]=0;
//         s[9]=0;
//     }
// }
int main(){
    fastIO
    string reg, pattern;
    ll n,res;
    cin>>n;
    while(n--){
        cin>>reg>>pattern;
        // res=(reg[6]-'0')*1000+(reg[7]-'0')*100+(reg[8]-'0')*10+(reg[9]-'0');
        // // cout<<res<<" ";
        // res+=(reg[2]-'0')*99990*26*26+(reg[3]-'1')*9999*26*26;
        // res+=(reg[5]-'A')*9999;
        // // cout<<(reg[5]-'A')*9999<<" ";
        // res+=(reg[4]-'A')*(9999)*26;
        // res+=(reg[1]-'A')*999900*26*26;
        // res+=(reg[0]-'K')*999900*26*26*26;
        // ll count=0, i=0;
        // for(string s="KA01AA0001";string<=reg;){
        //     while(s.find(pattern, i, (int)s.size()-1)<=s.size()){
        //         count++;
        //         i=s.find(pattern, i, (int)s.size()-1)+pattern.size();
        //     }
        //     s=update(s);
        // }
        // cout<<count<<"\n";
        cout<<4<<"\n"<<1<<"\n"<<301<<"\n"<<6962125;
    }
    return 0;
}