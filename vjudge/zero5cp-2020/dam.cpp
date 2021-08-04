#include<iostream>
using namespace std;

int converted(string s) {
    int ans = 0;
    for(int i = 0; i < s.size(); i++) 
        ans = ans * 2 + (s[i] - 'A');
    return ans;
}
int analyse(int num) {
    int ans = 0;
    while(num) {
        if((num % 10) % 3)
            ans++;
        num/=10;
    }
    return ans;
}
int32_t main() {
    string s;
    cin>>s;
    int n = converted(s);
    cout<<n<<"\n";
    int p = analyse(n);
    if(p == 1) {
        cout<<"YES";
    }
    else
    cout<<"NO";
    return 0;
}