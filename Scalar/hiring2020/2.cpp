vector<int> Solution::solve(string A, vector<vector<int> > &B) {
    vector<int> prev1(A.size()), next1(A.size()), count0(A.size());
    count0[0] = (A[0] == '0' ? 1 : 0);
    prev1[0] = (A[0] == '1' ? 0 : -1);
    for(int i = 1; i < A.size(); i++) {
        
        //building prev
        if(A[i] == '1')
            prev1[i] = i;
        else
            prev1[i] = prev1[i - 1];
        
        //zero count
        count0[i] = count0[i - 1];
        if(A[i] == '0')
            count0[i]++;
    }
    
    next1[(int)A.size() - 1] = (A.back() == '1' ? (int)A.size() - 1 : -1);
    for(int i = (int)A.size() - 2; i >= 0; i--) {
        
        if(A[i] == '1') {
            next1[i] = i;
        }
        else {
            next1[i] = next1[i + 1];
        }
        
    }
    
    vector<int> ans;
    for(int i = 0; i < A.size(); i++) {
        cout << next1[i] << " " << prev1[i] << endl;
    }
    for(auto e:B) {
        int l = next1[e[0] - 1], r = prev1[e[1] - 1];
        cout << l << " " << r << "\n";
        if(l == -1 || r == -1)
            ans.push_back(0);
        else {
            ans.push_back(count0[r] - count0[l]);
        }
    }
    return ans;
}
