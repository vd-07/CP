class Solution {
    int n, m;
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        using v = pair<int, vector<int>>;
        m = mat.size(), n = mat[0].size();
        vector<int> pos(m,0);
        int sum = 0;
        for(int i = 0; i < m; i++)
            sum += mat[i][0];
        
        priority_queue<v, vector<v>, greater<> > q;
        
        set<vector<int>> visited;
        visited.insert(pos);
        
        q.push({sum, pos});
        
        int count = 0;
        while(count < k) {
            vector<int> curr = q.top().second;
            sum = q.top().first;
            q.pop();
            int s1;
            for(int i = 0; i < m; i++) {
                s1 = sum;
                if(curr[i] == n - 1) continue;
                curr[i]++;
                s1 += mat[i][curr[i]] - mat[i][curr[i] - 1];
                if(visited.find(curr) == visited.end()) {
                    q.push({s1, curr});
                    visited.insert(curr);
                }
                curr[i]--;
            }
            cout << sum << "\n";
            count++;
        }
        return sum;
    }
};