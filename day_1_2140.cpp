class Solution {
public:
    long long dp[100001];
    long long solve(vector<vector<int>>&q,int idx){
        if(idx>=q.size())return 0;
        if(dp[idx]!=-1)return dp[idx];
        long long c1=0,c2=0;
        c1 = q[idx][0]+solve(q,idx+q[idx][1]+1);
        c2 = solve(q,idx+1);
        return dp[idx]=max(c1,c2);

    }
    long long mostPoints(vector<vector<int>>& q) {
        memset(dp,-1,sizeof(dp));
        return solve(q,0);
    }
};