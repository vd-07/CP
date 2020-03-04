//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define f(i,s,e) for(int i=s;i<e;i++)
#define test ll t;cin>>t;while(t--)
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod 1000000007
void solve(){
    int y1,y2,m1,m2;
    cin>>m1>>y1;
    cin>>m2>>y2;
    int ct=0,extra,a=0;
    bool got=false;
    if(y1==y2){
        if(m1>2||m2<2)
            {
                cout<<0<<"\n";
                return;
            }
    }
    // cout<<y2<<" "<<y1<<"\n";
    if(y2-y1==1){
        if(m1>2&&m2<2)
            {
                cout<<0<<"\n";
                return;
            }
    }
    if(m1>2)
    y1++;
    if(m2<2)
    y2--;
    if(y2<y1)
    swap(y1,y2);
    if(y2>2021){
        int newest=((y1-2020)/400)*400+2020;
    extra=0;
    //finding extra before y1
    for(int i=newest;i<y1;i++){
        if((i%4==0&&(i%100))||(i%400==0))
        extra=(extra+2)%7;
        else
        extra=(extra+1)%7;
    }
    // cout<<extra<<" ";
    newest=min(newest+400,y2);
    //from y1 till first 2020+400*n
    int y1pseudo=max(y1,2020);
    for(int i=y1pseudo;i<=newest;i++){
        ct+=(extra==0)+(extra==1)*(!((i%4==0&&(i%100))||(i%400==0)));
        if((i%4==0&&(i%100))||(i%400==0))
        extra=(extra+2)%7;
        else
        extra=(extra+1)%7;
    }
    // cout<<ct<<" ";
    //since in one complete 400 years total conditions satisfied is 101
    ct+=((y2-newest)/400)*101;
    int est;
    if(y2-newest<400)
    est=1;
    else
    est=0;
    newest=((y2-newest)/400)*400+newest+est;
    
    //from last 2020+400*n till y2
    if(newest!=y2){
        for(int i=newest;i<=y2;i++){
        ct+=(extra==0)+(extra==1)*(!((i%4==0&&(i%100))||(i%400==0)));
        if(i==y2)
        break;
        if((i%4==0&&(i%100))||(i%400==0))
        extra=(extra+2)%7;
        else
        extra=(extra+1)%7;
    }
    }
    
    // cout<<ct<<" ";
    // cout<<extra<<" ";
    if(extra==1||extra==0)
        got=true;
    
    }
    // cout<<ct<<" ";
    extra=0;
    
	for(int i=2020;i>=y1;i--){
	    ct+=(extra==0)+(extra==6)*(!((i%4==0&&(i%100))||(i%400==0)));
        // cout<<"year : "<<i<<" extra : "<<extra<<endl;
        if(i==y2){
            a=ct;
            if(extra==0||(extra==6&&(!((i%4==0&&(i%100))||(i%400==0)))))
            got=true;
        }
        if((i%4==0&&(i%100))||(i%400==0))
            extra=(extra-2+7)%7;
        else
            extra=(extra-1+7)%7;
   }
//    cout<<y1<<" "<<y2<<endl;
    // if(ct==a&&(got))
    // cout<<1<<"\n";
    // else
    // cout<<ct-a+1<<"\n";
    // cout<<extra<<"\n";
    if(got)
    ct++;
    if(a>ct)
    ct++;
    if(y1<=2020&&y2>2020)
    ct--;
    if(got==false&&y1==y2)
    cout<<0<<"\n";
    else
    cout<<ct-a<<"\n";
//    cout<<ct<<" "<<a<<"\n";
}

int main(){
    fastIO
    test solve();
    return 0;
}