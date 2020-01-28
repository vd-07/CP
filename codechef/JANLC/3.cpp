#include<iostream>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef long long int ll;
int main(){
	fastIO
	ll t,n,m,back,front;
	unsigned long long ct;
	cin>>t;
	while(t--){
		cin>>n>>m;
		ll matrix[n][m][3];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>matrix[i][j][0];
			}
		}
	//manacher's algo
		for(int p=0;p<n;p++){
			for (int i = 0, l = 0, r = -1; i < m; i++) {
	    		int k = (i > r) ? 1 : (min(matrix[p][l + r - i][0], r - i + 1));
	    		while (0 <= i - k && i + k < m && matrix[p][i - k][0] == matrix[p][i + k][0]) {
	        		k++;
	    		}
	    		matrix[p][i][1] = k--;
	    		if (i + k > r) {
	        		l = i - k;
	        		r = i + k;
	    		}
			}
		}
		
		for(int p=0;p<m;p++){
			for (int i = 0, l = 0, r = -1; i < n; i++) {
	    		int k = (i > r) ? 1 : (min(matrix[l + r - i][p][0], r - i + 1));
	    		while (0 <= i - k && i + k < n && matrix[i - k][p][0] == matrix[i + k][p][0]) {
	        		k++;
	    		}
	    		matrix[i][p][2] = k--;
	    		if (i + k > r) {
	        		l = i - k;
	        		r = i + k;
	    		}
			}
		}
		// for(int i=0;i<n;i++){
		// 	for(int j=0;j<m;j++){
		// 		ct=1,back=j-1,front=j+1;				
		// 		while(back>=0&&front<m&&matrix[i][back][0]==matrix[i][front][0]){
		// 			ct+=2;
		// 			back--;
		// 			front++;
		// 		}
		// 		matrix[i][j][1]=ct;
		// 	}
		// 	// cout<<endl;
		// }

		// for(int i=0;i<m;i++){
		// 	for(int j=0;j<n;j++){
		// 		ct=1,back=j-1,front=j+1;
		// 		while(back>=0&&front<n&&matrix[back][i][0]==matrix[front][i][0]){
		// 			ct+=2;
		// 			back--;
		// 			front++;
		// 		}
		// 		matrix[j][i][2]=ct;
		// 	}
		// }
		ct=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				ct+=(min(matrix[i][j][1],matrix[i][j][2])+1)/2;
				// cout<<matrix[i][j][1]<<" "<<matrix[i][j][2]<<"    ";
			}
			// cout<<endl;
		}
		cout<<ct<<"\n";
	}
	return 0;
}