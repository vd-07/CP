int Solution::solve(string A, string B) {
    //to check for presence of letters of A in B
    int ispresent[26];
    for(int i= 0; i < 26; i++)
    ispresent[i] = 0;
    //counting the letters in A
    for(int i = 0; i < A.size(); i++) 
    ispresent[A[i] - 'a']++;
    //count = No of letters of A still to be found in B
    //hasbeenfound = letters of A and their count that has been found in B
    //basically the count variable facilitates us to not iterate over hasbeenfound everytime
    //ans = final answer
    int count = A.size(), hasbeenfound[26], ans = 0;
    for(int i = 0; i < 26; i++)
    hasbeenfound[i] = 0;
    //for first N letters
    for(int i = 0; i < A.size(); i++) {
        //if this letter is still present in A
        if(ispresent[B[i] - 'a'] - hasbeenfound[B[i] - 'a'] > 0) {
            count--;
            hasbeenfound[B[i] - 'a']++;
        }
        else {
            //as we had to find a substring, so continuity matters
            if(ispresent[B[i] - 'a'] && B[i] == B[i - A.size() + count]) {
                //hasbeenfound[i]
            }
            else {
                count = A.size();
                for(int i = 0; i < 26; i++)
                hasbeenfound[i] = 0


            ;
            
            }
        }
        //cout<<count<<" ";
    }
    //if found all the letters
    if(count == 0) {
    ans++;
    }
    //printf("%d %d\n", count, ans);
    for(int i = A.size(); i < B.size(); i++) {
        //rolling over the leftover portion of B
        if(count == 0 && ispresent[B[i - A.size()] - 'a']) {
        hasbeenfound[B[i - A.size()] - 'a']--;
        count++;
        }
        if(ispresent[B[i] - 'a'] - hasbeenfound[B[i] - 'a'] > 0) {
            count--;
            hasbeenfound[B[i] - 'a']++;
        }
        else {
            if(ispresent[B[i] - 'a'] && B[i] == B[i - A.size() + count]) {
                //hasbeenfound[B[i] - 'a']++;
            }
            else {
                count = A.size();
                for(int  i = 0; i < 26; i++)
                hasbeenfound[i] = 0;
            }
            if(ispresent[B[i] - 'a'] && B[i] != B[i - A.size() + count]) {
                count = A.size() - 1;
                hasbeenfound [B[i] - 'a']++;
            }
                
        }
        cout<<count<<" ";
        if(count == 0) {
            ans++;
            //cout<<i<<" ";
        }
    }
    //printf("\n");
    //printf("%d %d\n", count, ans);
    return ans;
}
