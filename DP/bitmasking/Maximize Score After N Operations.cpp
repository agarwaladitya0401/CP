// https://leetcode.com/problems/maximize-score-after-n-operations/
//  when constrains are very small and we need all possible combination then think of bitmasking.

class Solution {
public:
    
    int dp[16385][8];
    
    int fun(int mask, int op, int n, vector<int>&nums){
        
        if(op>n){
            return 0;
        }
        
        if(dp[mask][op]!=-1){
            return dp[mask][op];
        }
        
        for(int i=0;i<2*n;i++){
            if((mask & (1<<i)) != 0)
                continue;
            
            for(int j=i+1;j<2*n;j++){
                if((mask & (1<<j))!=0)
                    continue;
                
                int currMask = mask | (1<<i) | (1<<j);
                dp[mask][op] = max(dp[mask][op], __gcd(nums[i],nums[j])*op + fun(currMask, op+1,n, nums));
            }
        }
        
        return dp[mask][op];
        
    }
    
    int maxScore(vector<int>& nums) {
        
        memset(dp,-1,sizeof(dp));
        
        int n = nums.size()/2;
        return fun(0,1,n,nums);
        
    }
};
