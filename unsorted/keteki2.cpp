#include <iostream>
using namespace std;



int main(){

	int n;
        cin>>n;
        int dp[26]={};
        dp[1]=1;
        dp[2]=1;
        dp[3]=1;
        for(int i=4;i<=n;i++)
        {
            for(int j=1;j<=i/2;j++)
            {
                dp[i]+=dp[j]*dp[i-j];
            }
        }
        cout<<dp[n]<<endl;

	return 0;

}