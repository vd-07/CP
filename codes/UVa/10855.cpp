#include<iostream>

using namespace std;

int main(){
	int N,n;
	while( (cin>>N>>n) && (N!=0&&n!=0) ){
		char big[N+1][N+1],small[n+1][n+1],rotated[n+1][n+1];
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
				cin>>big[i][j];
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				cin>>small[i][j];
		}
		for(int k=0;k<4;k++){
			int count=0;
			for(int i=0;i<N;i++){
				for(int j=0;j<N;j++){
					int flag=0;
					if(big[i][j]==small[0][0])
					{	
						flag=1;
						for(int p=0;p<n;p++){
							for(int q=0;q<n;q++){
								if(big[p+i][q+j]!=small[p][q])
									flag=0;
							}
						}
					}
					if(flag)
					count++;
				}

			}
		cout<<count<<" ";
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				rotated[j][n-i-1]=small[i][j];
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				small[i][j]=rotated[i][j];
			}
		}
		}
		cout<<"\n";

	}
	return 0;
}