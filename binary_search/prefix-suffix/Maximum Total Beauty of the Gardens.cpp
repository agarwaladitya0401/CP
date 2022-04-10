// https://leetcode.com/contest/weekly-contest-288/problems/maximum-total-beauty-of-the-gardens/ 
// see solution at : https://leetcode.com/problems/maximum-total-beauty-of-the-gardens/discuss/1931085/Explanation-with-pictures-Greedy

class Solution {
public:
    long long maximumBeauty(vector<int>& fl, long long newfl, long long int tar, long long int full, long long int par) {
        
        sort(fl.begin(),fl.end());
        
        
        
        long long int n = fl.size();
        
        
        if(fl[0]>=tar){
            return full*n;
        }
        
        vector<long long int> par_req(n,0),ful_req(n,0);
        
        for(long long int i=1;i<n;i++){
            
            par_req[i] = (fl[i]-fl[i-1])*i + par_req[i-1];
        }
        
        for(long long int i=n-1;i>=0;i--){
            
            if(fl[i]>=tar)
                continue;
            
            ful_req[i] = (tar - fl[i]) + (i<n-1?ful_req[i+1]:0);
            
        }
        
        long long int ans = 0;
        
        for(long long int i=n;i>=0;i--){
            
            long long int t = 0;
            
            if(i<n){
                t = ful_req[i];
            }
            long long int rm = newfl - t;
            long long int par_max = 0;
            
            if(rm>0){
                
                auto idx = upper_bound(par_req.begin(),par_req.end(),rm);
                idx--;
                
                long long int par_idx = idx - par_req.begin();
        
                
                par_idx = min(par_idx, i-1);
                
                 if(par_idx<0){
                    ans = max(ans, (i>0?fl[0]*par:0) + (n-i)*full);
                     break;
                }
                
                
                par_max = fl[par_idx];
                
                
                par_max += (rm - par_req[par_idx])/(par_idx+1);
                
                par_max = min(par_max, tar-1);
                
                
                ans = max(ans, par_max*par + (n-i)*full);
            }
            else{
                break;
            }
        }
        
        return ans;
        
    }
};
