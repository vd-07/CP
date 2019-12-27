#include <iostream>

using namespace std;
typedef long long int ll;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
	fastIO
	int t;
	string a,b;
	cin>>t;
	while(t--){
		cin>>a;
		cin>>b;
		int carry=0;
		reverse(a.begin(),a.end());
		reverse(b.begin(),b.end());
		int n=a.size(),m=b.size();
		if(n<m)
		swap(n,m);
		int boss[n]={},ct=0,maxct=0;
		for(int i=0;i<n;i++){
			if(i<a.size())
				boss[i]+=a[i]-'0';
			if(i<b.size())
				boss[i]+=b[i]-'0';
			boss[i]+=carry;
			if(boss[i]==2)
				carry=1;
			else
				carry=0;
			if(boss[i]==2)
			{
				ct++;
			}
			else
			{
				maxct=maxct>ct?maxct:ct;
				ct=0;
			}
		}
		cout<<maxct<<"\n";
	}
	return 0;
}