#define stm clock_t cccc=clock();
#define ptm cout<<1.*(clock()-cccc)/CLOCKS_PER_SEC<<endl;

#include <algorithm>
#include <cassert>
#include <bitset>
#include <climits>
#include <cstring>
#include <deque>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <streambuf>
#include <string>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
#define f(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007

int main(){
	int t;
	ll x,y,n,m,k;
	cin>>t;
	while(t--){
		double distance=INT_MAX;
		cin>>x>>y;
		cin>>n>>m>>k;
		vector<pair<ll,ll> > a(n),b(m),c(k);
		f(i,0,n)
			cin>>a[i].first>>a[i].second;
		f(i,0,m)
			cin>>b[i].first>>b[i].second;
		f(i,0,k)
			cin>>c[i].first>>c[i].second;
		
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		sort(c.begin(),c.end());


		// f(i,0,n)
		// 	cout<<a[i].first<<" "<<a[i].second<<endl;
		// f(i,0,m)
		// 	cout<<b[i].first<<" "<<b[i].second<<endl;
		// f(i,0,k)
		// 	cout<<c[i].first<<" "<<c[i].second<<endl;


		ll temp1, t1=b[0].first,t2=b[0].second,temp,p1,p2;
		temp1=(b[0].first-a[0].first)*(b[0].first-a[0].first)+(b[0].second-a[0].second)*(b[0].second-a[0].second);
		f(i,0,n){
			temp=(b[0].first-a[i].first)*(b[0].first-a[i].first)+(b[0].second-a[i].second)*(b[0].second-a[i].second);
			f(j,0,m){
				if(temp>=(b[j].first-a[i].first)*(b[j].first-a[i].first)+(b[j].second-a[i].second)*(b[j].second-a[i].second))
				{
					temp=(b[j].first-a[i].first)*(b[j].first-a[i].first)+(b[j].second-a[i].second)*(b[j].second-a[i].second);
					p1=b[j].first;
					p2=b[j].second;
				}
				else
					break;
			}
			if(temp<temp1){
				temp1=temp;
				t1=p1;
				t2=p2;
			}
		}
		ll temp2,t3=a[0].first,t4=a[0].second;

		temp2=(b[0].first-a[0].first)*(b[0].first-a[0].first)+(b[0].second-a[0].second)*(b[0].second-a[0].second);
		f(i,0,m){
			temp=(b[i].first-a[0].first)*(b[i].first-a[0].first)+(b[i].second-a[0].second)*(b[i].second-a[0].second);
			f(j,1,n){
				if(temp>=(b[i].first-a[j].first)*(b[i].first-a[j].first)+(b[i].second-a[j].second)*(b[i].second-a[j].second))
				{
					temp=(b[i].first-a[j].first)*(b[i].first-a[j].first)+(b[i].second-a[j].second)*(b[i].second-a[j].second);
					p1=a[j].first;
					p2=a[j].second;
				}
				else
					break;
			}
			if(temp<temp2){
				temp2=temp;
				t3=p1;
				t4=p2;
			}
		}
		ll t5,t6;
		if(temp1<temp2)
			{
				distance=sqrt(temp1);
				t5=t1;
				t6=t2;
				cout<<t1<<" "<<t2<<" "<<distance<<endl;
			}
		else
			{
				distance=sqrt(temp2);
				t5=t3;
				t6=t4;
				cout<<t3<<" "<<t4<<" "<<distance<<endl;
			}
			temp1=(c[0].first-t1)*(c[0].first-t1)+(c[0].second-t1)*(c[0].second-t1);

		f(i,1,k){
			if(temp1>=(c[i].first-t1)*(c[i].first-t1)+(c[i].second-t1)*(c[i].second-t1))
				{
					temp1=(c[i].first-t5)*(c[i].first-t5)+(c[i].second-t6)*(c[i].second-t6);
					p1=c[i].first;
					p2=c[i].second;
				}
			else break;
		}

		distance+=sqrt(temp1);
		printf("%.12f\n",distance );
		

		
	}
	return 0;
}
