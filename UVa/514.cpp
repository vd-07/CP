#include <iostream>
#include <stack>

using namespace std;

int main(){
	stack<int> station, B;
	int N,temp=1;
	while(cin>>N){
		while(temp){
			for(int i=N;i>0;i--)
				station.push(i);
			for(int i=0;i<N;i++){
				cin>>temp;
				if(station.top()==temp)
				{
					B.push(station.top());
					station.pop();
				}
				else if(station.top()<temp){
					while(station.top()!=temp){
						B.push(station.top());
						station.pop();
					}
				}
				else if(B.top()==temp)
				{
					B.pop();
				}
				else
				{
					cout<<"No\n";
					break;	
				}
				cout<<"Yes\n";	
			}
		}
		cout<<"\n";
	}
	return 0;
}