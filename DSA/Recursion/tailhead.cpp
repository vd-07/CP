#include<bits/stdc++.h>

void fun(int n)
{
    if(n>0)
    {
        printf("%d",n);
        fun(n-1);
    }
}

int main()
{
     #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    int x=3;
    fun(x);
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}