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
double round(double value){
    double val=(int)(value*100+0.5);
    return (double)val/100;
}
bool comp(pair<double, string> a, pair<double, string> b){
    return a.first>b.first;
}
int main(){
    fastIO
    // test solve();
    int n;
    cin>>n;
    string name;
    double price,discount;
    vector<pair<double, string> > shop;
    for(int i=0;i<n;i++){
        cin>>name>>price>>discount;
        price=price-(price*discount)/100;
        price=round(price);
        shop.push_back({price,name});
    }
    sort(shop.begin(),shop.end(),comp);
    // cout<<setprecision(2);
    double total=0;
    for(auto e:shop){
        // cout<<e.second<<" ";
        printf("%s %.2lf\n",(string)e.second, e.first);
        total+=e.first;
    }
    // cout<<"Total "<<total;
    printf("Total %.2lf", total);



    return 0;
}