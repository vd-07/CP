#include <iostream>

using namespace std;

int main(){
	int t, n, k1, k2;
	cin>>t;
	while(t--){
		cin>>n>>k1>>k2;
		int t1[k1],t2[k2];
		for(int i=0;i<k1;i++)
			cin>>t1[i];
		for(int i=0;i<k2;i++)
			cin>>t2[i];
		sort(t1,t1+k1);
		sort(t2,t2+k2);
		if(t1[k1-1]>=t2[k2-1])
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}