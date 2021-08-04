#include <iostream>
#include <cstring>
using namespace std;

int *pr, *cnt, *ans;
int main() {
  int n;
  cin >> n;
  //memory allocation
  pr = new int[n + 1];
  cnt = new int[n + 1];
  ans = new int[n + 1];
  //setting up 
  for(int i = 1; i <= n; i++) {
  	pr[i] = 0;
  	cnt[i] = 0;
  }
  //marking the multiples
  pr[1] = 1;
  for(int i = 2; i <= n; i++) {
  	if(!pr[i]) {
  		for(int k = i; k <= n; k += i)
  			if(pr[k] == 0) pr[k] = k / i;
  	}
  }
  
  //counting up values
  for(int i = 1; i <= n; i++) {
  	cnt[pr[i]]++;
  }

  int x = 0;
  for(int i = 1; i <=n; i++) {
  	while(cnt[i]--)
  		if(x == n) 	break; 
  		else	ans[++x] = i;
  }
	for(int i = 2; i <= n; i++) cout << ans[i] << " ";	
	
  delete []pr;
  delete []cnt;
  delete []ans;
  return 0;
}