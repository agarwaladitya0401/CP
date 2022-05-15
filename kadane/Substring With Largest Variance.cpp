// https://leetcode.com/problems/substring-with-largest-variance/

// The solution boils down to finding the solution if only 2 elements were present in array, as given in example "aababbb", if we can do that in O(n), 
// we can iterate over all 26 alphabet characters as the 2 elements and find the solution in O(26 * 26 * n) (around 10^7 operations, 
// so should pass test cases) and find the maximum considering those 2 characters, note that other elements would not interfere as at each iteration,
// variance is found considering only 2 elements.
// Finding maximum variance considering only 2 elements can be done using Kadanes algorithm. In this case, when i was 'b' and j was 'a', 
// then (let) maxV value is increased only if there are more b's than a's, else maxV is 0, so maxV is 0,0,1,0,1,2,3 
// after all the iterations over string length, and max of these elements is answer when iterated over all i's and j's.

class Solution {
public:
    int largestVariance(string s) {
        map<char,int>mp;
        
        for(auto it:s){
            mp[it]++;
        }
        
        int ans = 0;
        
        for(char i='a';i<='z';i++){
            
            for(char j='a';j<='z';j++){

                int freqB = mp[j];
                int currA = 0;
                int currB = 0;
                
                if(i==j || mp[i]==0 || mp[j]==0) continue;
                
                for(auto it:s){
                    if(it==i){
                        currA++;
                    }
                    else if(it==j){
                        currB++;
                        freqB--;
                    }
                    
                    if(currB>0)
                    ans = max(ans,currA-currB);
                    
                    if(currA-currB<0 and freqB>=1){
                        currA = 0;
                        currB = 0;
                    }
                }
            }    
        }
        return ans;
    }
};
