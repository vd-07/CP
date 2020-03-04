#include<iostream>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    fastIO
    int t,n,temp;
    cin>>t;
    while(t--){
        cin>>n;
        int count=0,ct=0;
        while(n--)
        {
            cin>>temp;
            if(temp==2)
                count++;
            if(temp==0)
                ct++;

        }
        long long int res=(count*(count-1))/2+(ct*(ct-1))/2;
        cout<<res<<"\n";
    }
    return 0;
}