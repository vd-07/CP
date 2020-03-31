#include <iostream>
using namespace std;
int gcd(int a, int b) {
    if(b==0)
        return a;
    return gcd(b, a%b);
}
int main(){
    int n;
    cin>>n;
    int a[n], maxE=0;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        maxE=maxE<a[i]?a[i]:maxE;
    }
    int gcdAll=a[0];
    for(int i=1;i<n;i++) gcdAll=gcd(gcdAll,a[i]);
    int k;
    cin>>k;
    cout<<maxE-gcdAll*(k-1);
}