// https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/
//  we made two arrays left and right, and cal them in 2^(n/2) complexity where 0<=n<=30, by meet in the middle, 
// then did BS for getting sum/2 for 1st subset

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        
        int ts = 0;
        
        for(auto i:nums){
            ts+=i;
        }
        
        int ans = INT_MAX;
        
        int n = nums.size();
        
        vector<int>lf[n/2+1], rt[n/2+1];
        int cnt = 0;
        int tmp1 = 0;
        int tmp2 = 0;
        
        for(int i=0;i<(1<<(n/2));i++){
             
            int j = i;
            int p = 0;
            tmp1 = 0;
            tmp2 = 0;
            cnt = 0;

            while(j){
                
                if(j&1){
                    tmp1 += nums[p];
                    tmp2 += nums[p + n/2];
                    cnt++;
                }
                
                j>>=1;
                p++;
            }
            
            lf[cnt].push_back(tmp1);
            rt[cnt].push_back(tmp2);
            
        }
        
        int hn = n/2;
        ans = min(abs(ts-2*lf[hn][0]), abs(ts-2*rt[hn][0]));
        
        for(int i=0;i<=hn;i++){
            sort(rt[i].begin(),rt[i].end());
        }
        
        for(int i=1;i<hn;i++){
            
            int rsz = hn-i;
            
            for(auto lfs:lf[i]){
                int rs = (ts - 2*lfs)/2;
                
                auto b = lower_bound(rt[rsz].begin(),rt[rsz].end(),rs);
                
                if(b != rt[rsz].end()){
                    
                    int s1 = lfs + *b;
                        
                    ans = min(ans, abs(ts - 2*s1));
                }
            }
            
        }
        
        return ans;
    }
};












