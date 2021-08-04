#include<iostream>
#include<set>

using namespace std;

int main(){
	int t;
	long long int a,m,x,y,q,rem;
	cin>>t;
	while(t--){
		cin>>a>>m;
		set<long long int> hash,div;
		for(int i=1;i*i<m;i++){
			if(m%i)
				continue;
			x=m/i;
			y=i;
			div.insert(x);
			div.insert(y);
			
			// if((m/y-1)%a==0&&(m/y-1)>a)
			// 	hash.insert(((m/y-1)/a)*y);
		}
		//for(auto D : div){
		//	if((m/D-1)%a==0&&(m/D-1)>=a)
		//		hash.insert(((m/D-1)/a)*D);
		//}
		for (auto D : div   ) {
            long long q, rem = m / D;
            rem--;
            if (rem % a) continue;
            q = rem / a;
            hash.insert(q * D);
        }
		cout<<hash.size()<<"\n";
		for(auto ans : hash)
			cout<<ans<<" ";
		cout<<"\n";
	}	

	return 0;
}