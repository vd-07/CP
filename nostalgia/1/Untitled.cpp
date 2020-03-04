#include <iostream>
using namespace std;

int main() {

	int i,j,t,n,m=1000000007;
	long int A[10000001];
	A[0]=1;
	for(i=1;i<=1000000;i++)
	{
	    A[i]=(i+1)*A[i-1];
	    if(A[i]>m)
	    A[i]%=m;
	}
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{   
		scanf("%d",&n);
		printf("%ld\\n",A[n]-1);
	}
	return 0;
}