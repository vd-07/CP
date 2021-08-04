//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define f(i,s,e) for(int i=s;i<e;i++)
#define test ll t;cin>>t;while(t--)
#define mod 1000000007


int main(){
    ll overall=0;
    test {
        int n;
        cin>>n;
        int show[4][15]={};
        int t;
        char m;
        for(int i=0;i<n;i++){
            cin>>m>>t;
            show[m-'A'][t]++;
        }
        ll curr,mpro=INT_MIN;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(i==j)
                    continue;
                for(int k=0;k<4;k++){
                    if(k==j||k==i)
                        continue;
                    for(int l=0;l<4;l++){
                        if(l==i||l==j||l==k)
                        continue;
                        int temp[]={show[i][3],show[j][6],show[k][9],show[l][12]};
                        sort(temp,temp+4);
                        curr=temp[0]*25+temp[1]*50+temp[2]*75+temp[3]*100;
                        curr-=((!show[i][3])+(!show[j][6])+(!show[k][9])+(!show[l][12]))*100;
                        // if(i==3&&j==2&&k==0&&l==1)
                        // cout<<"For case 1 :"<<curr<<"\n\n";
                        mpro=max(mpro,curr);
                    }
                }
            }
            
        }
        cout<<mpro<<"\n";
        overall+=mpro;
    }
    cout<<overall;
    return 0;
}