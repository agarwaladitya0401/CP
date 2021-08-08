// https://leetcode.com/problems/edit-distance/

// lcs variation, we see all possibilities and take min one.

class Solution {
    int dp[501][501];
public:
    
    int n,m;
    string w1,w2;
    
    int fun(int i, int j){
        
        // cout<<"i"<<i<<" j"<<j<<"\n";
        //  cout<<n<<" "<<m<<"\n";
        
        if(i==n) return abs(m-j);
        
        if(j==m) return abs(n-i);
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
                
        if(w1[i]==w2[j]){
            
            dp[i][j] = fun(i+1,j+1);
        }
        else{
            
            dp[i][j] = fun(i+1, j+1);
            dp[i][j] = min(dp[i][j], fun(i+1,j));
            dp[i][j] = min(dp[i][j], fun(i,j+1));
            
            dp[i][j]+=1;
        }
        
        // cout<<"i"<<i<<" j"<<j<<"\n";
        // cout<<"dp "<<dp[i][j]<<"\n";
        return dp[i][j];
        
    }
    
    int minDistance(string word1, string word2) {
        
        w1 = word1;
        w2 = word2;
        
        n = w1.size();
        m = w2.size();
        
        memset(dp,-1,sizeof(dp));
        cout<<n<<" "<<m<<"\n";
        
        return fun(0,0);
    }
};
