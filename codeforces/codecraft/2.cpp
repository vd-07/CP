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
#define pb push_back

void solve(){
    string s;
    int n;
    cin>>n;
    cin>>s;
    int k=1;
    char comp=s[0];
    string temp=s, temp1=s;
    f(i,1,n){
        if(s[i]<comp)
            {
                comp=s[i];
                k = i+1;
                // temp=s;
                // for(int ij=0;ij+k<=n;ij++){
                //     reverse(temp.begin()+ij,temp.begin()+ij+k);
                // }
                string p1=s.substr(i,n-i+1), p2=s.substr(0,i);
                if((k&1)==(n&1))
                    reverse(p2.begin(),p2.end());
                temp=p1+p2;
            }
        else if(s[i]==comp){
            // int j=1;
            // while(k+j<n&&i+j>=0) {
            //     if(s[k+j-1]>s[i+j]) {
            //         k=i+1;
            //         break;
            //     }
            //     j++;
            // }
            // string temp1=s;
            // for(int ij=0;ij+i+1<=n;ij++){
            //     reverse(temp1.begin()+ij,temp1.begin()+ij+i+1);
            string p1=s.substr(i,n-i+1), p2=s.substr(0,i);
            if(((i+1)&1)==(n&1))    
                reverse(p2.begin(),p2.end());
            temp1=p1+p2;
            if(temp1<temp)
            {
                    k=i+1;
                    temp=temp1;
            }
        }
    }

        // cout<<k<<" ";
    cout<<temp<<"\n";
    cout<<k<<"\n";
}
int main(){
    fastIO
    test solve();
    return 0;
}