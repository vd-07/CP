//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define f(i,s,e) for(int i=s;i<e;i++)
#define test ll t;cin>>t;while(t--)
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod 1000000007
int days, extra=6, prefix[4801];
void make_prefix(){
    for(int y=0;y<400;y++){
        for(int m=1;m<=12;m++){
            if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
                days=31;
            if(m==4||m==6||m==9||m==11)
                days=30;
            if(m==2)
                days=!y||y%4==0&&y%100?29:28;
            int d1=0,d2=days-1;
            while((extra+d1)%7!=5)
                ++d1;
            while((extra+d2)%7)
                d2--;
            d2-=7;
            prefix[y*12+m]=prefix[y*12+m-1]+(d1+10>d2);
            extra=(extra+days)%7;
        }
    }
}
ll solve2(int m, int y){
    ll r=(ll)prefix[4800]*(y/400);
    r+=prefix[y%400*12+m-1];
    return r;
}
void solve(){
    int m1,y1,m2,y2;
    cin>>m1>>y1>>m2>>y2;
    ++m2;
    if(m2>12)
        {
            m2=1;
            ++y2;
        }
    cout<<solve2(m2,y2)-solve2(m1,y1)<<"\n";
}

int main(){
    fastIO
    make_prefix();
    test solve();
    return 0;
}